#pragma once

#include "Choice.hpp"

class Player {
protected:
    Choice choice = Choice::Rock; // Default value
public:
    virtual ~Player() = default;
    virtual void makeChoice() = 0;
    virtual Choice getChoice() const = 0;
};