cmake_minimum_required(VERSION 3.26)
project(smart_algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(smart_algorithms main.cpp
        Board.h
        Board.cpp)
