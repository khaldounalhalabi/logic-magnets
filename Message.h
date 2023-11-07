//
// Created by Khaldoun Alhalabi on 11/3/2023.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef SMART_ALGORITHMS_MESSAGE_H
#define SMART_ALGORITHMS_MESSAGE_H

class Message {
public:
    static void message(const string &message) {
        int height = 1;
        unsigned long width = message.length() + 8;
        string horizontalLine(width, '-');
        string verticalLine = "| " + message + "      |";

        // Print the top border
        for (int i = 0; i < height; i++) {
            if (i == 0) {
                cout << horizontalLine << endl;
            } else {
                cout << "| " << string(message.length() + 8, ' ') << " |" << endl;
            }
        }

        // Print the message
        cout << verticalLine << endl;

        // Print the bottom border
        for (int i = 0; i < height; i++) {
            if (i == height - 1) {
                cout << horizontalLine << endl;
            } else {
                cout << "| " << string(message.length() + 8, ' ') << " |" << endl;
            }
        }
    }
};


#endif //SMART_ALGORITHMS_MESSAGE_H
