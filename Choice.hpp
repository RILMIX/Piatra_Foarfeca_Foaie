#pragma once

#include <ostream>

enum class Choice { Rock, Paper, Scissors };

std::ostream& operator<<(std::ostream& os, const Choice& choice);