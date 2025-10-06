#pragma once

#include <iostream>
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp"

class GameCore {
private:
    Player& human;
    Computer& bot;

public:
    GameCore(Player& p, Computer& c) : human(p), bot(c) {}

    void startGame() {
        human.choose();
        bot.pickRandomChoice();

        std::cout << "Tu ai ales: " << choiceToString(human.getSelected())
            << ", iar calculatorul a ales: " << choiceToString(bot.getCurrentChoice())
            << ".\nRezultat: " << getResult(human.getSelected(), bot.getCurrentChoice()) << "\n";
    }

private:
    static std::string choiceToString(Choice c) {
        switch (c) {
        case ROCK: return "Piatră";
        case PAPER: return "Hârtie";
        case SCISSORS: return "Foarfecă";
        default: return "Necunoscut";
        }
    }

    static std::string getResult(Choice playerChoice, Choice computerChoice) {
        if (playerChoice == computerChoice)
            return "Egalitate!";
        if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
            (playerChoice == PAPER && computerChoice == ROCK) ||
            (playerChoice == SCISSORS && computerChoice == PAPER))
            return "Ai câștigat!";
        return "Calculatorul a câștigat!";
    }
};
