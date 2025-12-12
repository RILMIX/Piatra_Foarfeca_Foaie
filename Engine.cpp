#include "Engine.hpp"
#include "AsciiRenderer.hpp"
#include <iostream>

static ImageType s_assets[] = {
    FromFile("resources/rock.txt"),
    FromFile("resources/paper.txt"),
    FromFile("resources/scissors.txt")
};

void Engine::start() {
    intro();
    while (true) {
        showScoreboard();
        obtainSelections();
        drawSelections();
        analyzeOutcome();
    }
}

void Engine::intro() const {
    std::cout << "\n==== ROCK • PAPER • SCISSORS ====\n";
    std::cout << "  0 = Rock\n  1 = Paper\n  2 = Scissors\n";
    std::cout << "Press Ctrl+C at any time to exit.\n\n";
}

void Engine::obtainSelections() {
    player.makeChoice();
    opponent.makeChoice();
}

void Engine::drawSelections() const {
    AsciiRenderer drawer;
    const int left = static_cast<int>(player.getChoice());
    const int right = static_cast<int>(opponent.getChoice());
    ImageType leftImg = s_assets[left];
    ImageType rightImg = FlipImage(s_assets[right]);
    ImageType combined = MergeImages(leftImg, rightImg);
    drawer.DrawImage(combined);
    std::cout << "Player picked: " << player.getChoice()
        << " | Computer picked: " << opponent.getChoice()
        << " → ";
}

void Engine::analyzeOutcome() {
    ++totalRounds;
    Choice c1 = player.getChoice();
    Choice c2 = opponent.getChoice();
    if (c1 == c2) {
        ++draws;
        std::cout << "Draw!\n";
        return;
    }
    bool pWins = (c1 == Choice::Rock && c2 == Choice::Scissors) ||
        (c1 == Choice::Paper && c2 == Choice::Rock) ||
        (c1 == Choice::Scissors && c2 == Choice::Paper);
    if (pWins) {
        ++winsPlayer;
        std::cout << "Player wins the round!\n";
    }
    else {
        ++winsComputer;
        std::cout << "Computer wins the round!\n";
    }
}

void Engine::showScoreboard() const {
    std::cout << "\n------ SCOREBOARD ------\n";
    std::cout << "Rounds:    " << totalRounds << "\n";
    std::cout << "You:       " << winsPlayer << "\n";
    std::cout << "Computer:  " << winsComputer << "\n";
    std::cout << "Draws:     " << draws << "\n";
    std::cout << "-------------------------\n\n";
}