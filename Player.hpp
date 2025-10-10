#pragma once

#include <iostream>
#include <limits>
#include "Choice.hpp"

class Player {
private:
    Choice selected;

public:
    void choose();
    Choice getSelected() const;
    void showChoice() const;
};
