#pragma once
#include <SFML/Graphics.hpp>

class Paleta {
public:
    Paleta(float startX, float startY); // Constructor de la clase Paleta
    void moveUp(); // M�todo para mover la paleta hacia arriba
    void moveDown(int windowHeight); // M�todo para mover la paleta hacia abajo
    void setTexture(const sf::Texture& texture); // M�todo para establecer una textura en la paleta
    sf::RectangleShape getShape(); // M�todo para obtener la forma de la paleta

private:
    float x, y; // Posici�n de la paleta
    sf::RectangleShape paleta; // Forma rectangular que representa la paleta
};
