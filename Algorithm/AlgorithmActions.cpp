//
// Created by Khaldoun Alhalabi on 11/7/2023.
//

#include "Algorithm.h"
#include "../Message/Message.h"
#include "../Board/Board.h"

Board Algorithm::move(Board board, const Stone &selectedStone, int row, int col) {
    Stone *currentCell = &board.board[selectedStone.position.row][selectedStone.position.col];
    Stone *targetCell = &board.board[row][col];
    board.dirty = false;

    bool result = handleMovable(selectedStone, row, col, *currentCell, *targetCell);

    if (result) {
        board.dirty = true;
        if (selectedStone.type == REPEL || selectedStone.type == REPELANDGOAL) {
            board.handleRepelReflection(row, col);
        } else if (selectedStone.type == ATTRACTANDGOAL || selectedStone.type == ATTRACT) {
            board.handleAttractReflection(row, col);
        }
    }

    return board;
}

bool Algorithm::handleMovable(const Stone &stone, int row, int col, Stone &currentCell, Stone &targetCell) {

    /*************** attract moves *************/

    // if the target cell is empty and the current cell contain only the "stone" stone
    if (targetCell.type == EMPTY && currentCell.type == ATTRACT) {
        currentCell.empty(stone.position);
        targetCell.attract({row, col});
        return true;
    }

        // if the target cell is empty and the current is "repel in the goal"
    else if (targetCell.type == EMPTY && currentCell.type == ATTRACTANDGOAL) {
        currentCell.goal(stone.position);
        targetCell.attract({row, col});
        return true;
    }

        // if the target cell is goal and the current is "repel"
    else if (targetCell.type == GOAL && currentCell.type == ATTRACT) {
        currentCell.empty(stone.position);
        targetCell.attractAndGoal({row, col});
        return true;
    }

        // if the current cell is "repel and goal and the target cell is goal"
    else if (currentCell.type == ATTRACTANDGOAL && targetCell.type == GOAL) {
        currentCell.goal(stone.position);
        targetCell.attractAndGoal({row, col});
        return true;
    }


        /*************** repel moves *************/

        // if the target cell is empty and the current cell contain only the current stone
    else if (targetCell.type == EMPTY && currentCell.type == REPEL) {
        currentCell.empty(stone.position);
        targetCell.repel({row, col});
        return true;
    }

        // if the target cell is empty and the current is "repel in the goal"
    else if (targetCell.type == EMPTY && currentCell.type == REPELANDGOAL) {
        currentCell.goal(stone.position);
        targetCell.repel({row, col});
        return true;
    }

        // if the target cell is goal and the current is "repel"
    else if (targetCell.type == GOAL && currentCell.type == REPEL) {
        currentCell.empty(stone.position);
        targetCell.repelAndGoal({row, col});
        return true;
    }

        // if the current cell is "repel and goal and the target cell is goal"
    else if (currentCell.type == REPELANDGOAL && targetCell.type == GOAL) {
        currentCell.goal(stone.position);
        targetCell.repelAndGoal({row, col});
        return true;
    } else return false;
}
