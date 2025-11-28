#pragma once

#include <iostream>
#include <string>
#include <memory>    // Pentru demo Smart Pointers
#include <vector>    // Pentru demo STL
#include <algorithm> // Pentru demo STL
#include "Choice.hpp" // Definiția pentru enum class Choice

class Player {
public:
    // Preluat de la prieten: variabila este 'choice' și este publică.
    std::string name;
    Choice choice;

    // --- Constructorii și Operatorii ---
    Player();
    Player(const std::string& name, Choice choice);
    Player(const Player& other);
    Player& operator=(const Player& other);

    // Operatori de comparație (necesari pentru sortare/căutare STL)
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    bool operator<(const Player& other) const;
    bool operator>(const Player& other) const;

    // Operatori I/O (prieteni)
    friend std::istream& operator>>(std::istream& is, Player& player);
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    // --- Metode de Joc (Preluat de la prieten) ---
    void makeChoice(); // Metodă pentru a face alegerea
    Choice getChoice() const; // Metodă pentru a returna alegerea

    // --- Funcții Statice pentru Demonstrații (Preluat din codul dumneavoastră și redenumite) ---
    static void demoSTLContainerAndAlgorithms();
    static void demoSmartPointers();
};