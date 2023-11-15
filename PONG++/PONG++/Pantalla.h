// Pantalla.h
#pragma once
#include <SFML/Graphics.hpp>

class Pantalla {
public:
    Pantalla(sf::RenderWindow& window);
    virtual ~Pantalla() = default;
    virtual void MoveUp() = 0;
    virtual void MoveDown() = 0;

protected:
    int selectedNivelIndex;
    sf::Font font;
    sf::RenderWindow& window;
};
