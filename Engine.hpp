#pragma once

#include <iostream>
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp"

class Engine {
private:
    Player& player;
    Computer& computer;

    int roundsPlayed = 0;
    int playerWins = 0;
    int computerWins = 0;
    int ties = 0;

public:
    Engine(Player& p, Computer& c) : player(p), computer(c) {}

    void run()
    {
        Init();

        while (true)
        {
            CurrentResult();   
            MakeChoices();     
            DisplayChoices();  
            DetermineResult(); 
        }
    }

private:


    void Init() {
        std::cout << "Welcome to Rock-Paper-Scissors!\n";
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors).\n";
        std::cout << "Exit with Ctrl+C\n";
        std::cout << "-------------------------\n";
    }

    void MakeChoices() {
        player.makeChoice();
        computer.makeChoice();
    }

    void DisplayChoices() {
        Choice player_choice = player.getChoice();
        Choice computer_choice = computer.getChoice();

        std::cout << "Tu ai ales " << player_choice
            << ", Calculatorul a ales " << computer_choice
            << " - ";
    }

    void DetermineResult() {
        ++roundsPlayed;

        Choice p = player.getChoice();
        Choice c = computer.getChoice();

        if (p == c) {
            std::cout << "Egalitate!\n";
            ++ties;
        }
        else if (
            (p == Choice::Rock && c == Choice::Scissors) ||
            (p == Choice::Paper && c == Choice::Rock) ||
            (p == Choice::Scissors && c == Choice::Paper)
            ) {
            std::cout << "Ai castigat!\n";
            ++playerWins;
        }
        else {
            std::cout << "Calculatorul a castigat!\n";
            ++computerWins;
        }
    }

    void CurrentResult() {
        std::cout << "\n--- Scor Curent ---\n";
        std::cout << "Runde jucate: " << roundsPlayed << "\n";
        std::cout << "Victoriile tale: " << playerWins << "\n";
        std::cout << "Victorii Calculator: " << computerWins << "\n";
        std::cout << "Egalitati: " << ties << "\n";
        std::cout << "--------------------\n";
    }
};
