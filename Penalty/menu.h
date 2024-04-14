#pragma once

#include "SFML/Graphics.hpp"
#include "Juego.h"
class Menu
{
private:
    sf::Sprite Sprite_Menu;
    sf::Texture Texture_Menu;
    sf::Font Fuente;
    sf::Text BOTON1;
    sf::Text BOTON2;
    sf::Text BOTON3;
    sf::Text BOTON4;
    int seleccion;
   
   
public:
    Menu();
    
    void draw(sf::RenderWindow& window);
    void SelecOpcion(sf::RenderWindow& window);
    int getSeleccion() {
        return seleccion;
             
    }
    void setSeleccion( int t) {
        this->seleccion=t;

    }


};