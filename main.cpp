#include "Board.h"
#include "Stone.h"

int main() {
    Board board(3, 4, 2);
    Stone repel(REPEL, true, {1, 3}, board);
    Stone goal1(GOAL, false, {2, 2}, board);
    Stone stone(STONE, true, {3, 2}, board);
    Stone goal2(GOAL, false, {4, 2}, board);
    board.printBoard();

    for (int i = 0; i < board.allowedMoves; i++) {
        repel.requestMove();
    }

    board.destroy();
    return 0;
}



