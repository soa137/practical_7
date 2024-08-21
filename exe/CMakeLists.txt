cmake_minimum_required(VERSION 3.16)
project(
    matrixlib-exe
    VERSION 1.0
    DESCRIPTION "matrixlib_exe"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)

add_executable(matrixlib-exe
    src/main.cpp
)
target_include_directories(matrixlib-exe  PUBLIC 
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

target_link_libraries(matrixlib-exe PRIVATE "${CMAKE_SOURCE_DIR}/libs/matrixlib/shared-matrixlib.so")