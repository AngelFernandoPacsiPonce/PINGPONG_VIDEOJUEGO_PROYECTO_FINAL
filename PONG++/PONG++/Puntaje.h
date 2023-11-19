#pragma once
#include <SFML/Graphics.hpp>

class Puntaje {
public:
    Puntaje(float x, float y, const std::string& fontPath);
    void aumentarPuntaje();
    int getPuntaje();
    void resetearPuntaje();  // Agrega esta funci�n

    sf::Text& getTexto(); // Cambia el retorno de la funci�n

private:
    int puntaje;
    sf::Font font;
    sf::Text texto;
};
