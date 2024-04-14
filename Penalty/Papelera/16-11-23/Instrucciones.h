#pragma once
#include <SFML/Graphics.hpp>

class Instrucciones {
private:
    sf::Sprite _sprite;
    sf::Texture _texture;

public:
    Instrucciones();
    void draw(sf::RenderWindow&);
};