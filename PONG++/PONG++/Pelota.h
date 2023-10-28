#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota(float startX, float startY, const std::string& texturaFile);
    void updatePosition();
    void reverseX();
    void reverseY();
    sf::Sprite getSprite();

private:
    float x, y;
    float velX, velY;
    sf::Sprite pelota;
    float radio; // Agrega el radio de la pelota como miembro
    sf::Texture textura; // Agrega la textura como miembro
};
