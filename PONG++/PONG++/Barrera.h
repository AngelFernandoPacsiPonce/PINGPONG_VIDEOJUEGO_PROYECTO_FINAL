// Barrera.h
#pragma once
#include <SFML/Graphics.hpp>

class Barrera {
public:
    Barrera(float startX, float startY, float width, float height);
    // Declarar la función como constante
    sf::RectangleShape getShape() const;
    void setPosition(float x, float y) {
        shape.setPosition(x, y);
    }
private:
    float x, y;
    sf::RectangleShape shape;
};