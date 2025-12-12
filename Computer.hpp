#pragma once

#include "Player.hpp"

class Computer : public Player {
public:
    void makeChoice() override;
    Choice getChoice() const override;
};