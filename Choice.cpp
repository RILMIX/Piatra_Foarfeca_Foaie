#include "Choice.hpp"

std::ostream& operator<<(std::ostream& os, const Choice& choice) {
    switch (choice) {
    case Choice::Rock: os << "Rock"; break;
    case Choice::Paper: os << "Paper"; break;
    case Choice::Scissors: os << "Scissors"; break;
    }
    return os;
}