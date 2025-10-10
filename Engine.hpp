#pragma once

#include <iostream>
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp"
#include <string>

class Engine {
private:
    Player human;
    Computer bot;

public:
    Engine(Player& p, Computer& c) : human(p), bot(c) {}

    void run() {
        human.choose();
        bot.pickRandomChoice();

        std::cout << "Tu ai ales: " << choiceToString(human.getSelected())
            << ", iar calculatorul a ales: " << choiceToString(bot.pickRandomChoice())
            << ".\nRezultat: " << getResult(human.getSelected(), bot.pickRandomChoice()) << "\n";
    }

private:
    static std::string choiceToString(Choice c) {
        switch (c) {
        case ROCK: return "Piatra";
        case PAPER: return "Hartie";
        case SCISSORS: return "Foarfec";
        default: return "Necunoscut";
        }
    }

    static std::string getResult(Choice playerChoice, Choice computerChoice) {
        if (playerChoice == computerChoice)
            return "Egalitate!";
        if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
            (playerChoice == PAPER && computerChoice == ROCK) ||
            (playerChoice == SCISSORS && computerChoice == PAPER))
            return "Ai castigat!";
        return "Calculatorul a castigat!";
    }
};
