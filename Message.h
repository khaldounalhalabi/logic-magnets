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
        std::string horizontalLine(width, '-');
        std::string verticalLine = "| " + message + "      |";

        // Print the top border
        for (int i = 0; i < height; i++) {
            if (i == 0) {
                std::cout << horizontalLine << std::endl;
            } else {
                std::cout << "| " << std::string(message.length() + 8, ' ') << " |" << std::endl;
            }
        }

        // Print the message
        std::cout << verticalLine << std::endl;

        // Print the bottom border
        for (int i = 0; i < height; i++) {
            if (i == height - 1) {
                std::cout << horizontalLine << std::endl;
            } else {
                std::cout << "| " << std::string(message.length() + 8, ' ') << " |" << std::endl;
            }
        }
    }
};


#endif //SMART_ALGORITHMS_MESSAGE_H
