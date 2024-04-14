#include "pelota.h"

const int ZONAS_DE_POTENCIA = 166;
const int POS_INICIAL_PELOTA_Y = 730;
const int POS_INICIAL_PELOTA_X = 600;
const int MAXIMO_CONTADOR_POTENCIADOR = 90;



Pelota::Pelota()
{
    // Pelota
    _texture.loadFromFile("imagenes/pelota.png");
    _sprite.setTexture(_texture);
    _sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
    posicionX = POS_INICIAL_PELOTA_X;
    posicionY = POS_INICIAL_PELOTA_Y;
    _sprite.setPosition(posicionX, posicionY);
    contador = 0.0;

    sf::IntRect rect_movimiento_pelota(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
    _sprite.setTextureRect(rect_movimiento_pelota);

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
    if (posicionX - _sprite.getGlobalBounds().width / 2 > BORDE_ARCO_IZQUIERDO &&
        posicionY - _sprite.getGlobalBounds().height / 2 > BORDE_ARCO_SUPERIOR &&
        posicionX + _sprite.getGlobalBounds().width / 2 < BORDE_ARCO_DERECHO &&
        posicionY + _sprite.getGlobalBounds().height / 2 < BORDE_ARCO_INFERIOR)
    {
        resultadoPenal = true;
        return true;
    }
    resultadoPenal = false;
    return false;
}

void Pelota::cargarPotenciador(float potencia)
{
    // TOTAL DEL RECTANGULO 150
    // MAXIMO POTENCIA 3
    // 3 -> 150
    // 2.5 -> x:
    // std::cout << "PORCENTAJE BARRA: " << (potencia * 150) / 3 << std::endl;
    cargaPotencia.setSize(sf::Vector2f((potencia * 150) / 3, 15.f));
    cargaPotencia.setFillColor(sf::Color::Red);
}

float Pelota::calcularPotencia()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !tiroEnProceso)
    {
        BanderaCronometro = true;
        // sleep_for(milliseconds(50));
        contador++;
    }

    BanderaCronometro = false;

    if (contador >= MAXIMO_CONTADOR_POTENCIADOR)
    {
        contador = MAXIMO_CONTADOR_POTENCIADOR;
    }

    if (contador > 0)
    {
        aux = contador;
    }

    return aux / 30;
}

void Pelota::reiniciarDisparo()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
    {
        posicionX = POS_INICIAL_PELOTA_X;
        posicionY = POS_INICIAL_PELOTA_Y;
        _sprite.setPosition(posicionX, posicionY);
        _sprite.setScale(1, 1);
        _positionInitial = true;
        tiroFinalizado = false;
        _direccion = ' ';
        contador = 0.0;
        aux = 0.0;
        maximoPosicionX = 0;
        freno = false;
        tiroEnProceso = false;
    }
}

void Pelota::escalaPelota()
{
    float posicionPelotaY = _sprite.getPosition().y;
    if (posicionPelotaY > 390)
    {
        float x = (posicionPelotaY - 315) / 404;
        float y = (posicionPelotaY - 315) / 404;
        std::cout << "ESCALA X/Y: " << y << std::endl;
        std::cout << "POSICION PELOTA: " << posicionPelotaY << std::endl;
        // _sprite.move(-_velocity);
        _sprite.setScale(x, y);
    }
}

void Pelota::curvaDisparo(float potencia, float movimientoX)
{
    // y=−0.008f⋅((posicionX−600.0f) 2)+500.0f => La funcion cuadratica que genera la curva
    // -0.008F parabola amplitud
    if (movimientoX < 0 && !freno)
    {
        posicionX += (movimientoX - potencia);
        maximoPosicionX = posicionX;
    }
    if (movimientoX > 0 && !freno)
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
        posicionY = -0.008f * ((posicionX - POS_INICIAL_PELOTA_X) * (posicionX - POS_INICIAL_PELOTA_X)) + POS_INICIAL_PELOTA_Y;
        posicionX = maximoPosicionX;
        freno = false;
        escalaPelota();
    }
    else
    {
        freno = true;
    }
}

