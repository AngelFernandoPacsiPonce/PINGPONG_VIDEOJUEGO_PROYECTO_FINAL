#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota(float startX, float startY, const std::string& texturaFile);
    void updatePosition();
    void reverseX();
    void reverseY();
    sf::Sprite getSprite();
    float getRadio(); // Agrega este método

private:
    float x, y;
    float velX, velY;
    sf::Sprite pelota;
    float radio;
    sf::Texture textura;
};
