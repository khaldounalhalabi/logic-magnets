//
// Created by Khaldoun Alhalabi on 11/11/2023.
//

#ifndef SMART_ALGORITHMS_LEVELINITIALIZER_H
#define SMART_ALGORITHMS_LEVELINITIALIZER_H

#include <functional>
#include "../Board/Board.h"

class LevelInitializer {
public:
    Board board;

    LevelInitializer();

    LevelInitializer level1();

    void play();

    void handleChoices();

    void handler();

    LevelInitializer level2();

    static void applyAlgorithm(const Board &desiredBoard, const std::function<void(Board)>& algorithm);

    LevelInitializer level3();

    LevelInitializer level4();

    LevelInitializer level5();

    LevelInitializer level6();

    LevelInitializer level7();

    LevelInitializer level8();

    LevelInitializer level9();

    LevelInitializer level10();

    LevelInitializer level11();

    LevelInitializer level12();

    LevelInitializer level21();

    LevelInitializer level27();
};


#endif //SMART_ALGORITHMS_LEVELINITIALIZER_H
