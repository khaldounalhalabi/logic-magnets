#include <iostream>
#include <vector>

using namespace std;

// Create a grid of empty spaces
vector<vector<char>> grid(5, vector<char>(5, ' '));

// Create a list of all possible magnet polarities
const char magnetPolarities[] = {'+', '-'};

// Create a function to generate a random magnet polarity
char generateRandomMagnetPolarity() {
    return magnetPolarities[rand() % 2];
}

// Create a function to place a magnet in a grid space
void placeMagnet(int row, int col, char polarity) {
    grid[row][col] = polarity;
}

// Create a function to check if a grid is valid
bool isValidGrid() {
    // Check if each row and column has the same number of positive and negative poles
    for (int i = 0; i < 5; i++) {
        int positivePoles = 0;
        int negativePoles = 0;
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == '+') {
                positivePoles++;
            } else if (grid[i][j] == '-') {
                negativePoles++;
            }
        }
        if (positivePoles != negativePoles) {
            return false;
        }
    }

    // Check if opposite poles attract and like poles repel
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] != ' ') {
                // Check the four adjacent grid spaces
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        int rowOffset = i + dx;
                        int colOffset = j + dy;
                        if (rowOffset >= 0 && rowOffset < 5 && colOffset >= 0 && colOffset < 5) {
                            char adjacentMagnet = grid[rowOffset][colOffset];
                            if (adjacentMagnet != ' ' && grid[i][j] == adjacentMagnet) {
                                return false;
                            } else if (adjacentMagnet != ' ' && grid[i][j] != adjacentMagnet) {
                                // Opposite poles attract
                                if (grid[i][j] == '+' && adjacentMagnet == '-' || grid[i][j] == '-' && adjacentMagnet == '+') {
                                    // Valid
                                } else {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    // The grid is valid
    return true;
}

// Generate a random puzzle
void generateRandomPuzzle() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            placeMagnet(i, j, generateRandomMagnetPolarity());
        }
    }
}

// Print the puzzle to the console
void printPuzzle() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

int main() {
    // Generate a random puzzle
    generateRandomPuzzle();

    // Print the puzzle to the console
    printPuzzle();

    // Check if the puzzle is valid
    if (isValidGrid()) {
        cout << "The puzzle is valid!" << endl;
    } else {
        cout << "The puzzle is invalid!" << endl;
    }

    return 0;
}
