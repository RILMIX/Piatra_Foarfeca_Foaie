#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Choice.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "Engine.hpp"

int main() {
    // Inițializează generatorul de numere aleatoare
    std::srand(std::time(nullptr));

    // Versiunea ta, dar echivalenta funcțional cu prietenul:
    std::unique_ptr<Player> player = std::make_unique<Player>();
    std::unique_ptr<Computer> computer = std::make_unique<Computer>();

    // Engine primește unique_ptr pentru a permite polimorfism și arhitectura corectă
    Engine engine(std::move(player), std::move(computer));

    engine.run();

    return 0;
}
