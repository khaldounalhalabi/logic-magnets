#include "Board.h"
#include "Stone.h"

using namespace std;

int main() {
    Board board(3, 4, 2);

    Stone repel = board.board[2][0].repel({2, 0});
    Stone goal1 = board.board[1][1].goal({1, 1});
    Stone goal2 = board.board[1][3].goal({3, 1});
    Stone stone = board.board[1][2].stone({2, 1});

    board.printBoard();

    for (int i = 0; i < board.allowedMoves; i++) {
        board.moveRepel(repel);
    }

    board.destroy();

    return 0;
}



