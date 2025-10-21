#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Choice.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "Engine.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // initializeaza generatorul random

    Player human;
    Computer bot;
    Engine joc(human, bot);

    joc.run();

    return 0;
}
