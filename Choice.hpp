#pragma once

#include <iostream>

enum class Choice 
{ 
	Rock = 0, 
	Paper = 1, 
	Scissors = 2 
};

std::ostream& operator <<(std::ostream& os, const Choice& choice);