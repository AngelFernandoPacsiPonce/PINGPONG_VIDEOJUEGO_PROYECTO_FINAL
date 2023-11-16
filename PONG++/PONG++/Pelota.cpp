#include "Pelota.h"


Pelota::Pelota(float startX, float startY, const std::string& texturaFile) : x(startX), y(startY), radio(60.0f) {
    if (!textura.loadFromFile("pelota1.png")) {
        
    }

    pelota.setTexture(textura);
    pelota.setScale(radio / pelota.getLocalBounds().width, radio / pelota.getLocalBounds().height); // Ajuste de escala
    pelota.setPosition(x - radio-2, y - radio-2); // Ajuste de posición
    velX = 0.3;
    velY = 0.3;
}
//double Pelota::setposition(int x,int y) {
  //  return (x - radio - ancho/2, y - radio - alto/2);
//}
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
void Pelota::setposition(float x, float y) {
    this->x = x;
    this->y = y;
    pelota.setPosition(x - radio - 2, y - radio - 2);
}