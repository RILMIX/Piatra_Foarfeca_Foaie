#pragma once
#include <iostream>
#include <string>
#include "choice.hpp"
#include "player.hpp"

class HumanPlayer : public Player {
public:
    std::string name;
    Choice choice;
	
	HumanPlayer(); // Default constructor
	HumanPlayer(const std::string& name, Choice choice); // Parameterized constructor
	HumanPlayer(const HumanPlayer& other); // Copy constructor
	HumanPlayer& operator=(const HumanPlayer& other); // Copy assignment operator

	bool operator==(const HumanPlayer& other) const; // Equality operator
	bool operator!=(const HumanPlayer& other) const; // Inequality operator
	bool operator<(const HumanPlayer& other) const; // Less-than operator
	bool operator>(const HumanPlayer& other) const; // Greater-than operator

	friend std::istream& operator>>(std::istream& is, HumanPlayer& player); // Input stream operator
	friend std::ostream& operator<<(std::ostream& os, const HumanPlayer& player); // Output stream operator

	void makeChoice(); // Prompts the user to make a choice
	Choice getChoice() const; // Returns the player's choice
};