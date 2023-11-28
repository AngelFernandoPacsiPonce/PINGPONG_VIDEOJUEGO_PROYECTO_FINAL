#include "PaletaFija.h"

PaletaFija::PaletaFija(float x, float y) {
    paletaShape.setSize(sf::Vector2f(10.0f, 100.0f));
    paletaShape.setPosition(x, y);
}

sf::RectangleShape PaletaFija::getShape() const {
    return paletaShape;
}

void PaletaFija::setPosition(float x, float y) {
    paletaShape.setPosition(x, y);
}
