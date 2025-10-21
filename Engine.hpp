#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp"

class Engine {
private:
    Player& human;
    Computer& bot;

public:
    Engine(Player& p, Computer& c) : human(p), bot(c) {}

    void run() {
        // Jucătorul își alege opțiunea
        human.choose();

        // Calculatorul generează aleatoriu o alegere
        bot.Chouse();

        // Afișăm ambele alegeri într-un mod clar
        std::cout << "Tu ai ales " << choiceToString(human.getSelected());
        std::cout << ", iar calculatorul a ales " << choiceToString(bot.getChoice()) << ". ";

        // Determinăm rezultatul jocului
        if (human.getSelected() == bot.getChoice()) {
            std::cout << "Rezultat: Egalitate!\n";
        }
        else if (
            (human.getSelected() == ROCK && bot.getChoice() == SCISSORS) ||
            (human.getSelected() == PAPER && bot.getChoice() == ROCK) ||
            (human.getSelected() == SCISSORS && bot.getChoice() == PAPER)
            ) {
            std::cout << "Rezultat: Ai câștigat!\n";
        }
        else {
            std::cout << "Rezultat: Calculatorul a câștigat!\n";
        }

        std::cout << std::endl;
    }

private:
    static std::string choiceToString(Choice c) {
        switch (c) {
        case ROCK: return "Piatra";
        case PAPER: return "Hartie";
        case SCISSORS: return "Foarfeca";
        default: return "Necunoscut";
        }
    }
};
