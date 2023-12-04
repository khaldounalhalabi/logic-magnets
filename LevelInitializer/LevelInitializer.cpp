//
// Created by Khaldoun Alhalabi on 11/11/2023.
//

#include "LevelInitializer.h"
#include "../Message/Message.h"
#include <iostream>
#include "../Algorithm/Algorithm.h"
#include <chrono>
#include <functional>


using namespace std;


void showNodePath(const Node *child) {
    child->board.printBoard();
    if (child->parent == nullptr) {
        return;
    }
    return showNodePath(child->parent);
}

LevelInitializer::LevelInitializer() {
    this->board = Board();
}

void LevelInitializer::play() {
    for (int i = 0; i < this->board.allowedMoves; i++) {
        bool validMovable = true;

        do {
            int movableRow, movableCol;
            Message::message("Select Movable row:");
            cin >> movableRow;
            Message::message("Select Movable Column :");
            cin >> movableCol;

            Stone selectedMovable = this->board.board[movableRow][movableCol];

            if (selectedMovable.type == REPEL || selectedMovable.type == REPELANDGOAL) {
                this->board.moveRepel(selectedMovable);
            } else if (selectedMovable.type == ATTRACT || selectedMovable.type == ATTRACTANDGOAL) {
                this->board.moveAttract(selectedMovable);
            } else {
                Message::message("Error : Select A Valid Movable Stone");
                validMovable = false;
            }

            if (this->board.checkWin()) {
                Message::message("You Win");
                return;
            }

        } while (!validMovable);
    }
}

void LevelInitializer::handler() {
    Message::message("Select A Level Number : From (1) To (12)");
    int levelNumber = 1;
    cin >> levelNumber;

    switch (levelNumber) {
        case 1: {
            this->level1().handleChoices();
            return;
        }
        case 2: {
            this->level2().handleChoices();
            return;
        }
        case 3: {
            this->level3().handleChoices();
            return;
        }
        case 4: {
            this->level4().handleChoices();
            return;
        }
        case 5: {
            this->level5().handleChoices();
            return;
        }
        case 6: {
            this->level6().handleChoices();
            return;
        }
        case 7 : {
            this->level7().handleChoices();
            return;
        }
        case 8 : {
            this->level8().handleChoices();
            return;
        }
        case 9 : {
            this->level9().handleChoices();
            return;
        }
        case 10: {
            this->level10().handleChoices();
            return;
        }
        case 11 : {
            this->level11().handleChoices();
            return;
        }
        case 12 : {
            this->level12().handleChoices();
            return;
        }
        case 21 : {
            this->level21().handleChoices();
            return;
        }
        case 27 : {
            this->level27().handleChoices();
            return;
        }

        default: {
            level1().handleChoices();
            return;
        }
    }
}

void LevelInitializer::handleChoices() {
    bool validSelection = true;
    int choice = 0;

    do {
        this->board.printBoard();
        Message::message("If You Want To Play Press (1)");
        Message::message("If You Want To Solve It With BFS Algorithm Press (2)");
        Message::message("If You Want To Solve It WIth UCS Algorithm Press (3)");
        Message::message("If You Want To Solve It WIth Hill Climbing Algorithm Press (4)");

        cin >> choice;

        if (choice == 1) {
            this->play();
            return;
        } else if (choice == 2) {
            LevelInitializer::applyAlgorithm(this->board, Algorithm::bfs);
            return;
        } else if (choice == 3) {
            LevelInitializer::applyAlgorithm(this->board, Algorithm::ucs);
            return;
        } else if (choice == 4) {
            Node *root = nullptr;
            root = Node::createNode(this->board);
            root->depth = board.allowedMoves;
            root->board.printBoard();

            auto start_time = chrono::high_resolution_clock::now();

            Algorithm algorithm;
            algorithm.hillClimbing(root);
            auto end_time = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
            showNodePath(root);

            cout << "-------------------------------------------------------------\n";
            cout << "Execution Time In Micro Seconds Ss : " << duration.count() << " Micro Second" << endl;
            cout << "-------------------------------------------------------------\n";

            cout << "-------------------------------------------------------------\n";
            cout << "Visited Nodes Count is : " << algorithm.visitedNodes << endl;
            cout << "-------------------------------------------------------------\n";

            return;
        } else {
            Message::message("Invalid Selection Try Again");
            validSelection = false;
        }
    } while (!validSelection);
}

/**
 *
 * @param desiredBoard the board you want to apply the algorithm on it
 * @param algorithm the selected algorithm execution function
 */
void LevelInitializer::applyAlgorithm(const Board &desiredBoard, const function<void(Board)> &algorithm) {
    auto start_time = chrono::high_resolution_clock::now();
    algorithm(desiredBoard);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "-------------------------------------------------------------\n";
    cout << "Execution Time In Micro Seconds Ss : " << duration.count() << " Micro Second" << endl;
    cout << "-------------------------------------------------------------\n";
}
