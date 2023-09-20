from __future__ import annotations

import contextlib
import glob
import logging
import os
import subprocess
import sys
from functools import cached_property
from pathlib import Path
from typing import ClassVar, Literal

from conan import ConanFile
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout


class PATHS:
    PROJECT_ROOT: ClassVar[Path] = Path(__file__).parent
    QTGQL_TEST_TARGET: ClassVar[Path] = PROJECT_ROOT / "tests" / "build"


ConanBool = [True, False]


logger = logging.getLogger(__name__)
__version__: str = "0.130.8"
class EnvManager:
    def __init__(self, env_var: str = "PATH") -> None:
        self._env_avr = env_var
        self._paths: list[Path] = []

    def _add_to_environ(self, p: Path) -> None:
        path_delimiter = ":" if sys.platform == "linux" else ";"
        paths = os.environ.get(self._env_avr, "").split(path_delimiter)
        paths.append(p.resolve(True).as_uri())
        os.environ.setdefault(self._env_avr, path_delimiter.join(paths))

    def add(self, p: Path) -> None:
        self._paths.append(p)

    def commit(self) -> None:
        for p in self._paths:
            self._add_to_environ(p)
class Qt6Installer:
    def __init__(self, os_name: Literal["windows"] | Literal["linux"], version: str):
        self.os_name = os_name
        self.is_windows = os_name == "windows"
        self.is_linux = os_name == "linux"
        self.version = version
        self.env_manager = EnvManager()

    @property
    def arch(self) -> str:
        if self.is_linux:
            return "gcc_64"
        elif self.is_windows:
            return "win64_mingw"

    @cached_property
    def aqt_install_dir(self) -> Path:
        ret = Path.home() / "MyConnandeps" / "Qt"

        if not ret.exists():
            ret.mkdir(parents=True)
        return ret

    @property
    def qt_root_dir(self) -> Path:
        arch = "mingw_64" if self.is_windows else "gcc_64"
        return self.aqt_install_dir / self.version / arch

    @property
    def qt6_cmake_config(self) -> Path:
        assert self.qt_root_dir.exists()
        return next(self.qt_root_dir.glob("**/Qt6Config.cmake")).parent

    @property
    def dll_path(self) -> Path:
        return self.qt_root_dir / "bin"

    def installed(self) -> bool:
        return self.qt_root_dir.exists()

    def set_env_vars(self) -> None:
        self.env_manager.add(self.dll_path.resolve(True))
        self.env_manager.commit()
        os.environ.setdefault(
            "QT_PLUGIN_PATH",
            (self.qt_root_dir / "plugins").resolve(True).as_uri(),
        )
        if self.is_linux:
            os.environ.setdefault(
                "LD_LIBRARY_PATH",
                (self.qt_root_dir / "lib").resolve(True).as_uri(),
            )

    def install(self) -> None:
        if not self.installed():
            subprocess.run(
                f"poetry run aqt install-qt {self.os_name} "
                f"desktop {self.version} {self.arch} "
                f"--outputdir {self.aqt_install_dir} "
                f"-m qtwebsockets".split(" "),
            ).check_returncode()
            assert self.qt6_cmake_config.exists()
        self.set_env_vars()
class QtGqlRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    name = "qtgql"
    license = "MIT"
    author = "Nir Benlulu nrbnlulu@gmail.com"
    url = "https://github.com/qtgql/qtgql"
    description = "GraphQL codegen client library for Qt"
    topics = ("GraphQL", "Qt", "codegen")
    version = __version__
    build_policy = "missing"
    options = {"qt_version": ["6.5.2"], "verbose": ConanBool, "test": ConanBool}  # noqa
    default_options = {  # noqa
        "verbose": False,
        "qt_version": "6.5.2",
        "test": False,
    }

    exports_sources = "CMakeLists.txt", "src/*", "pyproject.toml"

    def requirements(self) -> None:
        ...

    def layout(self) -> None:
        cmake_layout(self)

    @property
    def os_name(self):
        return self.settings.os.value.lower()

    def is_windows(self) -> bool:
        return self.os_name == "windows"

    def is_linux(self) -> bool:
        return self.os_name == "linux"

    @cached_property
    def qt_version(self) -> str:
        qt_version = self.options.qt_version.value
        if self.is_windows() and "6.5" in qt_version:
            logger.warning(
                "Can't compile with aqt installer on Windows just yet fall back to 6.5.0",
            )
            return "6.5.0"
        return qt_version

    @property
    def qt_arch(self) -> str:
        if self.is_linux():
            return "gcc_64"
        elif self.is_windows():
            return "win64_mingw"

    @cached_property
    def aqt_install_dir(self) -> Path:
        ret = Path.home() / "MyConnandeps" / "Qt"

        if not ret.exists():
            ret.mkdir(parents=True)
        return ret

    @property
    def qt6_install_dir(self) -> Path | None:
        relative_to = self.aqt_install_dir / self.qt_version
        if relative_to.exists():
            prev = Path.cwd()
            os.chdir(relative_to)
            res = glob.glob("**/Qt6Config.cmake", recursive=True)
            os.chdir(prev)
            with contextlib.suppress(IndexError):
                p = (relative_to / res[0]).resolve(True)
                return p.parent

    def generate(self) -> None:

        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.variables[
            "binaryDir"
        ] = PATHS.QTGQL_TEST_TARGET.as_posix()  # cmake works with posix paths only
        qt6_installer = Qt6Installer("linux", self.qt_version)
        qt6_installer.install()

        tc.cache_variables["Qt6_DIR"] = str(qt6_installer.qt6_cmake_config)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()