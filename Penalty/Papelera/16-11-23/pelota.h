#pragma once
// #include "Potencia.h"
#include <SFML\Graphics.hpp>
#include "SFML/Graphics.hpp"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

#include "Collisionable.h"

class Pelota : public Collisionable
{
	// Potenciador
	sf::RectangleShape potenciador;
	sf::RectangleShape cargaPotencia;
	// Pelota
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _velocity;
	//======== TRAER ESTAS PROPIEDADES DE LA CLASE ARCO ==============//
	const int BORDE_ARCO_IZQUIERDO = 326;
	const int BORDE_ARCO_DERECHO = 876;
	const int BORDE_ARCO_SUPERIOR = 215 /* - _sprite.getGlobalBounds().height / 2*/;
	const int BORDE_ARCO_INFERIOR = 390;
	//=============== PELOTA-FRAME ================== //
	int frame_horizontal = 0; 
	int frame_vertical = 0;
	int frame_ancho = 109; // Ancho de cada frame
	int frame_alto = 109; // Alto de cada frame
	sf::IntRect rect_movimiento_pelota;
	//======== TRAER ESTAS PROPIEDADES DE LA CLASE ARCO ==============//
	bool _positionInitial = true;
	float contador;
	bool BanderaCronometro = false;
	float aux = 0.0, maximoPosicionX = 0.0;
	float posicionX, posicionY;
	bool tiroFinalizado = false, tiroEnProceso = false;
	char _direccion;
	bool freno = false, resultadoPenal = false;

	float posicionxPrueba;
	

public:
	Pelota();
	// void disparo(float deltatime);
	void cargarPotenciador(float potencia);
	void curvaDisparo(float potencia, float movimientoX);
	void curvaDisparoInferior(float potencia, float movimientoX);
	void disparoRectoSuperior(float potencia);
	void disparoRectoInferior(float potencia);
	void disparo();
	void draw(sf::RenderWindow &);
	void reiniciarDisparo();
	float calcularPotencia();
	void escalaPelota();
	bool verificarGol();
	sf::FloatRect getBounds() const override;
	float getPositionPelotaX() { return _sprite.getPosition().x; }
	float getPositionPelotaY() { return _sprite.getPosition().y; }

};