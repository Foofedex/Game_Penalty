#pragma once
#include "pelota.h"
#include <cstring>
#include "NOMBRE.h"
using namespace std;

class cls_Display
{
private:
	bool banderaVolver = false;
	bool anotado = false;
	int goles = 0;
	sf::Font font;
	sf::Text gol;
	sf::Text nombreMostrar;
	sf::Text volver;
	sf::Font contadorTiros;
	sf::Text cTiros;
	NOMBRE nombre;
	


public:
	void Puntaje();
	void draw(sf::RenderWindow&);
	void FuncionVolvere(sf::RenderWindow&);
	void anotacion();
	void setAnotado(bool var)
	{
		anotado = var;
	};
	bool botonVolver(sf::RenderWindow&);
	bool getBanderaVolver() {
		return banderaVolver;
	}
	void setBanderaVolver(bool a)
	{
		banderaVolver = a;
	}
	int getGolesAnotados() {
		return goles;
	}
	void setGolesAnotados(int cGoles) {
		goles = cGoles;
	}
	void cDisparos(int a);
	sf::Text getGol() {
		return gol;
	}
	sf::Text getNombre() {
	
		return nombreMostrar;
	}
	sf::Text getCantidadTiros() {
		return cTiros;
	}
	void setNombre(string a) {
		nombreMostrar.setString(a);
	}
};