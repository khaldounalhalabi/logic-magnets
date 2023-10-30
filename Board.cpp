//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include "Board.h"
#include <iostream>
#include "array"
#include <stack>

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

    // Initialize the array (for example, with sequential values)
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->board[i][j] = Stone(EMPTY, true, {i, j});
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

void Board::moveRepel(Stone &stone) const {

    int col, row;

    do {
        cout << "Enter the desired cell row target \n";
        cin >> row;
        cout << "Enter the desired cell column target \n";
        cin >> col;
    } while (!this->checkValidMove(row, col));

    Stone *currentCell = &this->board[stone.position.row][stone.position.col];
    Stone *targetCell = &this->board[row][col];

    if (targetCell->type == EMPTY &&
        currentCell->type == REPEL) { // if the target cell is empty and the current cell contain only the current stone
        *currentCell = Stone().empty(stone.position);
        *targetCell = stone;
        stone.position = {row, col};
    } else if (targetCell->type == GOAL &&
               currentCell->type == REPEL) { // if the target cell is goal and the current is "repel"
        *currentCell = Stone().empty(stone.position);
        *targetCell = Stone().RepelAndGoal({row, col});
    }

    this->printBoard();
}

void Board::reflectRepelMove(Stone &repel) const {

}

void Board::checkReflectionRight(int currentRow, int currentCol) const {
    for (int row = currentRow; row < this->rows; row++) {

    }
}

bool Board::checkValidMove(int row, int col) const {
    StoneType targetType = this->board[row][col].type;
    if (targetType == STONE || targetType == OBSTACLE || targetType == STONEANDGOAL || targetType == REPELANDGOAL ||
        targetType == ATTRACTANDGOAL || row > this->rows - 1 || col > this->cols - 1) {
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
            else return true;
        }
    }
}

void Board::handleRepelReflectionRight(int row, int column) const {
    stack<Stone> rightSide;
    for (int col = column; col < this->cols; col++) {

        if (col + 1 >= this->cols) {
            rightSide.push(Stone(OBSTACLE, false, {row, col + 1}));
            break;
        }

        Stone *nexStone = &this->board[row][col + 1];
        if (nexStone->type == STONE || nexStone->type == STONEANDGOAL || nexStone->type == REPEL ||
            nexStone->type == REPELANDGOAL || nexStone->type == ATTRACT || nexStone->type == ATTRACTANDGOAL) {
            rightSide.push(*nexStone);
        } else {
            break;
        }
    }

    while (!rightSide.empty() and rightSide.top().type != OBSTACLE) {
        Stone stone = rightSide.top();
        rightSide.pop();
        auto [oldRow, oldCole] = stone.position;
        int newRow = oldRow;
        int newCol = oldCole + 1;

        if (this->board[newRow][newCol].type == EMPTY){

        }

    }
}
