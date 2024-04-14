
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
    //=============== ARQUERO-FRAME ================== //
    int frame_horizontal = 2;
    int frame_vertical = 0;
    int frame_ancho = 100; // Ancho de cada frame
    int frame_alto = 85; // Alto de cada frame
    sf::IntRect rect_movimiento_arquero;


public:
    Arquero();
    void desplazamientoArquero();
    void movimientoTecladoArquero();
    void getPosicionObjeto();
    void draw(sf::RenderWindow&);
    //sf::FloatRect getBounds() const override;
};
 