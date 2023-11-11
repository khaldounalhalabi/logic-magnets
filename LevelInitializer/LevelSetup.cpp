//
// Created by Khaldoun Alhalabi on 11/11/2023.
//

#include "LevelInitializer.h"

LevelInitializer LevelInitializer::level1() {
    this->board = Board(3, 4, 2);
    this->board.board[2][0].repel({2, 0});
    this->board.board[1][2].stone({1, 2});
    this->board.board[1][1].goal({1, 1});
    this->board.board[1][3].goal({1, 3});
    this->board.initMovables();
    return *this;
}

LevelInitializer LevelInitializer::level2() {
    this->board = Board(5, 5, 5);
    this->board.board[4][0].repel({4, 0});
    this->board.board[0][2].goal({0, 2});
    this->board.board[2][0].goal({2, 0});
    this->board.board[2][2].goal({2, 2});
    this->board.board[2][4].goal({2, 4});
    this->board.board[4][2].goal({4, 2});
    this->board.board[1][2].stone({1, 2});
    this->board.board[2][1].stone({2, 1});
    this->board.board[2][3].stone({2, 3});
    this->board.board[3][2].stone({3, 2});

    return *this;
}

LevelInitializer LevelInitializer::level3() {
    this->board = Board(3, 4, 5);
    this->board.board[2][0].repel({2, 0});
    this->board.board[1][2].stone({1, 2});
    this->board.board[0][3].goal({0, 3});
    this->board.board[2][3].goal({2, 3});
    this->board.board[0][0].obstacle({0, 0});
    this->board.board[0][1].obstacle({0, 1});
    this->board.board[0][2].obstacle({0, 2});

    return *this;
}

LevelInitializer LevelInitializer::level4() {
    this->board = Board(5, 3, 5);
    this->board.board[2][0].repel({2, 0});
    this->board.board[1][1].stone({1, 1});
    this->board.board[3][1].stone({3, 1});
    this->board.board[0][0].goal({0, 0});
    this->board.board[0][2].goal({0, 2});
    this->board.board[4][1].goal({4, 1});
    this->board.board[1][0].obstacle({1, 0});
    this->board.board[3][0].obstacle({3, 0});

    return *this;
}

LevelInitializer LevelInitializer::level5() {
    this->board = Board(4, 3, 2);
    this->board.board[3][1].repel({3, 1});
    this->board.board[1][0].stoneAndGoal({1, 0});
    this->board.board[1][2].stoneAndGoal({1, 2});
    this->board.board[2][0].stone({2, 0});
    this->board.board[2][2].stone({2, 2});
    this->board.board[0][0].goal({0, 0});
    this->board.board[0][2].goal({0, 2});
    this->board.board[3][0].goal({3, 0});
    for (int i = 0; i < 3; i++) {
        this->board.board[i][1].obstacle({i, 1});
    }

    return *this;
}

LevelInitializer LevelInitializer::level6() {
    this->board = Board(3, 5, 2);
    this->board.board[2][0].repel({2, 0});
    this->board.board[1][1].stone({1, 1});
    this->board.board[1][3].stone({1, 3});
    this->board.board[0][3].goal({0, 3});
    this->board.board[1][2].goal({1, 2});
    this->board.board[2][3].goal({2, 3});

    return *this;
}

LevelInitializer LevelInitializer::level7() {
    this->board = Board(5, 4, 2);
    this->board.board[2][1].repel({2, 1});
    this->board.board[0][0].goal({0, 0});
    this->board.board[2][3].goal({2, 3});
    this->board.board[4][3].goal({4, 3});
    this->board.board[1][0].stoneAndGoal({1, 0});
    this->board.board[3][2].stoneAndGoal({3, 2});
    this->board.board[2][0].stone({2, 0});
    this->board.board[3][1].stone({3, 1});
    for (int i = 0; i < 3; i++) {
        this->board.board[4][i].obstacle({4, i});
    }

    return *this;
}

LevelInitializer LevelInitializer::level8() {
    this->board = Board(3, 4, 2);
    this->board.board[2][0].repel({2, 0});
    this->board.board[0][0].goal({0, 0});
    this->board.board[0][2].goal({0, 2});
    this->board.board[2][2].goal({2, 2});
    this->board.board[1][1].stone({1, 1});
    this->board.board[1][2].stone({1, 2});

    return *this;
}

LevelInitializer LevelInitializer::level9() {
    this->board = Board(1, 7, 2);
    this->board.board[0][0].repel({0, 0});
    this->board.board[0][1].goal({0, 1});
    this->board.board[0][6].goal({0, 6});
    this->board.board[0][3].stoneAndGoal({0, 3});
    this->board.board[0][5].stone({0, 5});

    return *this;
}

LevelInitializer LevelInitializer::level10() {
    this->board = Board(4, 4, 2);
    this->board.board[0][0].repel({0, 0});
    this->board.board[1][1].goal({1, 1});
    this->board.board[1][3].goal({1, 3});
    this->board.board[3][0].goal({3, 0});
    this->board.board[3][3].goal({3, 3});
    this->board.board[2][2].stone({2, 2});
    this->board.board[2][3].stone({2, 3});
    this->board.board[3][1].stone({3, 1});

    return *this;
}

LevelInitializer LevelInitializer::level11() {
    this->board = Board(2, 5, 1);
    this->board.board[1][2].attract({1, 2});
    this->board.board[0][1].goal({0, 1});
    this->board.board[0][2].goal({0, 2});
    this->board.board[0][3].goal({0, 3});
    this->board.board[0][0].stone({0, 0});
    this->board.board[0][4].stone({0, 4});
    this->board.board[1][0].obstacle({1, 0});
    this->board.board[1][1].obstacle({1, 1});
    this->board.board[1][3].obstacle({1, 3});
    this->board.board[1][4].obstacle({1, 4});

    return *this;
}

LevelInitializer LevelInitializer::level12() {
    this->board = Board(5, 4, 1);
    this->board.board[3][1].attract({3, 1});
    board.board[0][0].stone({0, 0});
    board.board[4][3].stone({4, 3});
    board.board[1][0].stoneAndGoal({1, 0});
    board.board[2][0].goal({2, 0});
    board.board[4][0].goal({4, 0});
    board.board[4][2].goal({4, 2});

    return *this;
}

LevelInitializer LevelInitializer::level21() {
    this->board = Board(3, 4, 2);
    this->board.board[2][3].attract({2, 3});
    this->board.board[0][1].stone({0, 1});
    this->board.board[1][2].stone({1, 2});
    this->board.board[1][1].stoneAndGoal({1, 1});
    this->board.board[0][2].goal({0, 2});
    this->board.board[1][0].goal({1, 0});
    this->board.board[2][1].goal({2, 1});
    this->board.board[2][0].repelAndGoal({2, 0});

    return *this;
}

LevelInitializer LevelInitializer::level27() {
    this->board = Board(4, 6, 3);
    this->board.board[2][3].attract({2, 3});
    this->board.board[3][3].attract({3, 3});
    this->board.board[0][4].stone({0, 4});
    this->board.board[2][1].stone({2, 1});
    this->board.board[2][4].stoneAndGoal({2, 4});
    this->board.board[3][4].stone({3, 4});
    this->board.board[3][1].repel({3, 1});
    this->board.board[0][1].goal({0, 1});
    this->board.board[0][2].goal({0, 2});
    this->board.board[0][2].goal({0, 2});
    this->board.board[0][3].goal({0, 3});
    this->board.board[0][5].goal({0, 5});
    this->board.board[1][1].goal({1, 1});
    this->board.board[1][4].goal({1, 4});

    return *this;
}
