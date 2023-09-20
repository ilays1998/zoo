cmake_minimum_required(VERSION 3.16)

project(helloworld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(Qt6 COMPONENTS Core Quick REQUIRED)
qt_standard_project_setup()
add_executable(helloworld
        src/SimpleZooModel.cpp
        src/SimpleZooModel.h
        src/Animal.cpp
        src/Animal.h
        src/zooMain.cpp
)

target_link_libraries(helloworld Qt6::Core Qt6::Quick)