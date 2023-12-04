//
// Created by Khaldoun Alhalabi on 11/5/2023.
//

#ifndef SMART_ALGORITHMS_ALGORITHM_H
#define SMART_ALGORITHMS_ALGORITHM_H

#include "../Board/Board.h"
#include "Node.h"

class Algorithm {

public:
    int visitedNodes = 0;

    Algorithm();

    static Board move(Board board, const Stone &selectedStone, int row, int col);

    static bool handleMovable(const Stone &stone, int row, int col, Stone &currentCell, Stone &targetCell);

    static void bfs(const Board &board);

    void static showPath(const Board &child);

    static void ucs(const Board &board);

    static void askForSolutionPath(const Board &board);

    void hillClimbing(Node *&node);

    static void getNextStates(Node *&node);

    static void calcHeuristicCost(Node *&node);

    static void getMinimumHeurCost(Node *&node);
};


#endif //SMART_ALGORITHMS_ALGORITHM_H
