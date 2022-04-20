#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "game.h"

using namespace sf;

class cube
{
private:
    gameDataRef _data;

    RectangleShape _shape;

    float _movementSpeed;

public:
    cube(gameDataRef data);
    ~cube();

    void updateInput();

    void draw()const;
};