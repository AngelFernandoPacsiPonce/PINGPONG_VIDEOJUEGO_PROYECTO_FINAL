#include "Pelota.h"

Pelota::Pelota(float startX, float startY, const std::string& texturaFile) : x(startX), y(startY) {
    if (!textura.loadFromFile("pelota1.png")) {
        // Manejo de error en caso de que no se pueda cargar la textura.
    }

    pelota.setTexture(textura); // Configura la textura de la pelota
    pelota.setPosition(x, y); // Establece la posición inicial de la pelota
    velX = 0.2;
    velY = 0.2;
    radio = 10.0f; // Define el radio de la pelota
}

void Pelota::updatePosition() {
    x += velX;
    y += velY;
    pelota.setPosition(x, y); // Actualiza la posición de la pelota
}

void Pelota::reverseX() {
    velX = -velX; // Invierte la dirección en el eje X
}

void Pelota::reverseY() {
    velY = -velY; // Invierte la dirección en el eje Y
}

sf::Sprite Pelota::getSprite() {
    return pelota; // Devuelve el sprite de la pelota
}
