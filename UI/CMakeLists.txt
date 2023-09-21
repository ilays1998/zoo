cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(Qt6 COMPONENTS Core Quick Widgets Network REQUIRED)
qt_standard_project_setup()
add_executable(helloworld
        src/SimpleZooModel.cpp
        src/SimpleZooModel.hpp
        src/Animal.cpp
        src/Animal.hpp
        src/zooMain.cpp
        src/Metadata.cpp
        src/Metadata.hpp
        src/WebPicture.cpp
        src/WebPicture.hpp
)

target_link_libraries(helloworld Qt6::Core Qt6::Quick Qt6::Widgets Qt6::Network)