#pragma once
#include "Cancha.h"
#include "Pelota.h"
#include "Arquero.h"
#include "Instrucciones.h"
#include "Estadisticas.h"
#include "cls_Display.h"
#include <SFML/Audio.hpp>


class Juego  
{
   
    Pelota balon;
    Arquero portero;
    Cancha nuevaCancha;
    Instrucciones instrucc;
    cls_Display marcador_de_goles;
    Estadisticas estadistic;
    int contadorDisparos = 0;
    sf::SoundBuffer ambiente;
    sf::Sound tribuna;
    sf::SoundBuffer locutor;
    sf::Sound entradaLocutor;
    bool banderaEntradaLocutor = true;
    bool Winner = false;
    bool GameOver = false;
    bool cargarNombre = false;
    sf::Sprite Sprite_Gano;
    sf::Sprite Sprite_Perdio;
    sf::Texture Texture_Gano;
    sf::Texture Texture_Perdio;
    ArchivoEstadisticas guardarPartida;


    
    public:
public:
    Juego(sf::RenderWindow& window) : portero(balon) {

        //sonidos 
        ambiente.loadFromFile("ambiente.mp3");
        tribuna.setBuffer(ambiente);
        tribuna.setVolume(30);
        locutor.loadFromFile("inicioJuegoIntrucciones.mp3");
        entradaLocutor.setBuffer(locutor);

        // ganador 
        Texture_Gano.loadFromFile("imagenes/ImagenWinner.png");
        Sprite_Gano.setTexture(Texture_Gano);
        
        //perdedor
        Texture_Perdio.loadFromFile("imagenes/gameover.png");
        Sprite_Perdio.setTexture(Texture_Perdio);

    }

    void jugar(sf::RenderWindow& window, NOMBRE& name);

    void sonidoAmbient() {
        tribuna.play();
        tribuna.setLoop(true);
    }
    void sonidoAmbientStop() {
        tribuna.stop();
        entradaLocutor.stop(); 
    }
    void sonidoLocutor() {
        entradaLocutor.play();
    }
    void sonidoLocutorStop() {
        entradaLocutor.stop();
    }
    bool getbanderaLocutorEntrada() {
        return banderaEntradaLocutor;
    }
    void setbanderaLocutorEntrada(bool a) {
        banderaEntradaLocutor = a;
    }
    void PerdioDraw(sf::RenderWindow& window) {
        window.draw(Sprite_Perdio);
    }
    void GanoDraw(sf::RenderWindow& window) {
        window.draw(Sprite_Gano);
    }
    int getContadorDisparos() {
        return contadorDisparos;
    }

    void setWinner(bool a) {
        Winner = a;
    }
    void setGameOver(bool a){
        GameOver = a;
    }
    bool getWinner() {
        return Winner;
    }
    bool getGameOver() {
        return GameOver;
    }
    cls_Display getMarcadorGoles() {
        return marcador_de_goles;
    }

 
};