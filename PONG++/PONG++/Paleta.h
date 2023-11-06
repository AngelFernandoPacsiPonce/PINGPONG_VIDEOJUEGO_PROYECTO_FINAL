#pragma once
#include <SFML/Graphics.hpp>

class Paleta {
public:
    Paleta(float startX, float startY); // Constructor de la clase Paleta
    void moveUp(); // Método para mover la paleta hacia arriba
    void moveDown(int windowHeight); // Método para mover la paleta hacia abajo
    void setTexture(const sf::Texture& texture); // Método para establecer una textura en la paleta
    sf::RectangleShape getShape(); // Método para obtener la forma de la paleta

private:
    float x, y; // Posición de la paleta
    sf::RectangleShape paleta; // Forma rectangular que representa la paleta
};
