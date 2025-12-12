#include "HumanPlayer.hpp"
#include "Computer.hpp"
#include "Engine.hpp"

int main() {
    HumanPlayer human;
    Computer computer;
    Engine engine(human, computer);
    engine.start();
    return 0;
}