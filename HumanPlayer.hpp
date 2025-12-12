#pragma once

#include "Player.hpp"

class HumanPlayer : public Player {
public:
    void makeChoice() override;
    Choice getChoice() const override;
};