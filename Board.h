//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_BOARD_H
#define SMART_ALGORITHMS_BOARD_H

#include <stack>
#include <queue>
#include "string"
#include "iostream"
#include "Stone.h"
#include "vector"

using namespace std;

class Board {

public:
    int rows, cols, allowedMoves{}, moves{};
    Stone **board{};
    vector<Stone> movables;

    Board();

    Board(int rows, int cols, int allowedMoves);

    void destroy() const;

    void printBoard() const;

    Stone *moveRepel(Stone &stone);

    void handleRepelReflection(int currentRow, int currentCol) const;

    void handleAttractReflection(int currentRow, int currentCol) const;

    [[nodiscard]] bool checkValidMove(int row, int col) const;

    [[nodiscard]] bool checkWin() const;

    void handleRepelReflectionRight(int row, int column) const;

    void handleRepelReflectionLeft(int row, int column) const;

    void movementReplacing(int oldRow, int oldCol, int newRow, int newCol) const;

    void handleRepelReflectionUp(int row, int column) const;

    void handleRepelReflectionDown(int row, int column) const;

    void handleAttractReflectionRight(int row, int col) const;

    void handleAttractReflectionLeft(int row, int column) const;

    void handleAttractReflectionUp(int row, int column) const;

    void handleAttractReflectionDown(int row, int column) const;

    static void pushAcceptableStones(std::queue<Stone> &queue, const Stone *nextStone);

    Stone *moveAttract(Stone &stone);

    void initMovables();

    Board * moveRepel(Stone &stone, int row, int col);

    Board * moveAttract(Stone &stone, int row, int col);
};

#endif //SMART_ALGORITHMS_BOARD_H
