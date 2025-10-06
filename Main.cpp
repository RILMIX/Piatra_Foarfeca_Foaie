#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Choice.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "Engine.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    Player human;
    Computer bot;
    Engine game(human, bot);

    std::cout << "=== Bine ai venit la jocul Piatra - Hartie - Foarfeca! ===\n";
    game.run();

    std::cout << "\nMultumim ct ai jucat!\n";
    return 0;
}
