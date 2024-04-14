#include "Cancha.h"
Cancha::Cancha()
{
    Texture_Cancha.loadFromFile("imagenes/arco.jpeg");
    Sprite_Cancha.setTexture(Texture_Cancha);
}

void Cancha::draw(sf::RenderWindow &window)
{
    window.draw(Sprite_Cancha);
}