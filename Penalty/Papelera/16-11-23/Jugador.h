#pragma once
#include <cstring>
#include "SFML/Graphics.hpp"
class Jugador: public sf::Drawable
{
	sf::Sprite Spriter_Pateador;
	sf::Texture Texture_Pateador;
	sf::IntRect Rect_movimientosPateador;
	//char _nombre[30];
	//char _apellido[30];
	float _velocidad, _precision, _edad, _goles, _desplazamientoImagen;

public:
	Jugador();

	//void setNombre(const char *nombre);
//	void setApellido(const char *apellido);
	void draw(sf::RenderTarget&, sf::RenderStates states) const override;
	void movimientoDelPateador();
	void getPosicionPateador();
};