void Pelota::curvaDisparoInferior(float potencia, float movimientoX)
{
    // y=−0.008f⋅((posicionX−600.0f) 2)+500.0f => La funcion cuadratica que genera la curva
    // -0.008F parabola amplitud
    if (movimientoX < 0 && !freno)
    {
        posicionX += (movimientoX - potencia);
        maximoPosicionX = posicionX;
    }


    if (movimientoX > 0 && !freno)
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
        posicionY = -0.006f * ((posicionX - POS_INICIAL_PELOTA_X) * (posicionX - POS_INICIAL_PELOTA_X)) + POS_INICIAL_PELOTA_Y;
        posicionX = maximoPosicionX;
        freno = false;
        escalaPelota();
    }
    else
    {
        freno = true;
    }
    posicionxPrueba = posicionX;
}

void Pelota::disparoRectoSuperior(float potencia)
{
    if (posicionY > 600 - potencia * ZONAS_DE_POTENCIA)
    {
        posicionY -= (10 + potencia);
        /*float posicionPelotaY = _sprite.getPosition().y;
        if (posicionPelotaY > 390)
        {
            float x = (posicionPelotaY - 315.88) / 404.11;
            float y = (posicionPelotaY - 315.88) / 404.11;
            std::cout << posicionPelotaY << std::endl;
            // _sprite.move(-_velocity);
            _sprite.setScale(x, y);
        }*/
        escalaPelota();
        freno = false;
    }
    else
    {
        freno = true;
    }
}

void Pelota::disparoRectoInferior(float potencia)
{
    if (posicionY > 360 && posicionY > 600 - potencia * ZONAS_DE_POTENCIA)
    {
        posicionY -= (10 + potencia);
        /*float posicionPelotaY = _sprite.getPosition().y;
        if (posicionPelotaY > 390)
        {
            float x = (posicionPelotaY - 315.88) / 404.11;
            float y = (posicionPelotaY - 315.88) / 404.11;
            std::cout << posicionPelotaY << std::endl;
            // _sprite.move(-_velocity);
            _sprite.setScale(x, y);
        }*/
        escalaPelota();
        freno = false;

    }
    else
    {
        freno = true;
    }
}


void Pelota::disparo()
{
    // Movimiento circular pelota
    // Numero de frame 
    if(tiroEnProceso && !freno){
        rect_movimiento_pelota = sf::IntRect(frame_horizontal * frame_ancho, frame_vertical * frame_alto, frame_ancho, frame_alto);
        _sprite.setTextureRect(rect_movimiento_pelota);
        if(frame_vertical == 0){
            frame_vertical = 1;
        }else{
            frame_vertical = 0;
        }
    }

    float potencia = calcularPotencia();
    cargarPotenciador(potencia);
    // DISPARO ARRIBA MEDIO
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !tiroEnProceso)
    {
        _direccion = 'W';
        tiroEnProceso = true;
    }

    if (tiroEnProceso && _direccion == 'W')
    {
        disparoRectoSuperior(potencia);
    }

    // DISPARO ARRIBA DERECHA
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E) && !tiroEnProceso)
    {
        _direccion = 'E';
        tiroEnProceso = true;
    }

    if (tiroEnProceso && _direccion == 'E')
    {
        curvaDisparo(potencia, 5);
    }

    // DISPARO ARRIBA IZQUIERDA
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !tiroEnProceso)
    {
        _direccion = 'Q';
        tiroEnProceso = true;
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
    }

    if (tiroEnProceso && _direccion == 'A')
    {
        curvaDisparoInferior(potencia, -5);
    }

    // V.A.R. (Deteccion de gol)
    if (freno && tiroEnProceso)
    {
        bool estadoPenal = verificarGol();
        if (estadoPenal)
        {
            std::cout << "GOL!" << std::endl;
        }
        else
        {
            std::cout << "AFUERA!" << std::endl;
        }
    }

    //out << "posX: " << posicionX << endl;
}

void Pelota::draw(sf::RenderWindow &window)
{
    _sprite.setPosition(posicionX, posicionY);
    window.draw(potenciador);
    window.draw(cargaPotencia);
    window.draw(_sprite);
}

sf::FloatRect Pelota::getBounds() const
{
    return _sprite.getGlobalBounds();
}
