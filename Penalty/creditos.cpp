#include "creditos.h"
Creditos::Creditos()
{
    Fuente_creditos.loadFromFile("dogica.ttf");
    Texto_creditos.setFont(Fuente_creditos);

    Texto_creditos.setString("Penalty 24:\n\n\nJuego realizado por:\n\n\n"
        "Gaston Pandullo, Marco Allegri,\n\nDaniel Guillen y Federico Mojica\n\n\n"
        "\n\n\nCatedra: Laboratorio II"
        "\n\n\nDocentes: Brian Lara y Angel Simon"
        "\n\n\nJTP: Verónica Carbonari,\n\n\nMariano Varela y Ariel Tapia");
    Texto_creditos.setOrigin(Texto_creditos.getGlobalBounds().width / 2, Texto_creditos.getGlobalBounds().height / 2);
    Texto_creditos.setPosition(600, 400);
}

void Creditos::draw(sf::RenderWindow& window)
{
	window.draw(Texto_creditos);
}

