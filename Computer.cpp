#include "Computer.hpp"
#include <cstdlib>
#include <ctime>

void Computer::makeChoice() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
    choice = static_cast<Choice>(std::rand() % 3);
}

Choice Computer::getChoice() const {
    return choice;
}