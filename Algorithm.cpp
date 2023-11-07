//
// Created by Khaldoun Alhalabi on 11/5/2023.
//

#include "Algorithm.h"
#include "Message.h"
#include "Board.h"
#include <queue>

using namespace std;

void Algorithm::bfs(Board board) {
    Board root = board;
    queue<Board> states;
    states.push(root);

    while (!states.empty()) {

        Board current = states.front();
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

                if (current.allowedMoves == 1) {
                    cout << "===========================current level is  :  1===========================" << endl;
                    break;
                };

                while (!current.movables.empty()) {
                    Stone movable = current.movables.top();
                    current.movables.pop();

                    if (current.checkValidMove(row, col)) {
                        Board resultBoard = move(current, movable, row, col);

                        if (resultBoard.dirty) {
                            resultBoard.printBoard();

                            if (resultBoard.checkWin()) {
                                win = true;
                                Message::message("The Win State");
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