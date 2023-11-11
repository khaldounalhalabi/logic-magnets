//
// Created by Khaldoun Alhalabi on 11/4/2023.
//

#include <queue>
#include "Board.h"
#include "../Message/Message.h"

Stone *Board::moveAttract(Stone &stone) {
    int col, row;

    do {
        Message::message("Enter the desired cell row target :");
        cin >> row;
        Message::message("Enter the desired cell column target :");
        cin >> col;

        if (!this->checkValidMove(row, col)) {
            Message::message("invalid Move");
        }

    } while (!this->checkValidMove(row, col));

    Stone *currentCell = &this->board[stone.position.row][stone.position.col];
    Stone *targetCell = &this->board[row][col];

    // if the target cell is empty and the current cell contain only the "attract" stone
    if (targetCell->type == EMPTY && currentCell->type == ATTRACT) {
        currentCell->empty(stone.position);
        targetCell->attract({row, col});
    }

        // if the target cell is empty and the current is "repel in the goal"
    else if (targetCell->type == EMPTY && currentCell->type == ATTRACTANDGOAL) {
        currentCell->goal(stone.position);
        targetCell->attract({row, col});
    }

        // if the target cell is goal and the current is "repel"
    else if (targetCell->type == GOAL && currentCell->type == ATTRACT) {
        currentCell->empty(stone.position);
        targetCell->attractAndGoal({row, col});
    }

        // if the current cell is "repel and goal and the target cell is goal"
    else if (currentCell->type == ATTRACTANDGOAL && targetCell->type == GOAL) {
        currentCell->goal(stone.position);
        targetCell->attractAndGoal({row, col});

    } else {
        this->allowedMoves += 1;
        Message::message("Invalid Move");
    }

    this->handleAttractReflection(row, col);
    this->printBoard();
    if (this->checkWin()) {
        cout << "<<<------- You Win ------->>>" << endl;
        return currentCell;
    }

    return targetCell;
}

void Board::handleAttractReflection(int currentRow, int currentCol) const {
    this->handleAttractReflectionRight(currentRow, currentCol);
    this->handleAttractReflectionLeft(currentRow, currentCol);
    this->handleAttractReflectionUp(currentRow, currentCol);
    this->handleAttractReflectionDown(currentRow, currentCol);
}

void Board::handleAttractReflectionRight(int row, int column) const {
    queue<Stone> rightSide;
    for (int col = column; col < this->cols; col++) {
        if (col + 1 >= this->cols) {
            break;
        }
        Stone *nextStone = &this->board[row][col + 1];
        Board::pushAcceptableStones(rightSide, nextStone);
    }

    while (!rightSide.empty() && rightSide.front().type != OBSTACLE) {
        Stone stone = rightSide.front();
        rightSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow;
        int newCol = oldCol - 1;
        if (newCol >= this->cols) {
            break;
        }
        this->movementReplacing(oldRow, oldCol, newRow, newCol);
    }
}

void Board::handleAttractReflectionLeft(int row, int column) const {
    queue<Stone> leftSide;
    for (int col = column; col >= 0; col--) {
        if (col - 1 < 0) {
            break;
        }
        Stone *nextStone = &this->board[row][col - 1];
        Board::pushAcceptableStones(leftSide, nextStone);
    }

    while (!leftSide.empty() && leftSide.front().type != OBSTACLE) {
        Stone stone = leftSide.front();
        leftSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow;
        int newCol = oldCol + 1;
        if (newCol < this->cols) {
            this->movementReplacing(oldRow, oldCol, newRow, newCol);
        } else {
            break;
        }
    }
}

void Board::handleAttractReflectionUp(int row, int column) const {
    queue<Stone> upSide;
    for (int r = row; r >= 0; r--) {
        if (r - 1 < 0) {
            break;
        }
        Stone *nextStone = &this->board[r - 1][column];
        Board::pushAcceptableStones(upSide, nextStone);
    }

    while (!upSide.empty() && upSide.front().type != OBSTACLE) {
        Stone stone = upSide.front();
        upSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow + 1;
        int newCol = oldCol;
        if (newRow < this->rows) {
            this->movementReplacing(oldRow, oldCol, newRow, newCol);
        } else {
            break;
        }
    }
}

void Board::handleAttractReflectionDown(int row, int column) const {
    queue<Stone> downSide;
    for (int r = row; r < this->rows; r++) {
        cout << "this->rows is :" << this->rows << endl;
        cout << "r is : " << endl;
        cout << "r + 1 : " << r + 1 << endl;
        if (r + 1 >= this->rows) {
            break;
        }
        Stone *nextStone = &this->board[r + 1][column];
        Board::pushAcceptableStones(downSide, nextStone);
    }

    while (!downSide.empty() && downSide.front().type != OBSTACLE) {
        Stone stone = downSide.front();
        downSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow - 1;
        int newCol = oldCol;
        if (newRow >= 0) {
            this->movementReplacing(oldRow, oldCol, newRow, newCol);
        } else {
            break;
        }
    }
}

void Board::pushAcceptableStones(queue<Stone> &queue, const Stone *nextStone) {
    if (nextStone->type == STONE || nextStone->type == STONEANDGOAL || nextStone->type == REPEL ||
        nextStone->type == REPELANDGOAL || nextStone->type == ATTRACT || nextStone->type == ATTRACTANDGOAL) {
        queue.push(*nextStone);
    }
}
