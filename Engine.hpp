#pragma once

#include "Player.hpp"

class Engine {
private:
    Player& player;
    Player& opponent;
    int totalRounds = 0;
    int winsPlayer = 0;
    int winsComputer = 0;
    int draws = 0;

public:
    Engine(Player& p, Player& o) : player(p), opponent(o) {}
    void start();

private:
    void intro() const;
    void obtainSelections();
    void drawSelections() const;
    void analyzeOutcome();
    void showScoreboard() const;
};