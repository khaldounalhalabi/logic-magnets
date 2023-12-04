#pragma clang diagnostic push
#pragma ide diagnostic ignored "misc-no-recursion"
//
// Created by Khaldoun Alhalabi on 11/5/2023.
//

#include "Algorithm.h"
#include "../Message/Message.h"
#include <queue>
#include <cmath>

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
                            resultBoard.printBoard();

                            visitedCounter++;
                            if (resultBoard.checkWin()) {
                                win = true;
                                while (!states.empty()) states.pop();
                                Message::message("The Win State");
                                resultBoard.printBoard();
                                cout << "The Solution Depth Is : " << resultBoard.allowedMoves << endl;
                                cout << "The Count Of Visited Nodes Is : " << visitedCounter << endl;
                                askForSolutionPath(resultBoard);
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

void Algorithm::ucs(const Board &board) {
    Board root = Board(board);
    priority_queue<Board> states;
    states.push(root);
    int visitedCounter = 0;

    while (!states.empty()) {

        Board current = Board(states.top());
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
                            resultBoard.printBoard();
                            if (movable.type == REPEL or movable.type == REPELANDGOAL) {
                                resultBoard.cost = current.cost + 1;
                            } else if (movable.type == ATTRACTANDGOAL || movable.type == ATTRACT) {
                                resultBoard.cost = current.cost + 2;
                            }

                            visitedCounter++;
                            if (resultBoard.checkWin()) {
                                win = true;
                                while (!states.empty()) states.pop();
                                Message::message("The Win State");
                                resultBoard.printBoard();
                                cout << "The Solution Depth Is : " << resultBoard.allowedMoves << endl;
                                cout << "The Count Of Visited Nodes Is : " << visitedCounter << endl;
                                cout << "The Solution Cost Is : " << resultBoard.cost << endl;
                                Algorithm::askForSolutionPath(resultBoard);
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

void Algorithm::hillClimbing(Node *&node) {
    if (node->board.checkWin() && !node->visited) {
        return;
    } else {
        if (node->visited) {
            if (node->parent != nullptr) {
                node = node->parent;
                Algorithm::getMinimumHeurCost(node);
                Algorithm::hillClimbing(node);
            }
        } else if (!node->visited && node->depth != 0) {
            Algorithm::getNextStates(node);
            node->visited = true;
            Algorithm::getMinimumHeurCost(node);
            Algorithm::hillClimbing(node);
        } else if (node->depth == 0) {
            node->visited = true;
            this->visitedNodes++;
            Algorithm::hillClimbing(node);
        }
    }
}

void Algorithm::getNextStates(Node *&node) {
    if (!node->visited) {
        for (int row = 0; row < node->board.rows; row++) {
            for (int col = 0; col < node->board.cols; col++) {
                Board currentBoard = node->board;
                currentBoard.initMovables();
                while (!currentBoard.movables.empty()) {
                    Stone movable = currentBoard.movables.top();
                    currentBoard.movables.pop();

                    if (currentBoard.checkValidMove(row, col)) {
                        Board resultBoard = Board(move(currentBoard, movable, row, col));
                        if (resultBoard.dirty) {
                            Node *childNode = nullptr;
                            childNode = Node::createNode(resultBoard);
                            childNode->parent = node;
                            Algorithm::calcHeuristicCost(childNode);
                            node->addChild(childNode);
                        }
                    }
                }
            }
        }
    }
}

void Algorithm::calcHeuristicCost(Node *&node) {
    Board currentNodeBoard = node->board;
    currentNodeBoard.initStones();

    int sum = 0;
    int temp1;
    int temp2;

    while (!currentNodeBoard.stones.empty()) {
        Stone currentStone = currentNodeBoard.stones.top();
        currentNodeBoard.stones.pop();
        temp2 = 100;

        while (!currentNodeBoard.goals.empty()) {
            Stone currentGoal = currentNodeBoard.goals.top();
            currentNodeBoard.goals.pop();

            temp1 = abs(
                    (currentStone.position.row - currentGoal.position.row)
                    +
                    (currentStone.position.col - currentGoal.position.col)
            );

            temp2 = min(temp1, temp2);
        }

        sum += temp2;
    }

    node->heuristicCost = sum;
}

void Algorithm::getMinimumHeurCost(Node *&node) {
    Node *temp = nullptr;

    for (auto &child: node->children) {
        if (child->visited) continue;
        else {
            temp = child;
            break;
        }
    }

    for (auto &child: node->children) {
        if (child->visited) continue;

        if (temp->heuristicCost > child->heuristicCost) temp = child;
    }

    if (temp == nullptr) {
        return;
    } else {
        node = temp;
        return;
    }
}


void Algorithm::showPath(const Board &child) {
    child.printBoard();
    if (child.father == nullptr) {
        return;
    }
    return showPath(*child.father);
}

void Algorithm::askForSolutionPath(const Board &board) {
    Message::message("If You Want To Show The Solution Path  Press (1) Else Press (0)");
    int choice = 0;
    cin >> choice;
    if (choice == 1) {
        Message::message("Solution Path Is : ");
        Algorithm::showPath(board);
    } else return;
}

Algorithm::Algorithm() { this->visitedNodes = 0; }

#pragma clang diagnostic pop