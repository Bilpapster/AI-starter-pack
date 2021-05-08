#include <iostream>
#include <string>
#include <Tic Tac Toe/TicTacToe.h>
#include "N-puzzle/PuzzleSolver/PuzzleSolver.h"

int main() {

    std::string answer;
    int selectionNumber = 0;

    do {
        std::cout << "Please select operation mode:\n"
                  << "1. Start N-puzzle solver\n"
                  << "2. Play tic-tac-toe against computer\n"
                  << "Your answer ...";
        std::cin >> answer;
        selectionNumber = std::stoi(answer);

        if ((selectionNumber - 1) && (selectionNumber - 2)) {
            std::cout << "Invalid input, please enter 1 or 2 \n\n";
        } else break;

    } while (true);

    switch (selectionNumber) {
        case 1:
            PuzzleSolver::start();
            break;
        default:
            TicTacToe::play();
            break;
    }
    return 0;
}

