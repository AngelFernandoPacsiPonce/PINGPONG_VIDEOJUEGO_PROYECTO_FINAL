#pragma once

#include <SFML/Graphics.hpp>

class PaletaFija {
public:
    PaletaFija(float x, float y);
    sf::RectangleShape getShape() const;
    void setPosition(float x, float y); // Nuevo método para cambiar la posición de la paleta

private:
    sf::RectangleShape paletaShape;
};
