#include "Board/Board.h"
#include "Stone/Stone.h"
#include "Algorithm/Algorithm.h"
#include "Message/Message.h"
#include "LevelInitializer/LevelInitializer.h"

using namespace std;

int main() {

    LevelInitializer levelInitializer;
    levelInitializer.handler();

//    Message::message("Game Start State");
//    board.printBoard();
//
//    cout << "<----------------------------------->" << endl;
//
//    auto start_time = chrono::high_resolution_clock::now();
//    Algorithm::bfs(board);
//    auto end_time = chrono::high_resolution_clock::now();
//
//    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
//
//    cout << "-------------------------------------------------------------\n";
//    cout << "Execution Time In Micro Seconds Ss : " << duration.count() << " Micro Second" << endl;
//    cout << "-------------------------------------------------------------\n";

//    board.printBoard();

//    for (int i = 0; i < board.allowedMoves; i++) {
//        repel = board.moveAttract(*repel);
//    }

    return 0;
}




