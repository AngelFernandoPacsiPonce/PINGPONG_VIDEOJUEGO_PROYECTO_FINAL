#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota(float startX, float startY, const std::string& texturaFile);
    void updatePosition();
    void reverseX();
    void reverseY();
    void setPosition(float x, float y);
    sf::Sprite getSprite();
    float getRadio();
    void incrementarVelocidad();  // Nuevo método para incrementar la velocidad
    void resetearVelocidad();     // Nuevo método para resetear la velocidad

private:
    float x, y;
    float velX, velY;
    sf::Sprite pelota;
    float radio;
    sf::Texture textura;
    float factorIncrementoVelocidad;  // Nuevo miembro para controlar el incremento de velocidad
};
