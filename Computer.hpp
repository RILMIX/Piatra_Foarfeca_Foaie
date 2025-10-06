#pragma once

#include <cstdlib>
#include "Choice.hpp"

class Bot {
private:
    Choice selectedOption;

public:
    void randomizeChoice() {
        int randomNum = std::rand() % 3; // generează 0, 1 sau 2
        selectedOption = static_cast<Choice>(randomNum);
    }

    Choice getSelectedOption() const {
        return selectedOption;
    }

    int toInt() const {
        return static_cast<int>(selectedOption);
    }
};
