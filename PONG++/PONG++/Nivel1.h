#pragma once
#include <SFML/Graphics.hpp>
#include "Pelota.h"
#include "Paleta.h"

class Nivel1 {
public:
    Nivel1(int windowWidth, int windowHeight);
    void run();

private:
    sf::RenderWindow window;
    Paleta paleta1;
    Paleta paleta2;
    Pelota pelota;
};
