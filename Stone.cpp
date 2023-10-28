//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include "iostream"
#include "Stone.h"
#include "StoneTypeEnum.h"
#include "string"
#include "algorithm"

using namespace std;

Stone::Stone(StoneType type, bool canMove, Position position, Board &board) {
    this->type = type;
    this->naming(type);
    this->canMove = canMove;
    this->position = {position.cols - 1, position.rows - 1};
    this->board = board;
    this->board.board[this->position.rows][this->position.cols] = this->name;
}

void Stone::move(Position newPosition) {
    if (this->canMove) {
        this->board.board[this->position.rows][this->position.cols] = '\0';

        this->position.rows = newPosition.rows - 1;
        this->position.cols = newPosition.cols - 1;

        this->board.board[this->position.rows][this->position.cols] = this->name;
        this->board.printBoard();

    } else return;
}

void Stone::requestMove() {
    int col, row;
    cout << "Enter the desired cell column \n";
    cin >> col;

    cout << "Enter the desired cell row \n";
    cin >> row;

    this->move({col, row});
}

void Stone::naming(StoneType stoneType) {
    if (stoneType == REPEL) {
        this->name = "R";
    } else if (stoneType == ATTRACT) {
        this->name = "A";
    } else if (stoneType == STONE) {
        this->name = "S";
    } else if (stoneType == GOAL) {
        this->name = "G";
    } else if (stoneType == OBSTACLE) {
        this->name = "O";
    }
}

string removeWhitespace(const string &str) {
    string result = str;
    result.erase(remove_if(result.begin(), result.end(), ::isspace), result.end());
    return result;
}

