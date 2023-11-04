//
// Created by Khaldoun Alhalabi on 11/3/2023.
//
#include <stack>
#include "Board.h"

void Board::handleRepelReflection(int currentRow, int currentCol) const {
    this->handleRepelReflectionRight(currentRow, currentCol);
    this->handleRepelReflectionLeft(currentRow, currentCol);
    this->handleRepelReflectionDown(currentRow, currentCol);
    this->handleRepelReflectionUp(currentRow, currentCol);
}

void Board::handleRepelReflectionRight(int row, int column) const {
    stack<Stone> rightSide;
    for (int col = column; col < this->cols; col++) {
        if (col + 1 >= this->cols) {
            break;
        }
        Stone *nextStone = &this->board[row][col + 1];
        if (nextStone->type == STONE || nextStone->type == STONEANDGOAL || nextStone->type == REPEL ||
            nextStone->type == REPELANDGOAL || nextStone->type == ATTRACT || nextStone->type == ATTRACTANDGOAL ||
            nextStone->type == GOAL) {
            if (nextStone->type != GOAL) {
                rightSide.push(*nextStone);
            }
        } else {
            break;
        }
    }
    while (!rightSide.empty() && rightSide.top().type != OBSTACLE) {
        Stone stone = rightSide.top();
        rightSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow;
        int newCol = oldCol + 1;
        if (newCol >= this->cols) {
            break;
        }
        this->movementReplacing(oldRow, oldCol, newRow, newCol);
    }
}

void Board::handleRepelReflectionLeft(int row, int column) const {
    stack<Stone> leftSide;
    for (int col = column; col >= 0; col--) {  // Iterate to the left
        if (col - 1 < 0) {
            break;
        }
        Stone *nextStone = &this->board[row][col - 1];  // Update to the left column
        if (nextStone->type == STONE || nextStone->type == STONEANDGOAL || nextStone->type == REPEL ||
            nextStone->type == REPELANDGOAL || nextStone->type == ATTRACT || nextStone->type == ATTRACTANDGOAL ||
            nextStone->type == GOAL) {
            if (nextStone->type != GOAL) {
                leftSide.push(*nextStone);
            }
        } else {
            break;
        }
    }
    while (!leftSide.empty() && leftSide.top().type != OBSTACLE) {
        Stone stone = leftSide.top();
        leftSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow;
        int newCol = oldCol - 1;  // Move to the left
        if (newCol < 0) {
            break;
        }
        this->movementReplacing(oldRow, oldCol, newRow, newCol);
    }
}

void Board::handleRepelReflectionUp(int row, int column) const {
    stack<Stone> upSide;
    for (int r = row; r >= 0; r--) {  // Iterate upwards
        if (r - 1 < 0) {
            break;
        }
        Stone *nextStone = &this->board[r - 1][column];
        if (nextStone->type == STONE || nextStone->type == STONEANDGOAL || nextStone->type == REPEL ||
            nextStone->type == REPELANDGOAL || nextStone->type == ATTRACT || nextStone->type == ATTRACTANDGOAL ||
            nextStone->type == GOAL) {
            if (nextStone->type != GOAL) {
                upSide.push(*nextStone);
            }
        } else {
            break;
        }
    }


    while (!upSide.empty() && upSide.top().type != OBSTACLE) {
        Stone stone = upSide.top();
        upSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow - 1;  // Move up
        int newCol = oldCol;
        if (newRow < 0) {
            break;
        }
        this->movementReplacing(oldRow, oldCol, newRow, newCol);
    }
}

void Board::handleRepelReflectionDown(int row, int column) const {
    stack<Stone> downSide;
    for (int r = row; r < this->rows; r++) {  // Iterate downwards
        if (r + 1 >= this->rows) {
            break;
        }
        Stone *nextStone = &this->board[r + 1][column];
        if (nextStone->type == STONE || nextStone->type == STONEANDGOAL || nextStone->type == REPEL ||
            nextStone->type == REPELANDGOAL || nextStone->type == ATTRACT || nextStone->type == ATTRACTANDGOAL ||
            nextStone->type == GOAL) {
            if (nextStone->type != GOAL) {
                downSide.push(*nextStone);
            }
        } else {
            break;
        }
    }
    while (!downSide.empty() && downSide.top().type != OBSTACLE) {
        Stone stone = downSide.top();
        downSide.pop();
        auto [oldRow, oldCol] = stone.position;
        int newRow = oldRow + 1;  // Move down
        int newCol = oldCol;
        if (newRow >= this->rows) {
            break;
        }
        this->movementReplacing(oldRow, oldCol, newRow, newCol);
    }
}

void Board::movementReplacing(int oldRow, int oldCol, int newRow, int newCol) const {
    Stone *nextCell = &board[newRow][newCol];
    Stone *currentCell = &board[oldRow][oldCol];

    if (nextCell->type == EMPTY && currentCell->type == STONE) {
        nextCell->stone({newRow, newCol});
        currentCell->empty({oldRow, oldCol});
    } else if (nextCell->type == GOAL && currentCell->type == STONE) {
        nextCell->stoneAndGoal({newRow, newCol});
        currentCell->empty({oldRow, oldCol});
    } else if (currentCell->type == STONEANDGOAL && nextCell->type == EMPTY) {
        nextCell->stone({newRow, newCol});
        currentCell->goal({oldRow, oldCol});
    } else if (currentCell->type == STONEANDGOAL && nextCell->type == GOAL) {
        nextCell->stoneAndGoal({newRow, newCol});
        currentCell->goal({oldRow, oldCol});
    }
}