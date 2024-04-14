#include "pelota.h"


Pelota::Pelota()
{
    // Pelota
    _texturaPelota.loadFromFile("imagenes/pelota.png");
    _spritePelota.setTexture(_texturaPelota);
    _spritePelota.setOrigin(_spritePelota.getGlobalBounds().width / 2, _spritePelota.getGlobalBounds().height / 2);
    posicionX = POS_INICIAL_PELOTA_X;
    posicionY = POS_INICIAL_PELOTA_Y;
    _spritePelota.setPosition(posicionX, posicionY);
    contador = 0.0;
    //sonido de gol
    _sgol.loadFromFile("goolmarianocloss.mp3");
    sonidoGol.setBuffer(_sgol);
    //setea imagen de gol
    _texCartelGol.loadFromFile("imagenes/gol.png");
    _SpriteCartelGol.setTexture(_texCartelGol);
    _SpriteCartelGol.setOrigin(_SpriteCartelGol.getGlobalBounds().width / 2, _SpriteCartelGol.getGlobalBounds().height / 2);
    _SpriteCartelGol.setPosition(600, 400);
    //setea frame de pelota
    sf::IntRect rect_movimiento_pelota(frame_desplazamientoX * frame_ancho, frame_desplazamientoY * frame_alto, frame_ancho, frame_alto);
    _spritePelota.setTextureRect(rect_movimiento_pelota);

    // Potenciador
    potenciador.setSize(sf::Vector2f(150.f, 15.f));
    potenciador.setFillColor(sf::Color::Transparent);
    potenciador.setPosition(50, 550);
    potenciador.setOutlineThickness(5);
    potenciador.setOutlineColor(sf::Color::Black);

    // Carga Potencia
    cargaPotencia.setSize(sf::Vector2f(0.f, 15.f));
    cargaPotencia.setPosition(50, 550);
    cargaPotencia.setFillColor(sf::Color::Red);
   
}

bool Pelota::verificarGol()
{
    // VERIFICO EL BORDE IZQUIERDO
    // Posicion en X es el centro, necesito el borde izquierdo
    // Borde de la pelota => posicion + _sprite.getGlobalBounds().MEDIDA / 2

    /* ================= FALTARIA AGREGAR CUANDO ES GOL Y CUANDO NO ================= */
    
    if (posicionX - _spritePelota.getGlobalBounds().width / 2 > BORDE_ARCO_IZQUIERDO &&
        posicionY - _spritePelota.getGlobalBounds().height / 2 > BORDE_ARCO_SUPERIOR &&
        posicionX + _spritePelota.getGlobalBounds().width / 2 < BORDE_ARCO_DERECHO &&
        posicionY + _spritePelota.getGlobalBounds().height / 2 < BORDE_ARCO_INFERIOR && PelotaDetenida)
    {
        sonidoGol.play();
       
        //ver destructor
        return true;
    }
    else {
          return false;
    }
}

void Pelota::cargarPotenciador(float potencia)
{
    // TOTAL DEL RECTANGULO 150
    // MAXIMO POTENCIA 3
    // 3 -> 150
    // 2.5 -> x:
    // std::cout << "PORCENTAJE BARRA: " << (potencia * 150) / 3 << std::endl;
    cargaPotencia.setSize(sf::Vector2f((potencia * 150) / 3, 15.f));
    if (potencia <= 1) {
        cargaPotencia.setFillColor(sf::Color::Green);
    }
    else if (potencia > 1 && potencia <= 2) {
        cargaPotencia.setFillColor(sf::Color::Yellow);
    }
    else {
        cargaPotencia.setFillColor(sf::Color::Red);
    }
}

float Pelota::calcularPotencia()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !tiroEnProceso)
    {
     contador++;
    }

  
    if (contador >= MAXIMO_CONTADOR_POTENCIADOR)
    {
        contador = MAXIMO_CONTADOR_POTENCIADOR;
    }

    
        aux = contador;
    
    potencia = aux / 30;
    return potencia;
}

