#pragma once
#include <SFML/Graphics.hpp>
#include "Pantalla.h"

class Ganador : public Pantalla {
public:
    Ganador(sf::RenderWindow& mainWindow, int ganador); // Constructor
    int mostrar(); // M�todo para mostrar la pantalla de ganador
    virtual void MoveUp() override; // M�todo para mover la selecci�n hacia arriba
    virtual void MoveDown() override; // M�todo para mover la selecci�n hacia abajo
    int getSelectedOption(); // M�todo para obtener la opci�n seleccionada

private:
    int selectedItemIndex;
    sf::Text textoGanador;
    sf::Text reiniciarTexto;
    sf::Text siguienteNivelTexto;
    sf::Text salirTexto;
};
