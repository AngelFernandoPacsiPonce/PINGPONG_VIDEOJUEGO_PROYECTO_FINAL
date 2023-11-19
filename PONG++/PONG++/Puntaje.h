#pragma once
#include <SFML/Graphics.hpp>

class Puntaje {
public:
    Puntaje(float x, float y, const std::string& fontPath);
    void aumentarPuntaje();
    int getPuntaje();
    void resetearPuntaje();  // Agrega esta función

    sf::Text& getTexto(); // Cambia el retorno de la función

private:
    int puntaje;
    sf::Font font;
    sf::Text texto;
};
