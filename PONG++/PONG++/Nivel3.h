#pragma once

#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Pelota.h"
#include "Musica.h"
#include "Puntaje.h"
#include "Ganador.h"
#include "PaletaFija.h"

class Nivel3 {
public:
    Nivel3(sf::RenderWindow& mainWindow, Musica& music);
    void run();

private:
    sf::RenderWindow& window;
    Paleta paleta1;
    Paleta paleta2;
    PaletaFija paleta3;
    PaletaFija paleta4;
    PaletaFija paleta5; // Nueva paleta fija
   
    Pelota pelota;
    Musica& musica;
    Puntaje puntaje1;
    Puntaje puntaje2;
    Ganador ganador;

    sf::Texture fondoTexture;
    sf::Sprite fondoSprite;

    void actualizarPosicionPaletasFijas();
    float separacionEntrePaletas;
};
