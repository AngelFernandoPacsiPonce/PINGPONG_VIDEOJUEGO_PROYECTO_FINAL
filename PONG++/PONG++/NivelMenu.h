#pragma once
#ifndef NIVELMENU_H
#define NIVELMENU_H

#include <SFML/Graphics.hpp>

class NivelMenu {
public:
    NivelMenu(float width, float height); // Constructor de la clase NivelMenu
    void draw(sf::RenderWindow& window); // Método para dibujar el menú de selección de niveles
    void MoveUp(); // Método para mover la selección hacia arriba
    void MoveDown(); // Método para mover la selección hacia abajo
    int getSelectedNivel(); // Método para obtener el nivel seleccionado
    bool isBackSelected(); // Nuevo método para verificar la selección de retroceder

private:
    int selectedNivelIndex; // Índice del nivel seleccionado
    sf::Font font; // Fuente utilizada para el texto
    sf::Text nivelText[4]; // Arreglo de texto para los niveles y retroceder
    sf::Texture fondoTexture; // Textura para el fondo del menú
    sf::Sprite fondoSprite; // Sprite para mostrar el fondo
};

#endif
