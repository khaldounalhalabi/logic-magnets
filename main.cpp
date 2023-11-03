#include "Board.h"
#include "Stone.h"
#include "vector"

using namespace std;

struct Node {
    Board board;
    vector<Node> children;
    int depth{};

    explicit Node(Board level) : board(level)  {}

    void addChild(const Node& childNode)
    {
        children.push_back(childNode);
    }
};

Node* createNode(Board level) {
    Node* newNode = new Node(level);
    return newNode;
}

int main() {
    Board board(1, 7, 2);
    Stone *repel = &board.board[0][0];
    repel->repel({0, 0});
    board.board[0][1].goal({0, 1});
    board.board[0][6].goal({0, 6});
    board.board[0][3].stoneAndGoal({0, 3});
    board.board[0][5].stone({0, 5});

    board.printBoard();

    for (int i = 0; i < board.allowedMoves; i++) {
        repel = board.moveRepel(*repel);
    }

    board.destroy();

    return 0;
}




