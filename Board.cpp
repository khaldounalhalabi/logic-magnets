//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include <iostream>
#include "Board.h"
#include "array"
#include "Message.h"

using namespace std;

Board::Board() {
    this->rows = 1;
    this->cols = 1;
    this->moves = 0;
    this->allowedMoves = 2;
}

Board::Board(int rows, int cols, int allowedMoves) {
    this->rows = rows;
    this->cols = cols;
    this->allowedMoves = allowedMoves;
    this->moves = 0;
    this->board = new Stone *[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new Stone[this->cols];
    }

    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->board[i][j] = Stone(EMPTY, true, {i - 1, j - 1});
        }
    }
}

void Board::destroy() const {
    for (int i = 0; i < this->rows; i++) {
        delete[] board[i];
    }
    delete[] board;
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

Stone * Board::moveRepel(Stone &stone) {
    int col, row;

    do {
        cout << "Enter the desired cell row target \n";
        cin >> row;
        cout << "Enter the desired cell column target \n";
        cin >> col;

        if (!this->checkValidMove(row, col)) {
            cout << "invalid move from the check valid function" << endl;
        }

    } while (!this->checkValidMove(row, col));

    Stone *currentCell = &this->board[stone.position.row][stone.position.col];
    Stone *targetCell = &this->board[row][col];

    // if the target cell is empty and the current cell contain only the current stone
    if (targetCell->type == EMPTY && currentCell->type == REPEL) {
        currentCell->empty(stone.position);
        targetCell->repel({row, col});
    }

        // if the target cell is empty and the current is "repel in the goal"
    else if (targetCell->type == EMPTY && currentCell->type == REPELANDGOAL) {
        currentCell->goal(stone.position);
        targetCell->repel({row, col});
    }

        // if the target cell is goal and the current is "repel"
    else if (targetCell->type == GOAL && currentCell->type == REPEL) {
        currentCell->empty(stone.position);
        targetCell->repelAndGoal({row, col});
    }

        // if the current cell is "repel and goal and the target cell is goal"
    else if (currentCell->type == REPELANDGOAL && targetCell->type == GOAL) {
        currentCell->goal(stone.position);
        targetCell->repelAndGoal({row, col});

    } else {
        this->allowedMoves += 1;
        Message::message("Invalid Move");
    }

    this->handleReflection(row, col);
    this->printBoard();
    if (this->checkWin()) {
        cout << "<<<------- You Win ------->>>" << endl;
        return currentCell;
    }

    return targetCell;
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

