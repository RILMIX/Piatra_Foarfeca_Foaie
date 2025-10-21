#include "computer.hpp"
#include "choice.hpp"
#include <cstdlib>
#include <ctime>

void Computer::pick() {
    std::srand(std::time(nullptr));
    opt = static_cast<Choice>(std::rand() % 3);
}

Choice Computer::get() const {
    return opt;
}
