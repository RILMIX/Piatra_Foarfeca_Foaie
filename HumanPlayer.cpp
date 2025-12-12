#include "HumanPlayer.hpp"
#include <iostream>
#include <limits>

void HumanPlayer::makeChoice() {
    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        if (!(std::cin >> input) || !(input >= 0 && input <= 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            choice = static_cast<Choice>(input);
            break;
        }
    } while (true);
}

Choice HumanPlayer::getChoice() const {
    return choice;
}