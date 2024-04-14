#include "menu.h"

    ///setea opciones de menu con el contructor por defecto
Menu::Menu()
{
    Texture_Menu.loadFromFile("imagenes/menu2.png");
    Sprite_Menu.setTexture(Texture_Menu);

    Fuente.loadFromFile("dogica.ttf");
    BOTON1.setFont(Fuente);
    BOTON1.setString("JUGAR");
    BOTON1.setOrigin(BOTON1.getGlobalBounds().width / 2, BOTON1.getGlobalBounds().height / 2);
    BOTON1.setPosition(585, 335);

    BOTON2.setFont(Fuente);
    BOTON2.setString("ESTADISTICAS");
    BOTON2.setOrigin(BOTON2.getGlobalBounds().width / 2, BOTON2.getGlobalBounds().height / 2);
    BOTON2.setPosition(585, 370);

    BOTON3.setFont(Fuente);
    BOTON3.setString("CREDITOS");
    BOTON3.setOrigin(BOTON3.getGlobalBounds().width / 2, BOTON3.getGlobalBounds().height / 2);
    BOTON3.setPosition(585, 405);

    BOTON4.setFont(Fuente);
    BOTON4.setString("SALIR");
    BOTON4.setOrigin(BOTON4.getGlobalBounds().width / 2, BOTON4.getGlobalBounds().height / 2);
    BOTON4.setPosition(585, 440);


  

}

///dibuja menu y opciones
void Menu::draw(sf::RenderWindow& window)
{
    window.draw(Sprite_Menu);
    window.draw(BOTON1);
    window.draw(BOTON2);
    window.draw(BOTON3);
    window.draw(BOTON4);
    SelecOpcion(window);
    
 
}

void Menu::SelecOpcion(sf::RenderWindow& window) {
    
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    
    if (BOTON1.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
            BOTON1.setFillColor(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            /// jugar
            setSeleccion(1);
        }
    }
    else {
        // El ratón no está sobre el botón
        BOTON1.setFillColor(sf::Color::White);
    }

    if (BOTON2.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
      BOTON2.setFillColor(sf::Color::Green);
          if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
              // estadisticas
              setSeleccion(2);
          }
    }
    else {
      // El ratón no está sobre el botón
     BOTON2.setFillColor(sf::Color::White);
    }
   
    

    if (BOTON3.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        BOTON3.setFillColor(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            // credito
            setSeleccion(3);
       
        }
    }
    else {
        // El ratón no está sobre el botón
        BOTON3.setFillColor(sf::Color::White);
    }

    if (BOTON4.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosition))) {
        BOTON4.setFillColor(sf::Color::Green);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            // El ratón está sobre el botón
            setSeleccion(4);
        }
    }
    else {
        // El ratón no está sobre el botón
        BOTON4.setFillColor(sf::Color::White);
    }
}


    

