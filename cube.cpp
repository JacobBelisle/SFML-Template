#include "cube.h"

cube::cube(gameDataRef data) : _data(data)
{
    _movementSpeed = 8.0f;
    _shape.setFillColor(Color::White);
    _shape.setSize(Vector2f(128, 128));
    _shape.setPosition(0, 0);
}

cube::~cube() {}

void cube::updateInput()
{
    if (Keyboard::isKeyPressed(Keyboard::D))
    {
        _shape.move(_movementSpeed, 0.f);
    }
    else if (Keyboard::isKeyPressed(Keyboard::A))
    {
        _shape.move(-_movementSpeed, 0.f);
    }

    if (Keyboard::isKeyPressed(Keyboard::W))
    {
        _shape.move(0.f, -_movementSpeed);
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        _shape.move(0.f, _movementSpeed);
    }
}

void cube::draw() const
{
    _data->window.draw(_shape);
}