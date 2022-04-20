#pragma once

class state
{
public:
    virtual void init() = 0;                  //init de state
    virtual void handleInput() = 0;           //tous les input de la fenetre
    virtual void update(float delta) = 0;     //update la fenetre apres le input
    virtual void draw(float delta) const = 0; //draw la fenetrre apres le update
                                              //(delta est la difference de temps avec le frame rate)
    virtual void pause() {}                   //pause et resume le state
    virtual void resume() {}
};
