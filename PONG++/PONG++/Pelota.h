#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
public:
    Pelota(float startX, float startY, const std::string& texturaFile);
    void updatePosition();
    void reverseX();
    void reverseY();
    //double setposition(int x,int y);
    sf::Sprite getSprite();
    float getRadio(); 
    // Agrega este método
    void setposition(float x, float y);

private:
    float x, y;
    float velX, velY;
    sf::Sprite pelota;
    float radio;
    sf::Texture textura;
};
