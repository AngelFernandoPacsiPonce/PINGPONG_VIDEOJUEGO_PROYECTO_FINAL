#include "PaletaFija.h"

PaletaFija::PaletaFija(float x, float y) {
    paletaShape.setSize(sf::Vector2f(30.0f, 80.0f));
    paletaShape.setPosition(x, y);
}

sf::RectangleShape PaletaFija::getShape() const {
    return paletaShape;
}

void PaletaFija::setPosition(float x, float y) {
    paletaShape.setPosition(x, y);
}

void PaletaFija::setColor(sf::Color color) {
    paletaShape.setFillColor(color);
}
