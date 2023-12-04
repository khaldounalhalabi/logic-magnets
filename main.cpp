#include "LevelInitializer/LevelInitializer.h"
#include "Message/Message.h"
#include "Algorithm/Node.h"
#include "Algorithm/Algorithm.h"

using namespace std;

void showPath(const Node *child) {
    child->board.printBoard();
    if (child->parent == nullptr) {
        return;
    }
    return showPath(child->parent);
}

int main() {

    LevelInitializer levelInitializer;

    bool play = false;

    do {
        Message::message("1- Play");
        Message::message("0- Exit");
        cin >> play;
        levelInitializer.handler();
    } while (play);

    return 0;
}





