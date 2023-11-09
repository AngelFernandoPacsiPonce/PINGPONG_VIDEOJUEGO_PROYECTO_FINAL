// Pausa.h
#pragma once
#include <SFML/Graphics.hpp>

class Pausa {
public:
    Pausa(sf::RenderWindow& window); // Constructor
    int mostrar(); // Método para mostrar la pantalla de pausa
    void MoveUp(); // Método para mover la selección hacia arriba
    void MoveDown(); // Método para mover la selección hacia abajo
    int getSelectedOption(); // Método para obtener la opción seleccionada
    bool shouldReturnToMenu(); // Método para verificar si se debe regresar al menú principal

private:
    sf::RenderWindow& window; // Referencia a la ventana principal
    sf::Font font; // Fuente para el texto
    sf::Text textoPausa; // Texto que indica pausa
    sf::Text reanudarTexto; // Texto para la opción de reanudar
    sf::Text salirTexto; // Texto para la opción de salir
    int selectedItemIndex; // Índice de la opción seleccionada
    bool returnToMenu; // Bandera para indicar si se debe regresar al menú principal
};
