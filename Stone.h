//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_STONE_H
#define SMART_ALGORITHMS_STONE_H

#include "Board.h"
#include "StoneTypeEnum.h"

struct Position {
    int cols;
    int rows;
};

class Stone {
public:
    string name;
    bool canMove;
    Position position{};
    StoneType type;
    Board board;

    Stone(StoneType type, bool canMove, Position position, Board &board);

    void naming(StoneType stoneType);

    void move(Position newPosition);

    void requestMove();
};


#endif //SMART_ALGORITHMS_STONE_H
