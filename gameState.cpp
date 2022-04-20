#include "gameState.h"

gameState::gameState(gameDataRef data) : _data(data)
{
    _player = nullptr;
}
gameState::~gameState()
{
    delete _player;
}

void gameState::init()
{
    _player = new cube(_data);
}

void gameState::handleInput()
{
    _player->updateInput();
}

void gameState::update(float dt)
{
    Event event;

    while (_data->window.pollEvent(event))
    {
        if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
            _data->window.close();
    }
}

void gameState::draw(float dt) const
{
    _data->window.clear();
    _player->draw();
    _data->window.display();
}