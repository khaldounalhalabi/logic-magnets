#include "Board.h"
#include "Stone.h"
#include "vector"

using namespace std;

struct Node {
    Board board;
    vector<Node> children;
    int depth{};

    explicit Node(Board level) : board(level) {}

    void addChild(const Node &childNode) {
        children.push_back(childNode);
    }
};

Node *createNode(Board level) {
    Node *newNode = new Node(level);
    return newNode;
}

int main() {
    Board board(5, 4, 1);
    Stone *attract = &board.board[3][1];
    attract->attract({3, 1});
    board.board[0][0].stone({0, 0});
    board.board[4][3].stone({4, 3});
    board.board[1][0].stoneAndGoal({1, 0});
    board.board[2][0].goal({2, 0});
    board.board[4][0].goal({4, 0});
    board.board[4][2].goal({4, 2});
    board.board[3][0].obstacle({3, 0});
    board.board[4][1].obstacle({3, 0});

    board.printBoard();

    for (int i = 0; i < board.allowedMoves; i++) {
        attract = board.moveAttract(*attract);
    }

    board.destroy();

    return 0;
}




