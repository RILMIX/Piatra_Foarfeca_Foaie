#pragma once

#include <cstdlib>
#include "choice.hpp"

class Computer {
private:
    Choice currentChoice;

public:
    void pickRandomChoice() {
        int randomValue = std::rand() % 3;  // 0, 1 sau 2
        currentChoice = static_cast<Choice>(randomValue);
    }

    Choice getCurrentChoice() const {
        return currentChoice;
    }

    int asInt() const {
        return static_cast<int>(currentChoice);
    }
};
