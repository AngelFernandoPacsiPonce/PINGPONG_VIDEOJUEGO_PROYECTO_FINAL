#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(float width, float height); // Constructor de la clase Menu

    void draw(sf::RenderWindow& window); // Método para dibujar el menú en la ventana
    void MoveUp(); // Método para mover la selección hacia arriba
    void MoveDown(); // Método para mover la selección hacia abajo
    int getSelectedOption(); // Método para obtener la opción seleccionada

private:
    int selectedItemIndex; // Índice de la opción seleccionada
    sf::Font font; // Fuente utilizada para el texto
    sf::Text menuText[3]; // Arreglo de objetos de texto para las opciones del menú
    sf::Texture fondoTexture; // Textura para el fondo del menú
    sf::Sprite fondoSprite; // Sprite para mostrar el fondo
};

#endif
