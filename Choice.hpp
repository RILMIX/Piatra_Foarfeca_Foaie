#pragma once

#include "Choice.hpp"
#include "Player.hpp"
#include <random>

class Computer : public Player
{
private:
    Choice generatedChoice = Choice::Rock;

public:
    Computer() = default;

    void generateMove();

    Choice getMove() const;
};