void Pelota::reiniciarDisparo()
{
    if (!tiroEnProceso && PelotaDetenida && posicionY != 730) {
        contadorReinicio++;
        if (contadorReinicio >= 120)

        {

            posicionX = POS_INICIAL_PELOTA_X;
            posicionY = POS_INICIAL_PELOTA_Y;
            _spritePelota.setPosition(posicionX, posicionY);
            _spritePelota.setScale(1, 1);
           
            _direccion = ' ';
            contador = 0.0;
            aux = 0.0;
            maximoPosicionX = 0;
            PelotaDetenida = true;
            tiroEnProceso = false;
            contadorReinicio = 0;

        }
    }
}

void Pelota::escalaPelota()
{
    if (!PelotaDetenida) {
        float posicionPelotaY = _spritePelota.getPosition().y;
        if (posicionPelotaY >= 395)
        {
            float x = (posicionPelotaY - 315) / 404;
            float y = (posicionPelotaY - 315) / 404;
            _spritePelota.setScale(x, y);

        }
    }
}

void Pelota::curvaDisparo(float potencia, float movimientoX)
{
    // y=−0.008f⋅((posicionX−600.0f) 2)+500.0f => La funcion cuadratica que genera la curva
    // -0.008F parabola amplitud
    if (movimientoX < 0 && !PelotaDetenida)
    {
        posicionX += (movimientoX - potencia);
        maximoPosicionX = posicionX;
    }
    if (movimientoX > 0 && !PelotaDetenida)
    {
        posicionX += (movimientoX + potencia);
        maximoPosicionX = posicionX;
    }

    // Posicion de la pelota en Y es mayor a 600 - 1.5 * 200

    // A modo visualizacion de la parabola valor -0,006f amplitud ancha para el tiro abajo
    // A modo visualizacion de la parabola valor -0,008f amplitud angosta para el tiro arriba

    if (posicionY > 500 - potencia * 166)
    {
        // Funcion cuadratica
        
        float aux = calcularPotencia()/100;
        posicionY = -aux * ((posicionX - POS_INICIAL_PELOTA_X) * (posicionX - POS_INICIAL_PELOTA_X)) + POS_INICIAL_PELOTA_Y;
        posicionX = maximoPosicionX;
        
        tiroEnProceso = true;
        escalaPelota();
        PelotaDetenida = false;
    }
    else
    {
        PelotaDetenida = true;
        tiroEnProceso = false;

    }
}

void Pelota::curvaDisparoInferior(float potencia, float movimientoX)
{
   
    if (movimientoX < 0 && !PelotaDetenida)
    {
        //VELOCIDAD DE MOVIMIENTO DE LA PELOTA
        posicionX += (movimientoX - potencia);
        maximoPosicionX = posicionX;
    }

    if (movimientoX > 0 && !PelotaDetenida)
    {
        posicionX += (movimientoX + potencia);
        maximoPosicionX = posicionX;
    }

    // Posicion de la pelota en Y es mayor a 600 - 1.5 * 200

    // A modo visualizacion de la parabola valor -0,006f amplitud ancha para el tiro abajo
    // A modo visualizacion de la parabola valor -0,008f amplitud angosta para el tiro arriba

    if (posicionY > 500 - potencia * ZONAS_DE_POTENCIA)
    {
        // Funcion cuadratica
        posicionY =(-0.015f + (potencia * 0.004))*((posicionX - POS_INICIAL_PELOTA_X) * (posicionX - POS_INICIAL_PELOTA_X)) + POS_INICIAL_PELOTA_Y;

        posicionX = maximoPosicionX;
        tiroEnProceso = true;
        escalaPelota();
        PelotaDetenida = false;
    }
    else
    {
        PelotaDetenida = true;
        tiroEnProceso = false;
    }
}

void Pelota::disparoRectoSuperior(float potencia)
{
    if (posicionY > 600 - potencia * ZONAS_DE_POTENCIA)
    {
        posicionY -= (10 + potencia);
       
        tiroEnProceso = true;
        escalaPelota();
        PelotaDetenida = false;
    }
    else
    {
        PelotaDetenida = true;
        tiroEnProceso = false;

    }
}

