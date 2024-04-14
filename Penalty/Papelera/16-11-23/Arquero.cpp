
#include "Arquero.h"
#include "pelota.h"
#include <windows.h>
Arquero::Arquero() {
    Texture_Arquero.loadFromFile("imagenes/nuevoArqueroRedimensionado.png");
    Sprite_Arquero.setTexture(Texture_Arquero);
    //velocidad de movimiento
    movimientoAleatorio = { 2,2 };
    
  
    Sprite_Arquero.setPosition(Sprite_Arquero.getPosition().x, 600);
    Sprite_Arquero.setPosition(Sprite_Arquero.getPosition().y, 290);
    
}



void Arquero::desplazamientoArquero()
{
    float posicionPelotaX = 850;
    float posicionPelotaY = 230;
    float velocidad = 0.005;

    /*CORREGIR: NO SE DETIENE - HAY QUE MODIFICAR EL CONDICIONAL*/

     if (posicionArqX != posicionPelotaX && posicionArqY != posicionPelotaY)
     {
       direccionMovimientoArquero = { (posicionPelotaX - posicionArqX) * velocidad,(posicionPelotaY - posicionArqY) * velocidad };
        Sprite_Arquero.move(direccionMovimientoArquero);
     }


}

//Pelota balon2;

void Arquero::movimientoAleatorioArquero() {

    Pelota balon;
    cout << "posx: " << balon.getPositionPelotaX() << endl;
    Sprite_Arquero.move(movimientoAleatorio);

    rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    Sprite_Arquero.setTextureRect(rect_movimiento_arquero);

    if (auxContador < 120)
    {
        auxContador++;
        
    }
    else {
        auxContador = 0;
    }
    
    //if (balon.getPositionPelotaX() < 580) {
        if (Sprite_Arquero.getPosition().x < 550 && Sprite_Arquero.getPosition().x > 450)
        {
            frame_horizontal = 0;
        }
        if (Sprite_Arquero.getPosition().x < 580 && Sprite_Arquero.getPosition().x > 550)
        {
            frame_horizontal = 1;
        }
    //}
    if (Sprite_Arquero.getPosition().x==600)
    {
        frame_horizontal = 2;
    }
    //if (balon.getPositionPelotaX() > 620) {
        if (Sprite_Arquero.getPosition().x > 620 && Sprite_Arquero.getPosition().x < 650)
        {
            frame_horizontal = 3;
        }
        if (Sprite_Arquero.getPosition().x > 650 && Sprite_Arquero.getPosition().x < 750)
        {
            frame_horizontal = 4;
        }
    //}

    //cout << "valor posicion en x pelota: " << balon.getPositionPelotaX()<<endl;

    /*
    for (int i = 0; i < 9;i++) {
        sleep_for(milliseconds(1));
        cout << "segundos: " << i << endl;
    }
    */
}

void Arquero::funcionNombre()
{
    if (frame_vertical < 5)
    {
        frame_vertical++;
    }
    else
    {
        frame_vertical == 2;
    }
};

void Arquero::movimientoTecladoArquero() {
    
    

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(0, -_velocidad);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(0, _velocidad);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        funcionNombre();
        rect_movimiento_arquero = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        Sprite_Arquero.setTextureRect(rect_movimiento_arquero);
        Sprite_Arquero.move(_velocidad, 0);
    }
    


    

}

void Arquero::getPosicionObjeto()
{


    /*Movimientos en X
    //izquierda


    if (Sprite_Arquero.getPosition().x < 100) {
        //Sprite_Arquero.setPosition(400, Sprite_Arquero.getPosition().y);
        movimientoAleatorio.x = -movimientoAleatorio.x;
    }

    /*Movimientos en Y
    //arriba
    if (Sprite_Arquero.getPosition().y <00) {
       // Sprite_Arquero.setPosition(Sprite_Arquero.getPosition().x, 290);
        movimientoAleatorio.y=-movimientoAleatorio.y;

    }
    //derecha
    if (Sprite_Arquero.getPosition().x + Sprite_Arquero.getGlobalBounds().width > 800) {
     //   Sprite_Arquero.setPosition(740, Sprite_Arquero.getPosition().y);
        movimientoAleatorio.x = -movimientoAleatorio.x;
    }
    //este es abajo
    if (Sprite_Arquero.getPosition().y + Sprite_Arquero.getGlobalBounds().height > 400) {
     //   Sprite_Arquero.setPosition(Sprite_Arquero.getPosition().x, 306);
        movimientoAleatorio.y = -movimientoAleatorio.y;

   }

*/


    if (Sprite_Arquero.getPosition().x < 400 ||
        Sprite_Arquero.getPosition().x + Sprite_Arquero.getGlobalBounds().width > 800) {
        movimientoAleatorio.x = -movimientoAleatorio.x;
    }

    /* Movimientos en Y */
    // Arriba
    if (Sprite_Arquero.getPosition().y < 280 ||
        Sprite_Arquero.getPosition().y + Sprite_Arquero.getGlobalBounds().height > 400) {
        movimientoAleatorio.y = -movimientoAleatorio.y;
    }



}

void Arquero::draw(sf::RenderWindow& window)
{
    window.draw(Sprite_Arquero);
}

