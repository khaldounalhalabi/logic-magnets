//
// Created by Khaldoun Alhalabi on 11/5/2023.
//

#include "Algorithm.h"

#include "Board.h"
#include <queue>

struct Node {
    Board board;
    vector<Node> children;
    int depth{};

    explicit Node(Board level) : board(level) {}

    void addChild(const Node &childNode) {
        children.push_back(childNode);
    }
};

Node *createNode(Board level) {
    Node *newNode = new Node(level);
    return newNode;
}

void Algorithm::bfs(Board board) {
    queue<Board> states;
    for (int i = 0; i < board.allowedMoves; i++) {

        for (int row = 0; row < board.rows; row++) {
            for (int col = 0; col < board.cols; col++) {

                for (Stone movable: board.movables) {
                    if (movable.type == REPELANDGOAL || movable.type == REPEL) {
                        auto result = board.moveRepel(movable, row, col);

                        if (result != nullptr) {

                        }
                    }
                }

            }
        }

    }
}