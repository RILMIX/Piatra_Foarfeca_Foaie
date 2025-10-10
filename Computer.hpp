#pragma once

#include <cstdlib>
#include "Choice.hpp"

class Computer {
private:
    Choice selectedOption;

public:
    // Generează o alegere aleatoare (0, 1 sau 2)
    void Chouse() {
        int randomNum = std::rand() % 3;
        selectedOption = static_cast<Choice>(randomNum);
    }

    Choice Chouse() const {
        return selectedOption;
    }

    int toInt() const {
        return static_cast<int>(selectedOption);
    }
};
