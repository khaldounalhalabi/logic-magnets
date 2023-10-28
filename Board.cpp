//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include "Board.h"
#include <iostream>
#include "array"

using namespace std;

Board::Board(int rows, int cols, int allowedMoves) {
    this->rows = rows;
    this->cols = cols;
    this->allowedMoves = allowedMoves;
    this->moves = 0;
    this->board = new string *[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new string[this->cols];
    }

    // Initialize the array (for example, with sequential values)
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->board[i][j] = " ";
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
            cout << "| " << this->board[i][j] << " ";
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

void Board::destroy() const {
    for (int i = 0; i < this->rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}

Board::Board() {
    this->rows = 1;
    this->cols = 1;
    this->moves = 0;
    this->allowedMoves = 2;
}
