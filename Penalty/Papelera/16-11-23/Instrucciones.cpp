#include "Instrucciones.h"

Instrucciones::Instrucciones() {
    _texture.loadFromFile("imagenes/instrucciones.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    _sprite.setPosition(600, 300);
    _sprite.setScale(0.6, 0.6);
}

void Instrucciones::draw(sf::RenderWindow& window) {
    window.draw(_sprite);
}
