#include "Player.hpp"
#include <limits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory> 

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
void Player::showSTLDemos() { 
    std::vector<Player> players = {
        Player("Marius", Choice::ROCK),
        Player("Andrei", Choice::PAPER),
        Player("Ionut", Choice::SCISSORS)
    };

    std::sort(players.begin(), players.end());

    std::cout << "\n--- Demo STL (Jucatori sortati dupa nume) ---\n";
    for (const auto& p : players) {
        std::cout << p << std::endl;
    }
    auto it = std::find_if(players.begin(), players.end(),
        [](const Player& p) { return p.name == "Marius"; });
    if (it != players.end()) {
        std::cout << "Jucator gasit: " << *it << "\n";
    }
    std::cout << "------------------------------------------\n";
}

void Player::showSmartPointers() {
    std::shared_ptr<Player> p1 = std::make_shared<Player>("Elena", Choice::PAPER);
    std::shared_ptr<Player> p2 = std::make_shared<Player>("Alex", Choice::SCISSORS);

    std::vector<std::shared_ptr<Player>> playerPtrs = { p1, p2 };

    std::cout << "\n--- Demo Smart Pointers (shared_ptr) ---\n";
    for (const auto& ptr : playerPtrs) {
        std::cout << *ptr << "\n";
    }
    std::cout << "--------------------------------------\n";
}