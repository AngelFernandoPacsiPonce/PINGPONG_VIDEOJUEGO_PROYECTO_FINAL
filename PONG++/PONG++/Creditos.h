// Creditos.h
#pragma once

#include <SFML/Graphics.hpp>

class Creditos {
public:
    Creditos(sf::RenderWindow& window);

    void Mostrar();
    void Retroceder();
    bool getRetrocederSeleccionado() const;

private:
    sf::RenderWindow& window;
    sf::Font font;
    sf::Text textoFernando;
    sf::Text textoRuth;
    sf::Text textoRetroceder;
    sf::Texture fondoTexture;  // Nueva variable para la textura del fondo
    sf::Sprite fondoSprite;    // Nueva variable para el sprite del fondo
    bool retrocederSeleccionado;
};
