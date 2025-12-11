#pragma once

#include <iostream>
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp" 
// Notă: Nu mai este nevoie de lungile switch-uri de afișare datorită operatorului << din Choice.hpp!

class Engine {
private:
    // Păstrăm denumirile simple ale prietenului pentru simplitate
    Player& player;
    Computer& computer;

public:
    // Constructor
    Engine(Player& p, Computer& c) : player(p), computer(c) {}

    // Funcția principală care rulează o rundă de joc
    void run() {
        // 1. Jucătorii aleg (Uniformizat la makeChoice() și pentru Computer)
        player.makeChoice();
        computer.makeChoice(); // Atenție: presupunem că Computer are acum makeChoice()

        // Obținem alegerile (Folosim direct denumirile prietenului)
        Choice player_choice = player.getChoice();
        Choice computer_choice = computer.getChoice();

        // 2. Afișăm alegerile într-un format simplificat și elegant, folosind operatorul <<
        std::cout << "Tu ai ales " << player_choice;
        std::cout << ", Calculatorul a ales " << computer_choice;
        std::cout << " - ";

        // 3. Determinăm rezultatul (Logică Rock, Paper, Scissors)
        if (player_choice == computer_choice) {
            std::cout << "Egalitate!\n";
        }
        // Verificăm condițiile de câștig pentru Jucător
        else if (
            (player_choice == Choice::ROCK && computer_choice == Choice::SCISSORS) ||
            (player_choice == Choice::PAPER && computer_choice == Choice::ROCK) ||
            (player_choice == Choice::SCISSORS && computer_choice == Choice::PAPER)
            ) {
            std::cout << "Ai câștigat!\n";
        }
        // Dacă nu e egalitate și nu e câștig, e pierdere
        else {
            std::cout << "Calculatorul a câștigat!\n";
        }
        std::cout << "\n";
    }
};