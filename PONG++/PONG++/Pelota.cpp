#include "Pelota.h"

Pelota::Pelota(float startX, float startY, const std::string& texturaFile) : x(startX), y(startY), radio(60.0f) {
    if (!textura.loadFromFile(texturaFile)) {
        // Manejo de error, si la carga de la textura falla
    }

    pelota.setTexture(textura);
    pelota.setScale(radio / pelota.getLocalBounds().width, radio / pelota.getLocalBounds().height); // Ajuste de escala
    pelota.setPosition(x - radio - 2, y - radio - 2); // Ajuste de posición
    velX = 0.3;
    velY = 0.3;
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

void Pelota::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
    pelota.setPosition(x, y);
}

sf::Sprite Pelota::getSprite() {
    return pelota;
}

float Pelota::getRadio() {
    return radio;
}
