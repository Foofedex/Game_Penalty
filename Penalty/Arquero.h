#pragma once
#include "Collisionable.h"
#include "pelota.h"


class Arquero : public Collisionable
{
    int _velocidad = 5;
    sf::Sprite Sprite_Arquero;
    sf::Texture Texture_Arquero;
   
    //=============== FRAME ARQUERO ================== //
    int frame_horizontal = 5;
    int frame_vertical = 0;
    int frame_ancho = 250; // Ancho de cada frame
    int frame_alto = 200;   // Alto de cada frame
    //teclado
    sf::IntRect rect_movimiento_arquero;
    bool seDisparo = false;
    bool resultadoDisparo=true;
    sf::SoundBuffer _atajokloster;
    sf::Sound atajokloster;
    Pelota &pelota;

public:
    Arquero(Pelota &pelota);
    void desplazamientoArquero();
    void movimientoTecladoArquero();
    void draw(sf::RenderWindow &);
    sf::FloatRect getBounds() const override;
    void reiniciarDisparo();
    void atajada();
   
};