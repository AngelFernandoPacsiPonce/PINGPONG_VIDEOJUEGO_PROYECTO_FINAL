#include "Pelota.h"

Pelota::Pelota(float startX, float startY, const std::string& texturaFile) : x(startX), y(startY), radio(50.0f), factorIncrementoVelocidad(0.02f) {
    if (!textura.loadFromFile(texturaFile)) {
        // Manejo de error, si la carga de la textura falla
    }

    pelota.setTexture(textura);
    pelota.setScale(radio / pelota.getLocalBounds().width, radio / pelota.getLocalBounds().height);
    pelota.setPosition(x - radio - 2, y - radio - 2); // Ajuste de posición
    velX = 0.2;
    velY = 0.2;
}

void Pelota::updatePosition() {
    x += velX;
    y += velY;
    pelota.setPosition(x, y);
}

void Pelota::reverseX() {
    velX = -velX;
    incrementarVelocidad();  // Incrementar la velocidad al invertir la dirección X
}

void Pelota::reverseY() {
    velY = -velY;
    incrementarVelocidad();  // Incrementar la velocidad al invertir la dirección Y
}

void Pelota::setPosition(float newX, float newY) {
    x = newX;
    y = newY;
    pelota.setPosition(x, y);
    resetearVelocidad();  // Resetear la velocidad al establecer una nueva posición
}

sf::Sprite Pelota::getSprite() {
    return pelota;
}

float Pelota::getRadio() {
    return radio;
}

void Pelota::incrementarVelocidad() {
    velX += (velX > 0) ? factorIncrementoVelocidad : -factorIncrementoVelocidad;
    velY += (velY > 0) ? factorIncrementoVelocidad : -factorIncrementoVelocidad;

    // Limitar la velocidad máxima para evitar aumentos exponenciales
    const float velocidadMaxima = 5.0f;
    velX = std::min(std::max(velX, -velocidadMaxima), velocidadMaxima);
    velY = std::min(std::max(velY, -velocidadMaxima), velocidadMaxima);
}

void Pelota::resetearVelocidad() {
    velX = 0.2;
    velY = 0.2;
}
