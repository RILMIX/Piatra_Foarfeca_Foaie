#include "Player.hpp"
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include <string> // Adăugată, deși putea fi în .hpp, e utilă pentru operații cu string

// --- CONSTRUCTORI ȘI OPERATORI ---

// Constructor implicit (fără nume, Piatra ca alegere implicită)
Player::Player() : name("Anonim"), choice(ROCK) {}

// Constructor cu parametri
Player::Player(const std::string& nume, Choice alegere)
    : name(nume), choice(alegere) {
}

// Constructor de copiere
Player::Player(const Player& other)
    : name(other.name), choice(other.choice) {
}

// Operator de atribuire (Assignment Operator)
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        choice = other.choice;
    }
    return *this;
}

// Operator de egalitate (necesar pentru find_if)
bool Player::operator==(const Player& other) const {
    return name == other.name && choice == other.choice;
}

// Operator de inegalitate
bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

// Operator "mai mic" (necesar pentru std::sort)
bool Player::operator<(const Player& other) const {
    // Sortează în primul rând după nume. Dacă numele sunt egale, sortează după alegere.
    return name < other.name ||
        (name == other.name && static_cast<int>(choice) < static_cast<int>(other.choice));
}

// Operator "mai mare"
bool Player::operator>(const Player& other) const {
    return other < *this;
}

// --- FLUXURI I/O (std::istream și std::ostream) ---

// Operator de citire (folosit pentru cin >> player)
std::istream& operator>>(std::istream& is, Player& player) {
    std::cout << "Introdu numele jucatorului: ";
    // Folosim is >> player.name, nu cin, pentru a fi generic
    if