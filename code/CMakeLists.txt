cmake_minimum_required(VERSION 3.14)
project(code)

set(CMAKE_CXX_STANDARD 14)

include_directories(inc)

add_executable(code
        inc/cotton-runtime.h
        inc/cotton.h
        inc/wrapperinterface.h
        src/cotton-runtime.cpp
        src/nqueens.cpp
        src/wrapper.cpp)
