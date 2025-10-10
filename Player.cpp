#include "Player.hpp"

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
    case ROCK:     std::cout << "Piatra"; break;
    case PAPER:    std::cout << "Hartie"; break;
    case SCISSORS: std::cout << "Foarfeca"; break;
    }
    std::cout << "\n";
}
