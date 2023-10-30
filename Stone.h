//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_STONE_H
#define SMART_ALGORITHMS_STONE_H

#include "StoneTypeEnum.h"
#include "iostream"

using namespace std;

struct Position {
    int row;
    int col;
};

class Stone {
public:
    string name;
    bool canMove;
    Position position{};
    StoneType type;

    Stone();

    Stone(StoneType type, bool canMove, Position position);

    void naming(StoneType stoneType);

    Stone repel(Position currentPosition);

    Stone attact(Position currentPosition);

    Stone empty(Position currentPosition);

    Stone stone(Position currentPosition);

    Stone obstacle(Position currentPosition);

    Stone goal(Position position);

    void requestMove();

    Stone RepelAndGoal(Position currentPosition);
};


#endif //SMART_ALGORITHMS_STONE_H
