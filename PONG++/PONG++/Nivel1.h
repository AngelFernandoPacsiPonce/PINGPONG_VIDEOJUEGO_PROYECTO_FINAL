#pragma once
#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Pelota.h"
#include "Musica.h"
#include "Puntaje.h"  // Agregamos la inclusión de la clase Puntaje

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
    Puntaje puntaje;  // Agregamos un objeto de la clase Puntaje
};
