#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/Game.h"

int main() {

    const int gridWidth = 50;
    const int gridHeight = 50;
    const int cellSize = 10;

    Game game(gridWidth, gridHeight, cellSize);
    game.run();

    return 0;
}
