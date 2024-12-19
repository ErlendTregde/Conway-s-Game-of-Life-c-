//
// Created by erlen on 19.12.2024.
//

#ifndef GAMEOFLIFE_GRID_H
#define GAMEOFLIFE_GRID_H

#include <vector>

class Grid {
public:
    Grid(int width, int height);
    void randomize(double aliveProbability = 0.3);
    void update();
    bool isAlive(int x, int y) const;
    void setAlive(int x, int y, bool alive);

    int getWidth() const;
    int getHeight() const;
    const std::vector<std::vector<bool>>& getGrid() const;

private:
    int width, height;
    std::vector<std::vector<bool>> grid;

    int countNeighbors(int x, int y) const;
};

#endif //GAMEOFLIFE_GRID_H
