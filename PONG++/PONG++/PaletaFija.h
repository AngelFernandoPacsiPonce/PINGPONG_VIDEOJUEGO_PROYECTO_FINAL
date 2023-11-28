#pragma once

#include <SFML/Graphics.hpp>

class PaletaFija {
public:
    PaletaFija(float x, float y);
    sf::RectangleShape getShape() const;
    void setPosition(float x, float y);
    void setColor(sf::Color color); // Agregada la declaraci�n de la funci�n setColor

private:
    sf::RectangleShape paletaShape;
};
