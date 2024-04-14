#pragma once
#include <cstring>
class NOMBRE
{
private:

    sf::Event event;
    sf::Text nombreJugador;
    sf::String cadenaJugador = " ";
    char cadenaJugadorArchivo[30];
    sf::Font font;
    bool nombreIngreso = true;
public:
    NOMBRE() {
        font.loadFromFile("dogica.ttf");
        nombreJugador.setFont(font);
        nombreJugador.setCharacterSize(30);
        nombreJugador.setFillColor(sf::Color::White);
        nombreJugador.setPosition(0, 110);
        nombreJugador.setString("INGRESE NOMBRE: \n \n  (PRESIONE  ENTER AL FINALIZAR)");

    }

    string getCadenaJugador() {
        return cadenaJugador;
    }
    const char *getCadenaJugadorArchivo() {
        strcpy_s(cadenaJugadorArchivo, cadenaJugador.toAnsiString().c_str());
        return cadenaJugadorArchivo;
    }

    void setNombreingreso(bool n) {
        nombreIngreso = n;
    }
    bool getNombreIngreso() {
        return nombreIngreso;
    }
    void carga(sf::RenderWindow& window) {


        while (window.pollEvent(event) && nombreIngreso) {


            if (event.type == sf::Event::TextEntered) {

                if (event.text.unicode < 256)
                {

                    if (event.text.unicode == 8 && cadenaJugador.getSize() > 0) {
                        cadenaJugador.erase(cadenaJugador.getSize() - 1, 1);
                    }
                    else
                    {
                        cadenaJugador += static_cast<char>(event.text.unicode);
                    }
                    nombreJugador.setString("JUGADOR: " + cadenaJugador);


                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && nombreJugador.getString().getSize() > 0)
            {
                nombreIngreso = false;
            }


        }
     draw(window);
    }

    void draw(sf::RenderWindow& window) {
        window.draw(nombreJugador);

    }
    
};