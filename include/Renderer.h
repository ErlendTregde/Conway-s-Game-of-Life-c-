//
// Created by erlen on 19.12.2024.
//

#ifndef GAMEOFLIFE_RENDERER_H
#define GAMEOFLIFE_RENDERER_H

#include <SFML/Graphics.hpp>
#include "Grid.h"

class Renderer {
public:
    Renderer(int width, int height, int cellSize);

    void render(const Grid& grid);

    bool isWindowOpen() const;
    void handleEvents();

private:
    sf::RenderWindow window;
    int cellSize;
};


#endif //GAMEOFLIFE_RENDERER_H
