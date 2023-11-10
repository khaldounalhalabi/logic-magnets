#include "Board.h"
#include "Stone.h"
#include "Algorithm.h"

using namespace std;

int main() {
    Board board(3, 4, 2);
    Stone *attract = &board.board[2][3];
    attract->attract({2, 3});
    board.board[0][1].stone({0, 1});
    board.board[1][2].stone({1, 2});
    board.board[1][1].stoneAndGoal({1, 1});
    board.board[0][2].goal({0, 2});
    board.board[1][0].goal({1, 0});
    board.board[2][1].goal({2, 1});
    board.board[2][0].repelAndGoal({2, 0});

    board.printBoard();

//    Algorithm::bfs(board);


//    board.printBoard();

//    for (int i = 0; i < board.allowedMoves; i++) {
//        attract = board.moveAttract(*attract);
//    }

    return 0;
}




