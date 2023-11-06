#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota(float startX, float startY, const std::string& texturaFile); // Constructor de la clase Pelota
    void updatePosition(); // Método para actualizar la posición de la pelota
    void reverseX(); // Método para invertir la dirección en el eje X
    void reverseY(); // Método para invertir la dirección en el eje Y
    sf::Sprite getSprite(); // Método para obtener el sprite de la pelota

private:
    float x, y; // Posición de la pelota
    float velX, velY; // Velocidades en los ejes X e Y
    sf::Sprite pelota; // Sprite que representa la pelota
    float radio; // Radio de la pelota
    sf::Texture textura; // Textura de la pelota
};
