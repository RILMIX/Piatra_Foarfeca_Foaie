#pragma once

#include <cstdlib>
#include "Choice.hpp"

class Computer {
private:
    Choice selectedOption;

public:
    // Generează o alegere aleatoare (0, 1 sau 2)
    void pickRandomChoice() {
        int randomNum = std::rand() % 3;
        selectedOption = static_cast<Choice>(randomNum);
    }

    Choice pickRandomChoice() const {
        return selectedOption;
    }

    int toInt() const {
        return static_cast<int>(selectedOption);
    }
};
