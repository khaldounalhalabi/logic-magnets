//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include "iostream"
#include "Stone.h"
#include "StoneTypeEnum.h"
#include "string"
#include "algorithm"

using namespace std;

Stone::Stone(StoneType type, bool canMove, Position position) {
    this->type = type;
    this->naming(type);
    this->canMove = canMove;
    this->position = position;
}

void Stone::naming(StoneType stoneType) {
    if (stoneType == REPEL) {
        this->name = " R ";
    } else if (stoneType == ATTRACT) {
        this->name = " A ";
    } else if (stoneType == STONE) {
        this->name = " S ";
    } else if (stoneType == GOAL) {
        this->name = " G ";
    } else if (stoneType == OBSTACLE) {
        this->name = " O ";
    } else if (stoneType == EMPTY) {
        this->name = "   ";
    }
}

Stone::Stone() {
    this->type = EMPTY;
    this->name = "   ";
    this->position = {0, 0};
    this->canMove = true;
}

Stone Stone::repel(Position currentPosition) {
    this->name = " R ";
    this->type = REPEL;
    this->canMove = true;
    this->position = currentPosition;
    return *this;
}

Stone Stone::attract(Position currentPosition) {
    this->name = " A ";
    this->type = ATTRACT;
    this->canMove = true;
    this->position = currentPosition;
    return *this;
}

Stone Stone::empty(Position currentPosition) {
    this->name = "   ";
    this->type = EMPTY;
    this->canMove = true;
    this->position = currentPosition;
    return *this;
}

Stone Stone::stone(Position currentPosition) {
    this->name = " S ";
    this->type = STONE;
    this->canMove = true;
    this->position = currentPosition;
    return *this;
}

Stone Stone::stoneAndGoal(Position currentPosition) {
    this->name = "S+G";
    this->type = STONEANDGOAL;
    this->canMove = true;
    this->position = currentPosition;
    return *this;
}

Stone Stone::obstacle(Position currentPosition) {
    this->name = " O ";
    this->type = OBSTACLE;
    this->canMove = false;
    this->position = currentPosition;
    return *this;
}

Stone Stone::goal(Position currentPosition) {
    this->name = " G ";
    this->type = GOAL;
    this->canMove = false;
    this->position = currentPosition;
    return *this;
}

Stone Stone::repelAndGoal(Position currentPosition) {
    this->name = "G+R";
    this->type = REPELANDGOAL;
    this->canMove = true;
    this->position = currentPosition;
    return *this;
}

string removeWhitespace(const string &str) {
    string result = str;
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}

