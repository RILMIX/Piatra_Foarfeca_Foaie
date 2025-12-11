#include "Player.hpp"
#include <iostream>
#include <limits>
#include <string>

// --- CONSTRUCTORS AND OPERATORS ---

Player::Player() : name(""), choice(Choice::ROCK) {}

Player::Player(const std::string& name, Choice choice) : name(name), choice(choice) {}

Player::Player(const Player& other) : name(other.name), choice(other.choice) {}

Player& Player::operator=(const Player& other) {
    if (this != &other) {
        name = other.name;
        choice = other.choice;
    }
    return *this;
}

bool Player::operator==(const Player& other) const {
    return name == other.name && choice == other.choice;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

bool Player::operator<(const Player& other) const {
    return name < other.name || (name == other.name && static_cast<int>(choice) < static_cast<int>(other.choice));
}

bool Player::operator>(const Player& other) const {
    return other < *this;
}

// --- I/O STREAM OPERATORS ---

// Operator for reading Player data from istream
std::istream& operator>>(std::istream& is, Player& player) {
    std::cout << "Enter player name: ";
    if (!(is >> player.name)) return is;

    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        is >> input;

        if (is.fail() || !(input >= 0 && input <= 2)) {
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            player.choice = static_cast<Choice>(input);
            break;
        }
    } while (true);

    return is;
}

// Operator for writing Player data to ostream
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.name << ", Choice: ";
    switch (player.choice) {
    case Choice::ROCK: os << "Rock"; break;
    case Choice::PAPER: os << "Paper"; break;
    case Choice::SCISSORS: os << "Scissors"; break;
    }
    return os;
}

// --- CORE GAME METHODS ---

// Allows the player to input their choice
void Player::makeChoice() {
    int input;
    do {
        std::cout << "Enter 0 (Rock), 1 (Paper), or 2 (Scissors): ";
        std::cin >> input;

        if (std::cin.fail() || !(input >= 0 && input <= 2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again." << std::endl;
        }
        else {
            choice = static_cast<Choice>(input);
            break;
        }
    } while (true);
}

// Returns the player's current choice
Choice Player::getChoice() const {
    return choice;
}

// Note: Static demo functions (demoSTLContainerAndAlgorithms/demoSmartPointers) 
// have been removed to strictly match the provided friend's implementation file.