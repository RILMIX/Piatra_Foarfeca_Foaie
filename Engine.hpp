#pragma once

#include <iostream>
// Nu mai avem nevoie de <string> aici, deci o eliminăm pentru simplitate
#include "Player.hpp"
#include "Computer.hpp"
#include "Choice.hpp" // Presupunem că enum-ul Choice este definit aici

// Această clasă gestionează logica jocului (cine alege, cine câștigă)
class Engine {
private:
    // Folosim nume simple, directe, pentru a simplifica codul
    Player& p_jucator;
    Computer& c_calculator;

public:
    // Constructorul primește referințele la jucător și calculator
    Engine(Player& p, Computer& c) : p_jucator(p), c_calculator(c) {}

    // Funcția principală care rulează o rundă de joc
    void run() {
        // 1. Jucătorii aleg
        p_jucator.makeChoice(); // Am schimbat în 'makeChoice' pentru a fi consistent cu prietenul tău
        c_calculator.generateChoice(); // Am schimbat în 'generateChoice' pentru a fi consistent cu prietenul tău

        // Obținem alegerile pentru a le compara
        Choice alegere_jucator = p_jucator.getChoice(); // Presupunem că metoda de citire este getChoice()
        Choice alegere_calculator = c_calculator.getChoice(); // Presupunem că metoda de citire este getChoice()

        // 2. Afișăm alegerile
        std::cout << "Tu ai ales ";
        switch (alegere_jucator) {
        case ROCK: std::cout << "Piatra"; break;
        case PAPER: std::cout << "Hartie"; break;
        case SCISSORS: std::cout << "Foarfeca"; break;
        }

        std::cout << ", Calculatorul a ales ";
        switch (alegere_calculator) {
        case ROCK: std::cout << "Piatra"; break;
        case PAPER: std::cout << "Hartie"; break;
        case SCISSORS: std::cout << "Foarfeca"; break;
        }
        std::cout << " - ";

        // 3. Determinăm rezultatul (Logică Rock, Paper, Scissors)
        if (alegere_jucator == alegere_calculator) {
            std::cout << "Egalitate!\n";
        }
        // Verificăm condițiile de câștig pentru Jucător
        else if (
            (alegere_jucator == ROCK && alegere_calculator == SCISSORS) ||
            (alegere_jucator == PAPER && alegere_calculator == ROCK) ||
            (alegere_jucator == SCISSORS && alegere_calculator == PAPER)
            ) {
            std::cout << "Ai câștigat!\n";
        }
        // Dacă nu e egalitate și nu e câștig, e pierdere
        else {
            std::cout << "Calculatorul a câștigat!\n";
        }
        std::cout << "\n"; // Adăugăm o linie nouă pentru aspect
    }
};