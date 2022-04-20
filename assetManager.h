#pragma once
#include <map>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class assetManager
{
private:
    map<string, Texture> _textures;
    map<string, Font> _fonts;
    
public:
    void loadTexture(string name, string fileName);
    Texture& getTexture(string name);

    void loadFont(string name, string fileName);
    Font& getFont(string name);
};
