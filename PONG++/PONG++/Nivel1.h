#ifndef NIVEL1_H
#define NIVEL1_H

#include <SFML/Graphics.hpp>
#include "Paleta.h"
#include "Pelota.h"

class Nivel1 {
public:
    Nivel1(sf::RenderWindow& mainWindow); // Constructor que recibe una referencia a sf::RenderWindow
    void run();

private:
    sf::RenderWindow& window; // Referencia a la ventana de SFML
    Paleta paleta1;
    Paleta paleta2;
    Pelota pelota;
};

#endif
