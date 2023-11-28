// PaletaAutomatica.cpp
#include "PaletaAutomatica.h"

PaletaAutomatica::PaletaAutomatica(float x, float y)
    : speed(0.6f)//VELOCIDAD DE LA PALETA AUTOMATICCCC
{
    shape.setSize(sf::Vector2f(20.0f, 100.0f));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color::Magenta);
}

void PaletaAutomatica::move(float windowHeight)
{
    shape.move(0.0f, speed);

    if (shape.getPosition().y <= 0 || shape.getPosition().y + shape.getSize().y >= windowHeight)
    {
        speed = -speed;
    }
}

sf::RectangleShape& PaletaAutomatica::getShape()
{
    return shape;
}