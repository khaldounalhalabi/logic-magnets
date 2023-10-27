//
// Created by Khaldoun Alhalabi on 10/27/2023.
//

#ifndef SMART_ALGORITHMS_BOARD_H
#define SMART_ALGORITHMS_BOARD_H


class Board {
public:
    int rows, cols;
    char **board;

    Board(int rows, int cols);

    void destroy() const;

    void printBoard() const;
};

#endif //SMART_ALGORITHMS_BOARD_H
