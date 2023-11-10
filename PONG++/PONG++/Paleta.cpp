// Paleta.cpp
#include "Paleta.h"
#include <iostream>
Paleta::Paleta(float startX, float startY) : x(startX), y(startY) {
    paleta.setSize(sf::Vector2f(20, 100));
    paleta.setPosition(x, y);
}

void Paleta::moveUp() {
    if (y > 0) {
        y -= 0.7;
        paleta.setPosition(x, y);
    }
}

void Paleta::moveDown(int windowHeight) {
    if (y < windowHeight - paleta.getSize().y) {
        y += 0.7;
        paleta.setPosition(x, y);
    }
}

void Paleta::setTexture(const std::string& texturePath) {
    if (!textura.loadFromFile(texturePath)) {
        std::cerr << "Error: No se pudo cargar la textura para la paleta." << std::endl;
    }
    paleta.setTexture(&textura);
}

sf::RectangleShape Paleta::getShape() {
    return paleta;
}
