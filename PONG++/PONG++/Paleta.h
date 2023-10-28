#pragma once
#include <SFML/Graphics.hpp>

class Paleta {
public:
    Paleta(float startX, float startY);
    void moveUp();
    void moveDown(int windowHeight);
    void setTexture(const sf::Texture& texture);
    sf::RectangleShape getShape();

private:
    float x, y;
    sf::RectangleShape paleta;
};
