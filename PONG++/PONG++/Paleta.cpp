#include "Paleta.h"

Paleta::Paleta(float startX, float startY) : x(startX), y(startY) {
    paleta.setSize(sf::Vector2f(20, 100)); // Tamaño de la paleta
    paleta.setPosition(x, y);
}

void Paleta::moveUp() {
    if (y > 0) {
        y -= 0.7; // Ajusta la velocidad de movimiento
        paleta.setPosition(x, y);
    }
}

void Paleta::moveDown(int windowHeight) {
    if (y < windowHeight - paleta.getSize().y) {
        y += 0.7; // Ajusta la velocidad de movimiento
        paleta.setPosition(x, y);
    }
}

void Paleta::setTexture(const sf::Texture& texture) {
    paleta.setTexture(&texture);
}

sf::RectangleShape Paleta::getShape() {
    return paleta;
}
