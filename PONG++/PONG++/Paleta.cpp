#include "Paleta.h"

Paleta::Paleta(float startX, float startY) : x(startX), y(startY) {
    paleta.setSize(sf::Vector2f(20, 100)); // Configura el tamaño de la paleta
    paleta.setPosition(x, y); // Establece la posición inicial de la paleta
}

void Paleta::moveUp() {
    if (y > 0) {
        y -= 0.7; // Disminuye la posición en el eje Y para mover la paleta hacia arriba
        paleta.setPosition(x, y); // Actualiza la posición de la paleta
    }
}

void Paleta::moveDown(int windowHeight) {
    if (y < windowHeight - paleta.getSize().y) {
        y += 0.7; // Aumenta la posición en el eje Y para mover la paleta hacia abajo
        paleta.setPosition(x, y); // Actualiza la posición de la paleta
    }
}

void Paleta::setTexture(const sf::Texture& texture) {
    paleta.setTexture(&texture); // Asigna una textura a la paleta
}

sf::RectangleShape Paleta::getShape() {
    return paleta; // Devuelve la forma de la paleta (rectángulo)
}
