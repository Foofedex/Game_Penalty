#include "Jugador.h"
Jugador::Jugador()
{
    _desplazamientoImagen = 80;
    Rect_movimientosPateador= sf::IntRect(200, 0, 80, 100);

    Texture_Pateador.loadFromFile("imagenes/nuevoArqueroRedimensionado.png");
    Texture_Pateador.setSmooth(true);
    Spriter_Pateador.setTexture(Texture_Pateador);
    Spriter_Pateador.setTextureRect(Rect_movimientosPateador);
    _velocidad = 1;
    _precision = 1;
    _edad = 30;
    _goles = 0;

    //esto es de chat gpt
    int frame_actual = 0;
    int total_frames = 5; // Tienes 5 frames de animaci�n
    sf::Clock reloj_animacion;
    float velocidad_animacion = 1.0f;

    
}

/*
    char nombre[] = "Daniel";
    char apellido[] = "Guillen";
    strcpy(_nombre, nombre);
    strcpy(_apellido, apellido);*/
/*
void Jugador::setNombre(const char *n)
{
	strcpy(_nombre, n);
}
void Jugador::setApellido(const char *a)
{
	strcpy(_apellido, a);
}
void Jugador::draw(sf::RenderWindow& window)
{
	window.draw(Sprite_Jugador);
}

*/
void Jugador::movimientoDelPateador() {
    int frame_actual = 0;
    int total_frames = 5; // Supongamos que tienes 4 frames de animaci�n
    sf::Clock reloj_animacion;
    float velocidad_animacion = 00.1f;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
       // Spriter_Pateador.move(0, -_velocidad);
        /*Rect_movimientosPateador = sf::IntRect(100, 0, 100, 80);
        Spriter_Pateador.setTextureRect(Rect_movimientosPateador);
        Rect_movimientosPateador = sf::IntRect(0, 0, 80, 100);
        Spriter_Pateador.setTextureRect(Rect_movimientosPateador);*/
        
            frame_actual = (frame_actual + 1) % total_frames;
            reloj_animacion.restart();
        

        // Configurar el rect�ngulo de la textura seg�n el frame actual
        int frame_ancho = 100; // Ancho de cada frame
        int frame_alto = 80; // Alto de cada frame
        sf::IntRect rect_movimiento_pateador(frame_actual * frame_ancho, 0, frame_ancho, frame_alto);
        Spriter_Pateador.setTextureRect(rect_movimiento_pateador);
   
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        Spriter_Pateador.move(0, _velocidad);
        Rect_movimientosPateador = sf::IntRect(0, 0, 80, 100);
        Spriter_Pateador.setTextureRect(Rect_movimientosPateador);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Spriter_Pateador.move(-_velocidad, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Spriter_Pateador.move(_velocidad, 0);
    }
}
void Jugador::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(Spriter_Pateador, states);
}
void Jugador::getPosicionPateador()
{
    
    if (Spriter_Pateador.getPosition().x < 100) {
        Spriter_Pateador.setPosition(100, Spriter_Pateador.getPosition().y);
    }
    if (Spriter_Pateador.getPosition().x > 740) {
        Spriter_Pateador.setPosition(740, Spriter_Pateador.getPosition().y);
    }

    if (Spriter_Pateador.getPosition().y < 400) {
        Spriter_Pateador.setPosition(Spriter_Pateador.getPosition().x, 400);
    }

    if (Spriter_Pateador.getPosition().y > 306) {
        Spriter_Pateador.setPosition(Spriter_Pateador.getPosition().x, 306);
    }
}