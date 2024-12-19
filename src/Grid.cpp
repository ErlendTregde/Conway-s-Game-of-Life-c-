//
// Created by erlen on 19.12.2024.
//

#include <iostream>

#include <SFML/Graphics.hpp>

#include "../include/Grid.h"

#include <cstdlib>
#include <ctime>

Grid::Grid(int width, int height) : width(width), height(height), grid(height, std::vector<bool>(width, false)) {}

void Grid::update() {
    std::vector<std::vector<bool>> nextGrid = grid;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = countNeighbors(x, y);
            if (grid[y][x]) {
                nextGrid[y][x] = (neighbors == 2 || neighbors == 3);
            } else {
                nextGrid[y][x] = (neighbors == 3);
            }
        }
    }

    grid = nextGrid;
}

bool Grid::isAlive(int x, int y) const {
    return grid[y][x];
}

void Grid::setAlive(int x, int y, bool alive) {
    grid[y][x] = alive;
}

int Grid::getWidth() const {
    return width;
}

int Grid::getHeight() const {
    return height;
}

const std::vector<std::vector<bool>>& Grid::getGrid() const {
    return grid;
}

int Grid::countNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx >= 0 && nx < width && ny >= 0 && ny < height && grid[ny][nx]) {
                ++count;
            }
        }
    }
    return count;
}

void Grid::randomize(double aliveProbability) {
    std::srand(static_cast<unsigned>(std::time(0)));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = (static_cast<double>(std::rand()) / RAND_MAX) < aliveProbability;
        }
    }
}
