// Pausa.h
#pragma once
#include <SFML/Graphics.hpp>
#include "pantalla.h"

class Pausa : public Pantalla {
public:
    Pausa(sf::RenderWindow& mainwindow); // Constructor
    int mostrar(); // M�todo para mostrar la pantalla de pausa
    virtual void MoveUp() override; // M�todo para mover la selecci�n hacia arriba
    virtual void MoveDown() override; // M�todo para mover la selecci�n hacia abajo
    int getSelectedOption(); // M�todo para obtener la opci�n seleccionada
    bool shouldReturnToMenu(); // M�todo para verificar si se debe regresar al men� principal

private:
    
    int selectedItemIndex;
    bool returnToMenu;
    sf::Text textoPausa;
    sf::Text reanudarTexto;
    sf::Text salirTexto;
};