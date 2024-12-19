//
// Created by erlen on 19.12.2024.
//

#include "../include/Game.h"
#include <thread>
#include <chrono>

Game::Game(int width, int height, int cellSize)
        : grid(width, height), renderer(width, height, cellSize), paused(false) {
    grid.randomize();
}


void Game::run() {
    while (renderer.isWindowOpen()) {
        renderer.handleEvents();

        if (!paused) {
            grid.update();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        renderer.render(grid);
    }
}
