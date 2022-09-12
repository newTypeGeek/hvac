cmake_minimum_required(VERSION 3.0)

project(
    hvac
    VERSION 0.1
    LANGUAGES CXX
)

set (CMAKE_CXX_EXTENSIONS 11)

add_executable(
    hvac.out
    src/chiller/gordon_ng.h
    src/chiller/gordon_ng.cpp
    src/constants.h
    src/main.cpp
)
target_include_directories(
    hvac.out
    PRIVATE
    src
)