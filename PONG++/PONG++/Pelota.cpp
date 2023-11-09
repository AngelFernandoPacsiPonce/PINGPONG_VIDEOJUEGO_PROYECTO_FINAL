#include "Pelota.h"

Pelota::Pelota(float startX, float startY, const std::string& texturaFile) : x(startX), y(startY), radio(120.0f) {
    if (!textura.loadFromFile("pelota1.png")) {
        
    }

    pelota.setTexture(textura);
    pelota.setScale(radio / pelota.getLocalBounds().width, radio / pelota.getLocalBounds().height); // Ajuste de escala
    pelota.setPosition(x - radio, y - radio); // Ajuste de posici�n
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

sf::Sprite Pelota::getSprite() {
    return pelota;
}

float Pelota::getRadio() {
    return radio;
}
