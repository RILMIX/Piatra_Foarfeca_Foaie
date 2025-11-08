#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Choice.hpp"
#include "Player.hpp"
#include "Computer.hpp"
#include "Engine.hpp"

int main() {
    std::srand(std::time(nullptr));

    Player human;
    Computer bot;
    Engine joc(human, bot);

    joc.run();

    Player::showSTLDemos();
    Player::showSmartPointers();

    return 0;
}