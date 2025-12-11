#include "HumanPlayer.hpp"
#include <iostream>
#include <limits>

HumanPlayer::HumanPlayer() : name(""), choice(Choice::Rock) {}
HumanPlayer::HumanPlayer(const std::string& name, Choice choice) : name(name), choice(choice) {}

HumanPlayer::HumanPlayer(const HumanPlayer& other) : name(other.name), choice(other.choice) {}

HumanPlayer& HumanPlayer::operator=(const HumanPlayer& other) {
    if (this != &other) {
        name = other.name;
        choice = other.choice;
    }
    return *this;
}

bool HumanPlayer::operator==(const HumanPlayer& other) const {
    return name == other.name && choice == other.choice;
}
bool HumanPlayer::operator!=(const HumanPlayer& other) const {
    return !(*this == other);
}
bool HumanPlayer::operator<(const HumanPlayer& other) const {
    return name < other.name || (name == other.name && static_cast<int>(choice) < static_cast<int>(other.choice));
}
bool HumanPlayer::operator>(const HumanPlayer& other) const {
    return other < *this;
}

std::istream& operator>>(std::istream& is, HumanPlayer& player) {
    std::cout << "Enter player name: ";
    is >> player.name;
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

std::ostream& operator<<(std::ostream& os, const HumanPlayer& player) {
    os << "Player: " << player.name << ", Choice: ";
    switch (player.choice) {
    case Choice::Rock: os << "Rock"; break;
    case Choice::Paper: os << "Paper"; break;
    case Choice::Scissors: os << "Scissors"; break;
    }
    return os;
}

void HumanPlayer::makeChoice() {
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

Choice HumanPlayer::getChoice() const {
    return choice;
}