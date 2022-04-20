#include "game.h"
#include "gameState.h"
#include <time.h>
#include <stdlib.h>

game::game(int width, int height, string title)
{
    _data = make_shared<gameData>();

    _data->window.create(VideoMode(width, height), title, Style::Close | Style::Resize);

    //todo creation du premier etat de jeu (1iere fenetre)
    //*example
    _data->machine.addState(stateRef(new gameState(_data)));

    run();
}

void game::run()
{
    float newTime, frameTime, interpolation;
    float currentTime = _clock.getElapsedTime().asSeconds();
    float accumulator = 0.0f;
    while (_data->window.isOpen())
    {
        _data->machine.processStateChanges();
        //vérifie si on a des changements
        newTime = _clock.getElapsedTime().asSeconds();
        frameTime = newTime - currentTime;
        if (frameTime > 0.25f)
        { //si on dépasse le quart de seconde, on ajuste
            frameTime = 0.25f;
            //a .25 seconde pour le calcul de accumulator
        }
        currentTime = newTime; //new time devient le current time
        accumulator += frameTime;
        //accumulator accumule tous les frameTimes
        while (accumulator >= dt)
        {
            //si on dépasse le temps du frame (1/60 de seconde)
            //on vérifie les événements et on update la fenêtre
            _data->machine.getActiveState()->handleInput();
            _data->machine.getActiveState()->update(dt);
            accumulator -= dt;
            //on retire dt de l’accumulator pour l’interpolation
        }
        interpolation = accumulator / dt; //le temps d’exécution de la loop pour le draw
        _data->machine.getActiveState()->draw(interpolation);
    }
}