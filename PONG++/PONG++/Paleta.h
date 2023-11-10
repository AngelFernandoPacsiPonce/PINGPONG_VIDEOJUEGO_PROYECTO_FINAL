// Paleta.h
#pragma once
#include <SFML/Graphics.hpp>

class Paleta {
public:
    Paleta(float startX, float startY);
    void moveUp();
    void moveDown(int windowHeight);
    void setTexture(const std::string& texturePath);
    sf::RectangleShape getShape();

private:
    float x, y;
    sf::RectangleShape paleta;
    sf::Texture textura; // Nueva variable para almacenar la textura
};
