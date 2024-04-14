#pragma once
#include <cstring>


class Estadisticas
{
private:


	char nombreCadena[30];
	int cantidadDisparos = 0, goles = 0;
	bool banderaDeGuardado = false;
public:
	Estadisticas() {}


	void setCantidadDisparos(int a) {
		cantidadDisparos = a;
	}
	int getCantidadDisparos() {
		return cantidadDisparos;
	}

	void setGoles(int a) {
		goles = a;
	}
	int getGoles() {
		return goles;
	}


	void guardar(const char *nom, int gol, int cd) {
		
		strcpy_s(nombreCadena, nom);
		goles = gol;
		cantidadDisparos = cd;
		cout << nom << endl;
		cout << gol << endl;
		cout << cd << endl;
	}
	void setBanderaGuardado(bool a) {
		banderaDeGuardado = a;
	}
	bool getBanderaGuardado() {
		return banderaDeGuardado;
	}

	void MostrarArchivo() {


		cout <<"JUGADOR:"<< nombreCadena <<"    GOLES: "<<goles << "   DISPAROS " << cantidadDisparos << endl;

	}

	char* getNombre() {
		return  nombreCadena;
	
	}

};

class ArchivoEstadisticas
{
private:
	char nombre[30];


public:
	bool lecturaArchivo=false;

	ArchivoEstadisticas()
	{
		strcpy_s(nombre, "estadisticas.sav");
	}

	Estadisticas leerRegistro(int pos)
	{
		Estadisticas reg;
		FILE* p;
		fopen_s(&p, nombre, "rb");
		if (p == NULL)
			return reg;
		fseek(p, sizeof reg * pos, 0);
		fread(&reg, sizeof reg, 1, p);
		fclose(p);
		return reg;
	}
	int contarRegistros()
	{
		FILE* p;
		fopen_s(&p, nombre, "rb");
		if (p == NULL) {
			cout << "no leyoo el archivo" << endl;
			return 0;
		}
		fseek(p, 0, 2);
		int tam = ftell(p);
		fclose(p);
		return tam / sizeof(Estadisticas);
	}
	bool grabarRegistro(Estadisticas reg)
	{
		FILE* p;
		fopen_s(&p, nombre, "ab");
		if (p == NULL) {
			return false;
		}
		bool escribio = fwrite(&reg, sizeof reg, 1, p);
		fclose(p);
		return escribio;
	}

};


class BasedeEstadisticas {

public:
	void matrizFinalEstadistica(int x, sf::RenderWindow& window, Estadisticas VectorEstadistica[5], sf::Text Nombre, sf::Text goles, sf::Text disparos)
	{
		Nombre.setString(VectorEstadistica[x].getNombre());
		Nombre.setPosition(0, x * 160 + 50);
		goles.setString(to_string(VectorEstadistica[x].getGoles()));
		goles.setPosition(350, x * 160 + 50);
		disparos.setString(to_string(VectorEstadistica[x].getCantidadDisparos()));
		disparos.setPosition(680, x * 160 + 50);
		window.draw(Nombre);
		window.draw(goles);
		window.draw(disparos);
	}

	void CargaMatrizdePuntos(sf::RenderWindow& window) {

		ArchivoEstadisticas archivoEstadisticas;
		int totalregistros = archivoEstadisticas.contarRegistros();
		Estadisticas VectorEstadistica[5];
		sf::Text Nombre, goles, disparos;
		sf::Font fuente;
		fuente.loadFromFile("dogica.ttf");
		Nombre.setFont(fuente);
		goles.setFont(fuente);
		disparos.setFont(fuente);
		Nombre.setCharacterSize(35);
		goles.setCharacterSize(35);
		disparos.setCharacterSize(35);

		Estadisticas *vecDinamicoEstadistica;
		//creo vector dinamico y pido memoria
		vecDinamicoEstadistica = new Estadisticas[totalregistros];
		if (vecDinamicoEstadistica == NULL) {
			cout << "ERROR DE MEMORIA" << endl;
		}
		
		//lleno el vector dinamico con todos los registros del .sav
		for (int x = 0; x< totalregistros; x++) {
		vecDinamicoEstadistica[x] = archivoEstadisticas.leerRegistro(x);
		}

		//ordeno el vector dinamico con el burbujeo
		Estadisticas auxiliar;
		for (int i = 0; i < totalregistros; i++) {
			for (int j = 0; j < totalregistros-1; j++) {
				if (vecDinamicoEstadistica[j].getGoles() < vecDinamicoEstadistica[j + 1].getGoles()) {
					//intercambiar elementos si están en el orden incorrecto
					auxiliar = vecDinamicoEstadistica[j];
					vecDinamicoEstadistica[j] = vecDinamicoEstadistica[j + 1];
					vecDinamicoEstadistica[j + 1] = auxiliar;

				}
			}
		}

		//cargo el vector base de 5 con el dinamico
		if (totalregistros > 5) {
			for (int i = 0; i < 5; i++) {
				VectorEstadistica[i] = vecDinamicoEstadistica[i];
			}
		}
		else {
			for (int x = 0; x < totalregistros; x++) {
				VectorEstadistica[x] = vecDinamicoEstadistica[x];
			}
		}
		//borro el dinamico y libero memoria
		delete vecDinamicoEstadistica;

		//llamo a la funcion para mostrar y le paso el vector
		if (totalregistros > 0)
		{
			if (totalregistros < 5)
			{
				for (int x = 0; x < totalregistros; x++) {
					matrizFinalEstadistica(x, window, VectorEstadistica, Nombre, goles, disparos);
				}
			}
			else {
				for (int x = 0; x < 5; x++) {
					matrizFinalEstadistica(x,window, VectorEstadistica, Nombre, goles, disparos);
				}
			}
			//dibujo los titulos
			Nombre.setPosition(0, 0);
			Nombre.setString("NOMBRE ");
			Nombre.setFillColor(sf::Color::Cyan);
			goles.setFillColor(sf::Color::Cyan);
			goles.setPosition(300, 0);
			goles.setString("GOLES ");
			disparos.setFillColor(sf::Color::Cyan);
			disparos.setPosition(600, 0);
			disparos.setString("DISPAROS ");
			window.draw(Nombre);
			window.draw(goles);
			window.draw(disparos);


		}
		//cartel si no hay registros
		else {
			Nombre.setPosition(0, 100);
			Nombre.setString("NO EXISTEN PARTIDAS REGISTRADAS ");
			Nombre.setFillColor(sf::Color::Cyan);
			window.draw(Nombre);

		}
		
		
	}
	
};
		
