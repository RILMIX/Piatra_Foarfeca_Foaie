#pragma once

#include <iostream>
#include <string>
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp"

class Engine {
private:
    // Păstrăm numele tale, dar le definim invers (Computer, Player)
    Computer& bot;
    Player& human;

public:
    // Păstrăm constructorul tău
    Engine(Player& p, Computer& c) : human(p), bot(c) {}

    void run() {
        human.choose();
        bot.pick(); // Presupunând că ai ales 'pick()' din discuția anterioară

        std::cout << "Tu ai ales ";
        // Folosim switch, similar cu prietenul, dar păstrăm mesajul tău în română
        switch (human.getSelected()) {
        case ROCK: std::cout << "Piatra"; break;
        case PAPER: std::cout << "Hartie"; break;
        case SCISSORS: std::cout << "Foarfeca"; break;
        }

        std::cout << ", iar calculatorul a ales ";
        switch (bot.get()) { // Folosim get() conform fisierului Computer.hpp anterior
        case ROCK: std::cout << "Piatra"; break;
        case PAPER: std::cout << "Hartie"; break;
        case SCISSORS: std::cout << "Foarfeca"; break;
        }
        std::cout << ". ";

        // Logica de determinare a rezultatului (păstrată identic)
        Choice player_choice = human.getSelected(); // Variabilă locală pentru citire mai ușoară
        Choice bot_choice = bot.get();

        if (player_choice == bot_choice) {
            std::cout << "Rezultat: Egalitate! (TIE)\n";
        }
        else if (
            (player_choice == ROCK && bot_choice == SCISSORS) ||
            (player_choice == PAPER && bot_choice == ROCK) ||
            (player_choice == SCISSORS && bot_choice == PAPER)
            ) {
            std::cout << "Rezultat: Ai câștigat! (WIN)\n";
        }
        else {
            std::cout << "Rezultat: Calculatorul a câștigat! (LOSS)\n";
        }
        std::cout << "\n";
    }
};