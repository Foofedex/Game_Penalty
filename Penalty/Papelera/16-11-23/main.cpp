#include <SFML/Graphics.hpp>
#include "Arquero.h"
#include "Cancha.h"
#include "Pelota.h"
#include "Jugador.h"
#include "Instrucciones.h"

int main()
{
    //resolucion
    sf::RenderWindow window(sf::VideoMode(1200, 800), "FullBall Soccer");
    window.setFramerateLimit(60);

    Arquero portero;
    Jugador pateador;
    Cancha nuevaCancha;
    Pelota balon;
    Instrucciones instrucc;

    float auxiliar2 = 0.0;

    //Game Loop (Update del juego)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        portero.movimientoAleatorioArquero();
        portero.getPosicionObjeto();
        //portero.movimientoTecladoArquero();
        //portero.desplazamientoArquero();
        balon.reiniciarDisparo();
        balon.disparo();

        /*if (balon.Collision(portero)) {
            /*Colocar accion resultante de que el arquero ataje la pelota
        }*/

        window.clear();

        nuevaCancha.draw(window);
        portero.draw(window);
        balon.draw(window);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
            instrucc.draw(window);
        }

        window.display();
    }

    //liberacion del juego
    return 0;
}
