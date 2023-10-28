#include "Pelota.h"

Pelota::Pelota(float startX, float startY, const std::string& texturaFile) : x(startX), y(startY) {
    if (!textura.loadFromFile("pelota1.png")) {
        // Manejo de error en caso de que no se pueda cargar la textura.
    }

    pelota.setTexture(textura);
    pelota.setPosition(x, y);
    velX = 0.2;
    velY = 0.2;
    radio = 10.0f; // Define el radio de la pelota
}

void Pelota::updatePosition() {
    x += velX;
    y += velY;
    pelota.setPosition(x, y);
}

void Pelota::reverseX() {
    velX = -velX;
}

void Pelota::reverseY() {
    velY = -velY;
}

sf::Sprite Pelota::getSprite() {
    return pelota;
}
