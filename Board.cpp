//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#include "Board.h"
#include <iostream>

using namespace std;

Board::Board(int rows, int cols) {
    this->rows = rows;
    this->cols = cols;
    this->board = new char *[this->rows];

    for (int i = 0; i < this->rows; i++) {
        this->board[i] = new char[this->cols];
    }

    // Initialize the array (for example, with sequential values)
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; j++) {
            this->board[i][j] = '*';
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
}

void Board::destroy() const {
    for (int i = 0; i < this->rows; i++) {
        delete[] board[i];
    }
    delete[] board;
}
