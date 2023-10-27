#include <iostream>
#include "Board.h"

int main() {
    auto* board = new Board(5 , 5);

    board->printBoard();
    board->destroy();

    return 0;
}
