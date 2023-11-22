#pragma once
#include <SFML/Graphics.hpp>

class Creditos {
public:
    Creditos(sf::RenderWindow& window);

    void Mostrar();
    void Retroceder();

private:
    sf::Font font;
    sf::Text textoCreditos;
    sf::Text textoRuth;
    sf::Text textoFernando;
    sf::Text textoRetroceder;
    sf::RenderWindow& window;
};
