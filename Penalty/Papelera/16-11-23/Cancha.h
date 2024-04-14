#pragma once
#include "SFML/Graphics.hpp"
class Cancha
{
    sf::Sprite Sprite_Cancha;
    sf::Texture Texture_Cancha;



public:

    Cancha();
    void draw(sf::RenderWindow&);

};