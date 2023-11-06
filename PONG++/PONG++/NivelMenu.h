#pragma once
#ifndef NIVELMENU_H
#define NIVELMENU_H

#include <SFML/Graphics.hpp>

class NivelMenu {
public:
    NivelMenu(float width, float height); // Constructor de la clase NivelMenu
    void draw(sf::RenderWindow& window); // M�todo para dibujar el men� de selecci�n de niveles
    void MoveUp(); // M�todo para mover la selecci�n hacia arriba
    void MoveDown(); // M�todo para mover la selecci�n hacia abajo
    int getSelectedNivel(); // M�todo para obtener el nivel seleccionado
    bool isBackSelected(); // Nuevo m�todo para verificar la selecci�n de retroceder

private:
    int selectedNivelIndex; // �ndice del nivel seleccionado
    sf::Font font; // Fuente utilizada para el texto
    sf::Text nivelText[4]; // Arreglo de texto para los niveles y retroceder
    sf::Texture fondoTexture; // Textura para el fondo del men�
    sf::Sprite fondoSprite; // Sprite para mostrar el fondo
};

#endif
