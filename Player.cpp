#include "Player.hpp"
#include <limits>
#include <iostream>

Player::Player() : name(""), selected(Choice::ROCK) {}

Player::Player(const std::string& nume, Choice alegere)
    : name(nume), selected(alegere) {
}

Player::Player(const Player& other)
    : name(other.name), selected(other.selected) {
}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        selected = other.selected;
    }
    return *this;
}

bool Player::operator==(const Player& other) const {
    return name == other.name && selected == other.selected;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

bool Player::operator<(const Player& other) const {
    return name < other.name ||
        (name == other.name && static_cast<int>(selected) < static_cast<int>(other.selected));
}

bool Player::operator>(const Player& other) const {
    return other < *this;
}

std::istream& operator>>(std::istream& is, Player& player) {
    std::cout << "Introdu numele jucatorului: ";
    is >> player.name;

    int input;
    do {
        std::cout << "Introdu 0 (Piatra), 1 (Hartie), 2 (Foarfeca): ";
        is >> input;
        if (is.fail() || !(input >= 0 && input <= 2)) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Valoare invalida. Incearca din nou.\n";
        }
        else {
            player.selected = static_cast<Choice>(input);
            break;
        }
    } while (true);

    return is;
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Jucator: " << player.name << ", Alegere: ";
    switch (player.selected) {
    case ROCK: os << "Piatra"; break;
    case PAPER: os << "Hartie"; break;
    case SCISSORS: os << "Foarfeca"; break;
    }
    return os;
}

void Player::choose() {
    int value = -1;
    while (true) {
        std::cout << "Alege o optiune: 0 = Piatra, 1 = Hartie, 2 = Foarfeca -> ";
        std::cin >> value;

        if (std::cin.fail() || value < 0 || value > 2) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input invalid! Incearca din nou.\n";
        }
        else {
            selected = static_cast<Choice>(value);
            break;
        }
    }
}

Choice Player::getSelected() const {
    return selected;
}

void Player::showChoice() const {
    std::cout << "Jucatorul a ales: ";
    switch (selected) {
    case ROCK: std::cout << "Piatra"; break;
    case PAPER: std::cout << "Hartie"; break;
    case SCISSORS: std::cout << "Foarfeca"; break;
    }
    std::cout << "\n";
}
