//
// Created by erlen on 19.12.2024.
//

#ifndef GAMEOFLIFE_GAME_H
#define GAMEOFLIFE_GAME_H

#include "Grid.h"
#include "Renderer.h"

class Game {
public:
    Game(int width, int height, int cellSize);

    void run();

private:
    Grid grid;
    Renderer renderer;

    bool paused;
};



#endif

