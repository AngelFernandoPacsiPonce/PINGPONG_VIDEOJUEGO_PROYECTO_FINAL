// PaletaAutomatica.h
#pragma once

#include <SFML/Graphics.hpp>

class PaletaAutomatica {
public:
    PaletaAutomatica(float x, float y);
    void move(float windowHeight);

    sf::RectangleShape& getShape();

private:
    sf::RectangleShape shape;
    float speed;
};