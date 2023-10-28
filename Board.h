//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_BOARD_H
#define SMART_ALGORITHMS_BOARD_H

#include "string"
#include "iostream"

using namespace std;

class Board {
public:
    int rows, cols, allowedMoves{}, moves{};
    string **board{};

    Board();

    Board(int rows, int cols, int allowedMoves);

    void destroy() const;

    void printBoard() const;
};

#endif //SMART_ALGORITHMS_BOARD_H
