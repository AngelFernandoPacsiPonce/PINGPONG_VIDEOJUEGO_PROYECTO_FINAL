// Pausa.h
#pragma once
#include <SFML/Graphics.hpp>
#include "pantalla.h"

class Pausa : public Pantalla {
public:
    Pausa(sf::RenderWindow& mainwindow); // Constructor
    int mostrar(); // Método para mostrar la pantalla de pausa
    virtual void MoveUp() override; // Método para mover la selección hacia arriba
    virtual void MoveDown() override; // Método para mover la selección hacia abajo
    int getSelectedOption(); // Método para obtener la opción seleccionada
    bool shouldReturnToMenu(); // Método para verificar si se debe regresar al menú principal

private:
    
    int selectedItemIndex;
    bool returnToMenu;
    sf::Text textoPausa;
    sf::Text reanudarTexto;
    sf::Text salirTexto;
};