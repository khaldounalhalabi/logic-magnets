//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include <iostream>
#include "Board.h"
#include "Message.h"

using namespace std;

Board::Board() {
    this->rows = 1;
    this->cols = 1;
    this->moves = 0;
    this->allowedMoves = 2;
    this->movables = {};
    this->board = {{}};
}

Board::Board(int rows, int cols, int allowedMoves) {
    this->rows = rows;
    this->cols = cols;
    this->allowedMoves = allowedMoves;
    this->moves = 0;
    this->movables = {};

    for (int row = 0; row < this->rows; row++) {
        for (int col = 0; col < this->cols; col++) {
            this->board[row][col] = Stone(EMPTY, true, {row - 1, col - 1});
        }
    }
}

void Board::initMovables() {
    for (int row = 0; row < this->rows; row++) {
        for (int col = 0; col < this->cols; col++) {
            Stone current = this->board[row][col];
            if (current.type == REPELANDGOAL || current.type == REPEL || current.type == ATTRACTANDGOAL ||
                current.type == ATTRACT) {
                this->movables.push(current);
            }
        }
    }
}

void Board::printBoard() const {
    for (int i = 0; i < this->rows; i++) {
        // Print horizontal line
        for (int j = 0; j < this->cols; j++) {
            cout << "+---";
        }
        cout << "+" << endl;

        // Print array values and vertical lines
        for (int j = 0; j < this->cols; j++) {
            cout << "|" << this->board[i][j].name << "";
        }
        cout << "|" << endl;
    }

    // Print the final horizontal line
    for (int j = 0; j < this->cols; j++) {
        cout << "+---";
    }
    cout << "+" << endl;
    cout << "----------------------!!!!!---------------------- \n";
}

bool Board::checkValidMove(int row, int col) const {
    if (row > this->rows - 1 || col > this->cols - 1) {
        cout << "<<<-----------Invalid Move----------->>>" << endl;
        return false;
    }

    StoneType targetType = this->board[row][col].type;

    if (targetType == STONE || targetType == OBSTACLE || targetType == STONEANDGOAL || targetType == REPELANDGOAL ||
        targetType == ATTRACTANDGOAL) {
        cout << "<<<-----------Invalid Move----------->>>" << endl;
        return false;
    } else return true;
}

bool Board::checkWin() const {
    for (int row = 0; row < this->rows; row++) {
        for (int col = 0; col < this->cols; col++) {
            StoneType currentCellType = this->board[row][col].type;
            if (currentCellType == REPEL || currentCellType == STONE ||
                currentCellType == ATTRACT || currentCellType == GOAL)
                return false;
        }
    }
    return true;
}

