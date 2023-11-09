// Pausa.h
#pragma once
#include <SFML/Graphics.hpp>

class Pausa {
public:
    Pausa(sf::RenderWindow& window); // Constructor
    int mostrar(); // M�todo para mostrar la pantalla de pausa
    void MoveUp(); // M�todo para mover la selecci�n hacia arriba
    void MoveDown(); // M�todo para mover la selecci�n hacia abajo
    int getSelectedOption(); // M�todo para obtener la opci�n seleccionada
    bool shouldReturnToMenu(); // M�todo para verificar si se debe regresar al men� principal

private:
    sf::RenderWindow& window; // Referencia a la ventana principal
    sf::Font font; // Fuente para el texto
    sf::Text textoPausa; // Texto que indica pausa
    sf::Text reanudarTexto; // Texto para la opci�n de reanudar
    sf::Text salirTexto; // Texto para la opci�n de salir
    int selectedItemIndex; // �ndice de la opci�n seleccionada
    bool returnToMenu; // Bandera para indicar si se debe regresar al men� principal
};
