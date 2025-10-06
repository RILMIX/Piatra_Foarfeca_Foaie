#pragma once

#include <iostream>
#include <limits>
#include "choice.hpp"

class Player {
private:
    Choice selectedChoice;

public:
    void chooseOption() {
        int value = -1;
        bool valid = false;

        while (!valid) {
            std::cout << "Alege o opțiune: 0 = Rock, 1 = Paper, 2 = Scissors -> ";
            if (std::cin >> value && value >= 0 && value <= 2) {
                selectedChoice = static_cast<Choice>(value);
                valid = true;
            }
            else {
                std::cout << "Input invalid. Introdu un număr între 0 și 2.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }

    Choice getSelectedChoice() const {
        return selectedChoice;
    }
};
