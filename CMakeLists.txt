cmake_minimum_required(VERSION 3.22)
project(smart_algorithms)

set(CMAKE_CXX_STANDARD 23)

add_executable(smart_algorithms main.cpp
        Board/Board.h
        Board/Board.cpp
        Stone/Stone.h
        Stone/Stone.cpp
        Stone/Stone.cpp
        Stone/StoneTypeEnum.h
        Board/RepelActions.cpp Message/Message.h Board/AttractActions.cpp Algorithm/Algorithm.cpp Algorithm/Algorithm.h Algorithm/AlgorithmActions.cpp LevelInitializer/LevelInitializer.cpp LevelInitializer/LevelInitializer.h LevelInitializer/LevelSetup.cpp)
