#include "LevelInitializer/LevelInitializer.h"
#include "Message/Message.h"
#include <iostream>

using namespace std;

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




