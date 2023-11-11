#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by Khaldoun Alhalabi on 11/5/2023.
//

#include "Algorithm.h"
#include "../Message/Message.h"
#include <queue>

using namespace std;

void Algorithm::bfs(const Board &board) {
    Board root = Board(board);
    queue<Board> states;
    states.push(root);
    int visitedCounter = 0;

    while (!states.empty()) {

        Board current = Board(states.front());
        states.pop();
        current.initMovables();
        bool win = false;
        bool outOfMoves = false;

        for (int row = 0; row < current.rows; row++) {

            if (win) break;
            if (outOfMoves)break;

            for (int col = 0; col < current.cols; col++) {

                if (win) break;
                if (outOfMoves)break;

                current.initMovables();

                while (!current.movables.empty()) {
                    Stone movable = current.movables.top();
                    current.movables.pop();

                    if (current.checkValidMove(row, col)) {
                        Board resultBoard = Board(move(current, movable, row, col));
                        resultBoard.father = &current;

                        if (resultBoard.dirty) {
//                            resultBoard.printBoard();

                            visitedCounter++;
                            if (resultBoard.checkWin()) {
                                win = true;
                                while (!states.empty()) states.pop();
                                Message::message("The Win State");
                                resultBoard.printBoard();
                                cout << "The Solution Depth Is : " << resultBoard.allowedMoves << endl;
                                cout << "The Count Of Visited Nodes Is : " << visitedCounter << endl;
//                                Message::message("Solution Path Is : ");
//                                Algorithm::showPath(resultBoard);

                                break;
                            }

                            if (resultBoard.allowedMoves <= 0) {
                                outOfMoves = true;
                                break;
                            }

                            resultBoard.allowedMoves--;
                            states.push(resultBoard);
                        }
                    }

                }

            }
        }
    }
}

void Algorithm::showPath(const Board &child) {
    child.printBoard();
    if (child.father == nullptr) {
        return;
    }
    return showPath(*child.father);
}

#pragma clang diagnostic pop