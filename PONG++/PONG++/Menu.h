#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(float width, float height); // Constructor de la clase Menu

    void draw(sf::RenderWindow& window); // M�todo para dibujar el men� en la ventana
    void MoveUp(); // M�todo para mover la selecci�n hacia arriba
    void MoveDown(); // M�todo para mover la selecci�n hacia abajo
    int getSelectedOption(); // M�todo para obtener la opci�n seleccionada

private:
    int selectedItemIndex; // �ndice de la opci�n seleccionada
    sf::Font font; // Fuente utilizada para el texto
    sf::Text menuText[3]; // Arreglo de objetos de texto para las opciones del men�
    sf::Texture fondoTexture; // Textura para el fondo del men�
    sf::Sprite fondoSprite; // Sprite para mostrar el fondo
};

#endif
