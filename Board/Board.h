//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_BOARD_H
#define SMART_ALGORITHMS_BOARD_H

#include <stack>
#include <queue>
#include "string"
#include "iostream"
#include "../Stone/Stone.h"
#include "vector"

using namespace std;

class Board {

public:
    int rows, cols, allowedMoves{}, moves{};
    bool dirty = false;
    Stone **board{};
    stack<Stone> movables;
    stack<Stone> goals;
    stack<Stone> stones;
    Board *father = nullptr;
    int cost = 0;

    Board();

    Board(int rows, int cols, int allowedMoves);

    Board(const Board &other) {
        this->rows = other.rows;
        this->cols = other.cols;
        this->allowedMoves = other.allowedMoves;
        this->moves = other.moves;
        this->dirty = other.dirty;
        this->cost = other.cost;

        this->board = new Stone *[this->rows];
        for (int i = 0; i < this->rows; i++) {
            this->board[i] = new Stone[this->cols];
            for (int j = 0; j < this->cols; j++) {
                this->board[i][j] = other.board[i][j];
            }
        }

        this->movables = other.movables;
    }

    bool operator<(const Board &other) const {
        return this->cost > other.cost;
    }

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

    void initGoals();

    void initStones();
};

#endif //SMART_ALGORITHMS_BOARD_H
