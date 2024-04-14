
#include <stdio.h>
#pragma once

void Ejecutar()
{
    ///inicializa la ventana
    sf::RenderWindow window(sf::VideoMode(1200, 800), "FullBall Soccer");
    window.setFramerateLimit(60);
    ///creo las clases que se van a usar
    Menu menu;
    cls_Display volver;
    NOMBRE name;
    Juego juego(window);
    Creditos credito;
    int variableAnalizar = 0;
      
    ///game loop (update del juego)
    while (window.isOpen())
    {
        window.clear();

        ///poner la badera true para volver al menu
        /// banderaVolver es un atributo bool de la clase cls_display cuando apretas volver pasa true
       if (volver.getBanderaVolver()) {
            variableAnalizar = 0;
            volver.setBanderaVolver(false);
       }

        switch (variableAnalizar)
        {
        case 0:
        {
            menu.draw(window);

            if (menu.getSeleccion() == 1) {
                variableAnalizar = 1;
                menu.setSeleccion(0);

                juego.sonidoAmbient();
            }
            if (menu.getSeleccion() == 2) {
                variableAnalizar = 2;
                menu.setSeleccion(0);
            }
            if (menu.getSeleccion() == 3) {
                variableAnalizar = 3;
                menu.setSeleccion(0);
            }
            if (menu.getSeleccion() == 4) {
                variableAnalizar = 4;
                menu.setSeleccion(0);
            }

        }
        break;

        case 1:
        {
            name.carga(window);

            if (!name.getNombreIngreso()) {
                juego.jugar(window, name);
            }

            volver.botonVolver(window);

            if (volver.botonVolver(window) == true) {
                juego.sonidoAmbientStop();
             Ejecutar(); 
            }
            if (juego.getbanderaLocutorEntrada() == true) {
                juego.sonidoLocutor();
                juego.setbanderaLocutorEntrada(false);
            }
        }

        break;
        case 2:
        {
              BasedeEstadisticas cargamatriz;
               cargamatriz.CargaMatrizdePuntos(window);
                volver.botonVolver(window);
         
        }
        break;

        case 3:
        {
            credito.draw(window);
            volver.botonVolver(window);
         }
        break;

        case 4:
        {
          exit(1);
        }
        break;
                
        }

        window.display();
    }
};