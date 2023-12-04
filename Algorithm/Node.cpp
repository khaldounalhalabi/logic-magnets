//
// Created by Khaldoun Alhalabi on 11/27/2023.
//

#include "Node.h"

void Node::addChild(Node *childNode) {
    children.push_back(childNode);
}

Node *Node::createNode(const Board& level) {
    Node *newNode = new Node(level);
    return newNode;
}