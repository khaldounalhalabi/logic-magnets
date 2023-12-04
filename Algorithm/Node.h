//
// Created by Khaldoun Alhalabi on 11/27/2023.
//

#ifndef SMART_ALGORITHMS_NODE_H
#define SMART_ALGORITHMS_NODE_H

#pragma once

#include <vector>
#include "../Board/Board.h"

class Node {
public:
    Board board;
    vector<Node *> children;
    int depth = 0;
    Node *parent = nullptr;
    int cost = 0;
    int heuristicCost = 0;
    bool visited = false;

    explicit Node(Board level) : board(level) {}

    void addChild(Node *childNode);

    static Node *createNode(const Board& level);
};

#endif //SMART_ALGORITHMS_NODE_H
