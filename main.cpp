#include "Board.h"
#include "Stone.h"
#include "Algorithm.h"

using namespace std;

int main() {
    Board board(3, 4, 2);
    Stone repel = board.board[2][0].repel({2, 0});
    Stone stone = board.board[1][2].stone({1, 2});
    Stone goal1 = board.board[1][1].goal({1, 1});
    Stone goal2 = board.board[1][3].goal({1, 3});

    board.initMovables();

    Algorithm::bfs(board);


//    board.printBoard();

//    for (int i = 0; i < board.allowedMoves; i++) {
//        attract = board.moveAttract(*attract);
//    }

    return 0;
}




