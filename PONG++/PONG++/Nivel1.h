#pragma once
#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Pelota.h"
#include "Musica.h"
#include "Puntaje.h"
#include "Ganador.h"

class Nivel1 {
public:
    Nivel1(sf::RenderWindow& mainWindow, Musica& music);
    void run();

private:
    sf::RenderWindow& window;
    Paleta paleta1;
    Paleta paleta2;
    Pelota pelota;
    Musica& musica;
    Puntaje puntaje1;
    Puntaje puntaje2;
    Ganador ganador;

    sf::Texture fondoTexture;  // Textura para el fondo
    sf::Sprite fondoSprite;    // Sprite para el fondo
};
