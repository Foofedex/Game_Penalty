
#pragma once
#include "SFML/Graphics.hpp"
#include "Collisionable.h"
#include "pelota.h"

class Arquero 
{
    int _velocidad = 5;
    sf::Sprite Sprite_Arquero;
    sf::Texture Texture_Arquero;
    sf::Vector2f movimientoAleatorio;
    sf::Vector2f direccionMovimientoArquero;
    const int POS_INICIAL_ARQUERO_Y = 290;
    const int POS_INICIAL_ARQUERO_X = 600;
    float posicionArqX;
    float posicionArqY;
    //=============== FRAME ARQUERO ================== //
    int frame_horizontal = 0;
    int frame_vertical = 0;
    int frame_ancho = 100; // Ancho de cada frame
    int frame_alto = 85; // Alto de cada frame
    sf::IntRect rect_movimiento_arquero;
    int auxContador = 0;

public:
    Arquero();
    void desplazamientoArquero();
    void movimientoAleatorioArquero();
    void movimientoTecladoArquero();
    void getPosicionObjeto();
    void draw(sf::RenderWindow&);
    void funcionNombre();
};