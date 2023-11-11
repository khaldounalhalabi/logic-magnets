//
// Created by Khaldoun Alhalabi on 11/5/2023.
//

#ifndef SMART_ALGORITHMS_ALGORITHM_H
#define SMART_ALGORITHMS_ALGORITHM_H


#include "../Board/Board.h"

class Algorithm {

public:
    static Board move(Board board, const Stone &selectedStone, int row, int col);

    static bool handleMovable(const Stone &stone, int row, int col, Stone &currentCell, Stone &targetCell);

    static void bfs(const Board& board);

    void static showPath(const Board& child);
};


#endif //SMART_ALGORITHMS_ALGORITHM_H