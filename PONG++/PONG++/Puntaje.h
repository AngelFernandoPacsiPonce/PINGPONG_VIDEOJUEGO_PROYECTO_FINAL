#pragma once
#include <SFML/Graphics.hpp>

class Puntaje {
public:
    // Constructor predeterminado
    Puntaje();

    // Constructor que recibe la fuente
    Puntaje(sf::Font& font);

    void aumentarIzquierda();
    void aumentarDerecha();
    int getPuntosIzquierda();
    int getPuntosDerecha();
    void resetear();
    void dibujar(sf::RenderWindow& window);

private:
    int puntosIzquierda;
    int puntosDerecha;
    sf::Text textoIzquierda;
    sf::Text textoDerecha;
};
