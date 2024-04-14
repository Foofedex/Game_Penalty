#include "Arquero.h"
#include "pelota.h"
#include <stdlib.h>
#include <time.h>


Arquero::Arquero(Pelota &pelota) : pelota(pelota)
{
    Texture_Arquero.loadFromFile("imagenes/nuevoArqueroRedimensionado.png");
    Sprite_Arquero.setTexture(Texture_Arquero);
    Sprite_Arquero.setScale(0.7, 0.7);
   
    _atajokloster.loadFromFile("nervioso.mp3");
    atajokloster.setBuffer(_atajokloster);

    
   
    //frames que va a tomar
    sf::IntRect rect_movimiento_arquero(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    Sprite_Arquero.setTextureRect(rect_movimiento_arquero);

    Sprite_Arquero.setOrigin(rect_movimiento_arquero.width / 2, rect_movimiento_arquero.height);

    Sprite_Arquero.setPosition(600, 395);
}
//probabilidad
bool ataja_o_NoAtaja(Pelota& pelota)
{
   
    int num= 1 + rand() % (10);
    bool ataja = false;
   
    int probabilidadIzquierda = 1 + rand() % (10);
    int probabilidadDerecha = 1 + rand() % (10);
    int probabilidadCentro = 1 + rand() % (10);
    cout << "probabilidadIzquierda" << probabilidadIzquierda << endl;
    cout << "probabilidadDerecha" << probabilidadDerecha << endl;
    cout << "probabilidadCentro" << probabilidadCentro << endl;

      
    if (pelota.getdireccion() == 'A' || pelota.getdireccion() == 'Q') {

        if (num <= 1)
        {
            ataja = true;
        }
        
    }
    else if (pelota.getdireccion() == 'D' || pelota.getdireccion() == 'E') {

        if (num <= 1)
        {
            ataja = true;
        }
    }
  
    else {
        if (num <= 1)
        {
            ataja = true;
        }
        
    }
   // ataja = false;
    return ataja;
}

void Arquero::atajada()
{
    float posicionArqueroX = Sprite_Arquero.getPosition().x;
    float posicionArqueroY = Sprite_Arquero.getPosition().y;
    float posicionPelotaX = pelota.getPositionPelotaX();
    float posicionPelotaY = pelota.getPositionPelotaY();
    char direccion_disparo = pelota.getdireccion();

    if (Collision(pelota))atajokloster.play();

    if (posicionPelotaX <= 580) {
        if (Collision(pelota))
        {

            frame_horizontal = 0;
            Sprite_Arquero.move(0, 0);
            pelota.setFreno();
            pelota.setPositionXY(Sprite_Arquero.getPosition().x-80, Sprite_Arquero.getPosition().y - 50);

        }
    }
    
    if (posicionPelotaX >= 620) {
        if (Collision(pelota))
        {
            frame_horizontal = 8;
            Sprite_Arquero.move(0, 0);
            pelota.setFreno();
            pelota.setPositionXY(Sprite_Arquero.getPosition().x+80, Sprite_Arquero.getPosition().y - 50);
        }
    }

    if (posicionPelotaX > 580 && posicionPelotaX < 620) {
        if (Collision(pelota))
        {
           
            frame_horizontal = 3;
            Sprite_Arquero.move(0, 0);
            pelota.setFreno();
            pelota.setPositionXY(Sprite_Arquero.getPosition().x, Sprite_Arquero.getPosition().y);

        }
       
    }
}

void Arquero::desplazamientoArquero()
{
    sf::IntRect rect_movimiento_arquero(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
    Sprite_Arquero.setOrigin(rect_movimiento_arquero.width / 2, rect_movimiento_arquero.height);

    if (pelota.getTiroEnProceso() && !seDisparo)
    {
        seDisparo = true;
        resultadoDisparo = ataja_o_NoAtaja(pelota);
       
    }

    if (pelota.getTiroEnProceso() && !pelota.getPelotaDetenida())
    {
        if ((pelota.getPositionPelotaX() < 580 && resultadoDisparo) || (!resultadoDisparo && pelota.getPositionPelotaX() > 620))
        {
            Sprite_Arquero.move(-8, 0);
        }
        else if ((pelota.getPositionPelotaX() > 620 && resultadoDisparo) || (!resultadoDisparo && pelota.getPositionPelotaX() < 580))
        {
            Sprite_Arquero.move(8, 0);
        }
        else if (pelota.getPositionPelotaX() == 600 && !resultadoDisparo)
        {
            int num;
            srand(time(NULL));
            num = 1 + rand() % (2);
            if (num == 1) { Sprite_Arquero.move(8, 0); }
            if (num == 2) { Sprite_Arquero.move(-8, 0); }

        }
    }
    
    else
    {//el del medio
        frame_horizontal = 4;
    }

    float positionX = Sprite_Arquero.getPosition().x;
    //izquierda
   
    if (positionX >= 315 && positionX < 385)
    {
      frame_horizontal = 0;
    }

    else if (positionX >= 385 && positionX < 455)
    {
        frame_horizontal = 1;
    }
    else if (positionX >= 455 && positionX < 545)
    {
        frame_horizontal = 2;
    }


    //derecha
    else if (positionX > 670 && positionX < 740)
    {
        frame_horizontal = 7;
    }
    else if (positionX > 740 && positionX < 810)
    {
        frame_horizontal = 7;
    }
    else if (positionX > 810 && positionX < 880)
    {
        frame_horizontal = 8;
    }
}

void Arquero::reiniciarDisparo()
{
    if (!pelota.getTiroEnProceso() && pelota.getPelotaDetenida() && pelota.getPositionPelotaY() != 730) {
        if (pelota.getContadorReinicio() >= 119)
        {
            seDisparo = false;
            Sprite_Arquero.setPosition(600, 390);
           
        }
    }
}

void Arquero::movimientoTecladoArquero()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(0, -_velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(0, _velocidad);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(_velocidad, 0);
    }
}

void Arquero::draw(sf::RenderWindow &window)
{
    window.draw(Sprite_Arquero);
}

sf::FloatRect Arquero::getBounds() const
{
   
     return Sprite_Arquero.getGlobalBounds();
   
};