void Pelota::disparoRectoInferior(float potencia)
{
    if (posicionY > 360 && posicionY > 600 - potencia * ZONAS_DE_POTENCIA)
    {
        posicionY -= (10 + potencia);
        tiroEnProceso = true;
        escalaPelota();
        PelotaDetenida = false;
    }
    else
    {
        PelotaDetenida = true;
        tiroEnProceso = false;

    }
}

void Pelota::disparo()
{   
    // Numero de frame
    if (tiroEnProceso && !PelotaDetenida)
    {
     // Movimiento circular pelota
        rect_movimiento_pelota = sf::IntRect(frame_desplazamientoX * frame_ancho, frame_desplazamientoY * frame_alto, frame_ancho, frame_alto);
        _spritePelota.setTextureRect(rect_movimiento_pelota);
        if (frame_desplazamientoY == 0)
        {
            frame_desplazamientoY = 1;
        }
        else
        {
            frame_desplazamientoY = 0;
        }
    }

    //devuelve  el float de la potencia aprentando la espaciadora
     float potencia = calcularPotencia();
     //leno la barra segun la potencia
    cargarPotenciador(potencia);

    //DISPAROS//
    // DISPARO ARRIBA MEDIO
    if (potencia > 0) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !tiroEnProceso)
            {
                _direccion = 'W';
                tiroEnProceso = true;
                PelotaDetenida = false;
            }

             if (tiroEnProceso && _direccion == 'W')
             {
              disparoRectoSuperior(potencia);
             }

        // DISPARO ARRIBA DERECHA
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !tiroEnProceso)
             {
                 _direccion = 'E';
                 tiroEnProceso = true;
                   PelotaDetenida = false;
             }

             if (tiroEnProceso && _direccion == 'E')
             {
               curvaDisparo(potencia, 5);
             }

        // DISPARO ARRIBA IZQUIERDA
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !tiroEnProceso)
             {   _direccion = 'Q';
                 tiroEnProceso = true;
                 PelotaDetenida = false;
             }

              if (tiroEnProceso && _direccion == 'Q')
              {
                 curvaDisparo(potencia, -5);
              }

        // DISPARO ABAJO MEDIO
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !tiroEnProceso)
            {
                _direccion = 'S';
                tiroEnProceso = true;
                PelotaDetenida = false;
            }

             if (tiroEnProceso && _direccion == 'S')
             {
                disparoRectoInferior(potencia);
             }

        // DISPARO ABAJO DERECHA
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !tiroEnProceso)
             {
                 _direccion = 'D';
                 tiroEnProceso = true;
                 PelotaDetenida = false;
             }

             if (tiroEnProceso && _direccion == 'D')
             {
                curvaDisparoInferior(potencia, 5);
             }

        // DISPARO ABAJO IZQUIERDA
             if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && !tiroEnProceso)
             {
                 _direccion = 'A';
                 tiroEnProceso = true;
                 PelotaDetenida = false;
             }

            if (tiroEnProceso && _direccion == 'A')
            {
                curvaDisparoInferior(potencia, -5);
            }
    }
    // V.A.R. (Detección de gol)
    if (PelotaDetenida && !tiroEnProceso)
    {
        bool estadoPenal = verificarGol();
       
    }
}

void Pelota::draw(sf::RenderWindow &window)
{
    _spritePelota.setPosition(posicionX, posicionY);
    window.draw(potenciador);
    window.draw(cargaPotencia);
    window.draw(_spritePelota);
    if (verificarGol()) {
        window.draw(_SpriteCartelGol);
        }
}

sf::FloatRect Pelota::getBounds() const
{
    return _spritePelota.getGlobalBounds();
}

void Pelota::setPositionXY(float x, float y) {

    posicionX = x;
    posicionY = y;
    _spritePelota.setPosition(posicionX, posicionY);
}

void Pelota:: setFreno() {
    tiroEnProceso = false;
    PelotaDetenida = true;

}
