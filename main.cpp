#include "Board.h"
#include "Stone.h"
#include "Algorithm.h"
#include "Message.h"
#include <chrono>

using namespace std;

int main() {
    Board board(5, 5, 5);
    Stone *repel = &board.board[4][0];
    repel->repel({4, 0});
    board.board[0][2].goal({0, 2});
    board.board[2][0].goal({2, 0});
    board.board[2][2].goal({2, 2});
    board.board[2][4].goal({2, 4});
    board.board[4][2].goal({4, 2});
    board.board[1][2].stone({1, 2});
    board.board[2][1].stone({2, 1});
    board.board[2][3].stone({2, 3});
    board.board[3][2].stone({3, 2});

    Message::message("Game Start State");
    board.printBoard();

    cout << "<----------------------------------->" << endl;

    auto start_time = chrono::high_resolution_clock::now();
    Algorithm::bfs(board);
    auto end_time = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "-------------------------------------------------------------\n";
    cout << "Execution Time In Micro Seconds Ss : " << duration.count() << " Micro Second" << endl;
    cout << "-------------------------------------------------------------\n";

//    board.printBoard();

//    for (int i = 0; i < board.allowedMoves; i++) {
//        repel = board.moveAttract(*repel);
//    }

    return 0;
}




