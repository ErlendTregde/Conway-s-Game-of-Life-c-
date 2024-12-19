//
// Created by erlen on 19.12.2024.
//
#include "../include/Renderer.h"

Renderer::Renderer(int width, int height, int cellSize)
        : window(sf::VideoMode(width * cellSize, height * cellSize), "Conway's Game of Life"),
          cellSize(cellSize) {}

void Renderer::render(const Grid& grid) {
    window.clear(sf::Color::Black);

    for (int y = 0; y < grid.getHeight(); ++y) {
        for (int x = 0; x < grid.getWidth(); ++x) {
            if (grid.isAlive(x, y)) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(x * cellSize, y * cellSize);
                cell.setFillColor(sf::Color::White);
                window.draw(cell);
            }
        }
    }

    window.display();
}

bool Renderer::isWindowOpen() const {
    return window.isOpen();
}

void Renderer::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
    }
}
