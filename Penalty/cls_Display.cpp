#include "cls_Display.h"
#include <iostream>

using namespace std;

/// setea la cantidad de goles en sf text
void cls_Display::Puntaje()
{
    font.loadFromFile("dogica.ttf");
    gol.setFont(font);
    
    gol.setString("Goles: " + to_string(goles));
    
}


/// dibuja los goles y la cantidad de tiros y el nombre del jugador

void cls_Display::draw(sf::RenderWindow& window)
{
    window.draw(gol);
    window.draw(cTiros);
    window.draw(nombreMostrar);
 }


/// ejecuta la funcion de set volver, la dibuja y modifica la bandera
bool  cls_Display::botonVolver(sf::RenderWindow& window) {
    window.draw(volver);
    font.loadFromFile("dogica.ttf");
    volver.setFont(font);
    volver.setPosition(1000, 0);
    volver.setString("VOLVER");

    FuncionVolvere(window);

    if (banderaVolver) {

        return true;

    }
    
        return false;
    
  
}


/// dibuja el boton volver y cambia el color
void cls_Display::FuncionVolvere(sf::RenderWindow& window)
{

    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    if (volver.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        volver.setFillColor(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            // El ratón está sobre el botón

            banderaVolver =true;
        }
    }
    else {
        // El ratón no está sobre el botón
        volver.setFillColor(sf::Color::White);
    }
}

/// cuenta los goles segun bandera anotado
void cls_Display::anotacion()
{
    Pelota balon;

    if (!anotado)
    {
      
        goles++;
        anotado = true;

    }
    
}



/// setea la cantidad de disparos
void cls_Display::cDisparos(int a)
{
    cTiros.setFont(font);
    cTiros.setPosition(0, 50);
    cTiros.setString("DISPAROS : " + to_string(a) );
   
}

