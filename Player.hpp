#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include "Choice.hpp"

class Player {
public:
    std::string name;
    Choice choice;

    Player(const std::string& n = "Unknown", Choice c = Choice::None)
        : name(n), choice(c) {
    }

    bool operator==(const Player& o) const { return name == o.name && choice == o.choice; }
    bool operator!=(const Player& o) const { return !(*this == o); }
    bool operator<(const Player& o)  const { return name < o.name; }
    bool operator>(const Player& o)  const { return name > o.name; }

    friend std::istream& operator>>(std::istream& is, Player& p) {
        std::cout << "Name: ";
        is >> p.name;
        std::cout << "Choice (0/1/2): ";
        int c; is >> c;
        p.choice = static_cast<Choice>(c);
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Player& p) {
        return os << "Player: " << p.name << " | Choice: " << (int)p.choice;
    }
    virtual void makeChoice() = 0;
    virtual Choice getChoice() const = 0;

    static void demoSTLContainer() {
        std::vector<int> v = { 5,2,4,1 };
        std::sort(v.begin(), v.end());
        for (int x : v) std::cout << x << " ";
        std::cout << "\n";
    }

    static void demoSmartPtr() {
        auto ptr = std::make_shared<int>(10);
        std::cout << "SmartPtr: " << *ptr << "\n";
    }

    virtual ~Player() = default;
};
