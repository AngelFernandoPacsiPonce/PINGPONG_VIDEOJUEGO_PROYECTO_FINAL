#pragma once
#include <SFML/Graphics.hpp>
#include "Pantalla.h"

class Ganador : public Pantalla {
public:
    Ganador(sf::RenderWindow& mainWindow, int ganador); // Constructor
    int mostrar(); // Método para mostrar la pantalla de ganador
    virtual void MoveUp() override; // Método para mover la selección hacia arriba
    virtual void MoveDown() override; // Método para mover la selección hacia abajo
    int getSelectedOption(); // Método para obtener la opción seleccionada

private:
    int selectedItemIndex;
    sf::Text textoGanador;
    sf::Text reiniciarTexto;
    sf::Text siguienteNivelTexto;
    sf::Text salirTexto;
};
