#pragma once
#include <SFML/Graphics.hpp>

class Puntaje {
public:
    Puntaje(float x, float y, const std::string& fuentePath);
    void aumentarPuntaje();
    void reiniciarPuntaje();
    void actualizarTexto();

    sf::Text getTexto();
    unsigned int getPuntaje();

private:
    unsigned int puntaje;
    sf::Font fuente;
    sf::Text textoPuntaje;
};


