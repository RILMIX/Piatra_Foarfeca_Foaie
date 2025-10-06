#pragma once

#include <iostream>
#include "player.hpp"
#include "computer.hpp"
#include "choice.hpp"

class GameEngine {
private:
    Player& human;
    Computer& ai;

public:
    GameEngine(Player& p, Computer& c) : human(p), ai(c) {}

    void start() {
        human.chooseOption();
        ai.pickRandomChoice();
        std::cout << "\nTu ai ales: " << choiceToString(human.getSelectedChoice())
            << "\nComputerul a ales: " << choiceToString(ai.getCurrentChoice())
            << "\nRezultat: " << determineOutcome() << "\n";
    }

private:
    static std::string choiceToString(Choice c) {
        switch (c) {
        case ROCK:     return "Rock";
        case PAPER:    return "Paper";
        case SCISSORS: return "Scissors";
        default:       return "Unknown";
        }
    }

    std::string determineOutcome() const {
        Choice playerChoice = human.getSelectedChoice();
        Choice computerChoice = ai.getCurrentChoice();

        if (playerChoice == computerChoice)
            return "Egalitate!";
        if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
            (playerChoice == PAPER && computerChoice == ROCK) ||
            (playerChoice == SCISSORS && computerChoice == PAPER))
            return "Ai câștigat!";
        return "Computerul a câștigat!";
    }
};
