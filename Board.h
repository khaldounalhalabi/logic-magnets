//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_BOARD_H
#define SMART_ALGORITHMS_BOARD_H

#include "string"
#include "iostream"
#include "Stone.h"

using namespace std;

class Board {
public:
    int rows, cols, allowedMoves{}, moves{};
    Stone **board{};

    Board();

    Board(int rows, int cols, int allowedMoves);

    void destroy() const;

    void printBoard() const;

    void moveRepel(Stone& stone) const;

    void reflectRepelMove(Stone &repel) const;

    void checkReflectionRight(int currentRow, int currentCol) const;

    bool checkValidMove(int row, int col) const;

    bool checkWin() const;

    void handleRepelReflectionRight(int row, int column) const;
};

#endif //SMART_ALGORITHMS_BOARD_H
