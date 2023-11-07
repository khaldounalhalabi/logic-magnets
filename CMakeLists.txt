cmake_minimum_required(VERSION 3.22)
project(smart_algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(smart_algorithms main.cpp
        Board.h
        Board.cpp
        Stone.h
        Stone.cpp
        Stone.cpp
        StoneTypeEnum.h
        LevelsContainer.txt RepelActions.cpp Message.h AttractActions.cpp Algorithm.cpp Algorithm.h AlgorithmActions.cpp)
