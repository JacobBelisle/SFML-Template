#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "state.hpp"
#include "game.h"

//TO REMOVE
#include "cube.h"

using namespace sf;

class gameState : public state
{
private:
    gameDataRef _data;

    //exemple of variable
    cube *_player;

public:
    gameState(gameDataRef data);
    ~gameState();

    void init();
    void handleInput();
    void update(float dt);

    void draw(float dt) const;
};