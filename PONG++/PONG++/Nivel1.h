#pragma once
#include <SFML/Graphics.hpp>
#include "Pelota.h"
#include "Paleta.h"

class Nivel1 {
public:
    Nivel1(int windowWidth, int windowHeight); // Constructor de la clase Nivel1
    void run(); // Método para ejecutar el nivel

private:
    sf::RenderWindow window; // Ventana de juego
    Paleta paleta1; // Instancia de la paleta 1
    Paleta paleta2; // Instancia de la paleta 2
    Pelota pelota; // Instancia de la pelota
};
