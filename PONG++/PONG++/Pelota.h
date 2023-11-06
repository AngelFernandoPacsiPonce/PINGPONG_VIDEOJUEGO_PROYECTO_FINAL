#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota(float startX, float startY, const std::string& texturaFile); // Constructor de la clase Pelota
    void updatePosition(); // M�todo para actualizar la posici�n de la pelota
    void reverseX(); // M�todo para invertir la direcci�n en el eje X
    void reverseY(); // M�todo para invertir la direcci�n en el eje Y
    sf::Sprite getSprite(); // M�todo para obtener el sprite de la pelota

private:
    float x, y; // Posici�n de la pelota
    float velX, velY; // Velocidades en los ejes X e Y
    sf::Sprite pelota; // Sprite que representa la pelota
    float radio; // Radio de la pelota
    sf::Texture textura; // Textura de la pelota
};
