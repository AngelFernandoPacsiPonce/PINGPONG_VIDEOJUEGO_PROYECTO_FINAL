// Barrera.cpp
#include "Barrera.h"

Barrera::Barrera(float startX, float startY, float width, float height) : x(startX), y(startY) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::White);  // Puedes ajustar el color según tu diseño
}

sf::RectangleShape Barrera::getShape() const {
    return shape;
}