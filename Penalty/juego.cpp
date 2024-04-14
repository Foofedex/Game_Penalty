#include "juego.h"

void Juego::jugar(sf::RenderWindow& window, NOMBRE &name) {
    if (!GameOver && !Winner) {

        window.clear();

        portero.desplazamientoArquero();
        portero.atajada();
        portero.reiniciarDisparo();
        marcador_de_goles.cDisparos(contadorDisparos);
        balon.reiniciarDisparo();
        balon.disparo();
        marcador_de_goles.Puntaje();

        if (balon.verificarGol()) {
                marcador_de_goles.anotacion();
        }

        if (balon.getContadorReinicio() == 119) {
            marcador_de_goles.setAnotado(false);
            contadorDisparos++;
            cout << contadorDisparos << endl;
        }

        nuevaCancha.draw(window);
        portero.draw(window);
        balon.draw(window);
        marcador_de_goles.draw(window);
        name.draw(window);
       
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::I))
        {
            instrucc.draw(window);

        }

        if (contadorDisparos==10) {
            if (marcador_de_goles.getGolesAnotados() > 5)
            {
                cout << "WINNER";
                Winner = true;
            }
            else {
                cout << "GAME OVER";
                GameOver = true;
                contadorDisparos = 0;
                marcador_de_goles.setGolesAnotados(0);
            }
        }
    }

    ///guarda el registro
    if ((Winner) && !estadistic.getBanderaGuardado()) {
        estadistic.guardar(name.getCadenaJugadorArchivo(), marcador_de_goles.getGolesAnotados(), contadorDisparos);
        estadistic.setBanderaGuardado(true);
        guardarPartida.grabarRegistro(estadistic);
    }


        if (GameOver) {

              PerdioDraw(window);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                GameOver = false;
                estadistic.setBanderaGuardado(false);
            }
        }

        if (Winner) {
              GanoDraw(window);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

                     Winner = false;
                     estadistic.setBanderaGuardado(false);

                    contadorDisparos = 0;
                    marcador_de_goles.setGolesAnotados(0);
            }

        }
    
}

