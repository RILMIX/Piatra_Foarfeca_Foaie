#pragma once
#include "choice.hpp"

class Computer {
private:
    Choice opt;

public:
    void    pick();
    Choice  get() const;
};