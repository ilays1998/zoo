#cmake_minimum_required(VERSION 3.16)
#
#project(helloworld VERSION 1.0.0 LANGUAGES CXX)
#
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
#
#
#find_package(Qt6 COMPONENTS Core Quick Widgets Network REQUIRED)
#add_executable(helloworld
#        src/SimpleZooModel.cpp
#        src/SimpleZooModel.hpp
#        src/Animal.cpp
#        src/Animal.hpp
#        src/zooMain.cpp
#        src/Metadata.cpp
#        src/Metadata.hpp
#)
#
#target_link_libraries(helloworld Qt6::Core Qt6::Quick Qt6::Widgets Qt6::Network)


cmake_minimum_required(VERSION 3.25.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(countries VERSION 0.1.0
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt6 REQUIRED COMPONENTS Core Quick)
qt_standard_project_setup()
add_subdirectory(qtgql)
add_subdirectory(src/grapgql/__generated__)

add_executable(${PROJECT_NAME}
        src/SimpleZooModel.cpp
        src/SimpleZooModel.hpp
        src/Animal.cpp
        src/Animal.hpp
        src/zooMain.cpp
        src/Metadata.cpp
        src/Metadata.hpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE qtgql
        Qt6::Core Qt6::Quick
        Countries
)
