#pragma once
#include "choice.hpp"

class Computer {
    Choice opt;
public:
    void pick();
    Choice get() const;
};
