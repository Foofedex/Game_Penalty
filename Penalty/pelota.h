#pragma once
using namespace std;

#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Audio.hpp>
#include "Collisionable.h"

class Pelota : public Collisionable
{
	// Potenciador
	sf::RectangleShape potenciador;
	sf::RectangleShape cargaPotencia;
	// Pelota
	sf::Sprite _spritePelota;
	sf::Sprite _SpriteCartelGol;
	sf::Texture _texCartelGol;
	sf::Texture _texturaPelota;
	sf::SoundBuffer _sgol;
	sf::Sound sonidoGol;
	const int ZONAS_DE_POTENCIA = 166;
	const int POS_INICIAL_PELOTA_Y = 730;
	const int POS_INICIAL_PELOTA_X = 600;
	const int MAXIMO_CONTADOR_POTENCIADOR = 90;

	
	
	//======== TRAER ESTAS PROPIEDADES DE LA CLASE ARCO ==============//
	const int BORDE_ARCO_IZQUIERDO = 326;
	const int BORDE_ARCO_DERECHO = 876;
	const int BORDE_ARCO_SUPERIOR = 215;
	const int BORDE_ARCO_INFERIOR = 390;
	//=============== PELOTA-FRAME ================== //
	int frame_desplazamientoX = 0;
	int frame_desplazamientoY = 0;
	int frame_ancho = 109; // Ancho de cada frame
	int frame_alto = 109;  // Alto de cada frame
	sf::IntRect rect_movimiento_pelota;
	//======== TRAER ESTAS PROPIEDADES DE LA CLASE ARCO ==============//
	
	float contador;
	
	float aux = 0.0, maximoPosicionX = 0.0;
	float posicionX, posicionY;
	bool tiroFinalizado = false, tiroEnProceso = false;
	char _direccion=' ';
	bool PelotaDetenida = true;
	float potencia = 0.0;
	int contadorReinicio = 0;
	
public:
	Pelota();
	
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
	int getContadorReinicio() { return contadorReinicio; }
	sf::FloatRect getBounds() const override;
	float getPositionPelotaX() { return _spritePelota.getPosition().x; }
	float getPositionPelotaY() { return _spritePelota.getPosition().y; }
	bool getPelotaDetenida() { return PelotaDetenida; }
	bool getTiroEnProceso() { return tiroEnProceso; }
	void setFreno();
	void setPositionXY(float x, float y);
	const char getdireccion() {
		return _direccion;
		
	}
	
};