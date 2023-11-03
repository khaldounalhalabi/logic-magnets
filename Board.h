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

    Stone * moveRepel(Stone &stone);

    void handleReflection(int currentRow, int currentCol) const;

    [[nodiscard]] bool checkValidMove(int row, int col) const;

    [[nodiscard]] bool checkWin() const;

    void handleRepelReflectionRight(int row, int column) const;

    void handleRepelReflectionLeft(int row, int column) const;

    void movementReplacing(int oldRow, int oldCol, int newRow, int newCol) const;

    void handleRepelReflectionUp(int row, int column) const;

    void handleRepelReflectionDown(int row, int column) const;
};

#endif //SMART_ALGORITHMS_BOARD_H
