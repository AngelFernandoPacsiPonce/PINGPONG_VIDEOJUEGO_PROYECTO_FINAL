// Nivel1.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Pelota.h"
#include "Musica.h"

class Nivel1 {
public:
    Nivel1(sf::RenderWindow& mainWindow, Musica& music); // Agregar Musica como argumento
    void run();

private:
    sf::RenderWindow& window;
    Paleta paleta1;
    Paleta paleta2;
    Pelota pelota;
    Musica& musica; // Mantener una referencia a Musica
};
