#pragma once

#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Pelota.h"
#include "Musica.h"
#include "Puntaje.h"
#include "Ganador.h"
#include "Barrera.h"

class Nivel3 {
public:
    Nivel3(sf::RenderWindow& mainWindow, Musica& music);
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
    std::vector<Barrera> barreras;
    void inicializarBarreras();

    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;
};
