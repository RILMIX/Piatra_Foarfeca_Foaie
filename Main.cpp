#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Choice.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "Engine.hpp"

//comment

int main() {
    // Inițializează generatorul de numere aleatoare. Esențial pentru Computer.
    std::srand(std::time(nullptr));

    // Creează instanțele principale
    Player player;
    Computer computer;

    // Inițializează motorul jocului cu referințe la player și computer
    Engine engine(player, computer);

    // Rulează o rundă de joc
    engine.run();

    // Adaugă funcționalitățile extra din codul prietenului:
    Player::demoSTLContainerAndAlgorithms(); // Demonstrație STL
    Player::demoSmartPointers(); // Demonstrație Smart Pointers

    return 0;
}