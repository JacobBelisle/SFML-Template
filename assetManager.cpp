#include "assetManager.h"

void assetManager::loadTexture(string name, string fileName)
{
    Texture tex;
    if (tex.loadFromFile(fileName))
        _textures[name] = tex;
}

Texture &assetManager::getTexture(string name)
{
    return _textures.at(name);
}

void assetManager::loadFont(string name, string fileName)
{
    Font fon;
    if (fon.loadFromFile(fileName))
        _fonts[name] = fon;
}

Font &assetManager::getFont(string name)
{
    return _fonts.at(name);
}