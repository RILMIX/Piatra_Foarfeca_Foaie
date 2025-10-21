#pragma once

#include <iostream>
#include <limits>
#include <string>
#include "Choice.hpp"

class Player {
private:
    std::string name;
    Choice selected;

public:
    Player();
    Player(const std::string& name, Choice choice);
    Player(const Player& other);
    Player& operator=(const Player& other);

    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    bool operator<(const Player& other) const;
    bool operator>(const Player& other) const;

    friend std::istream& operator>>(std::istream& is, Player& player);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    void choose();
    Choice getSelected() const;
    void showChoice() const;
};
    