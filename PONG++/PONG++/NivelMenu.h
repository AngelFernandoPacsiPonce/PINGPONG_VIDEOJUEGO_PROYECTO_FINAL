#pragma once
#ifndef NIVELMENU_H
#define NIVELMENU_H

#include <SFML/Graphics.hpp>

class NivelMenu {
public:
    NivelMenu(float width, float height);

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int getSelectedNivel();
    bool isBackSelected(); // Nuevo m�todo para verificar la selecci�n de retroceder

private:
    int selectedNivelIndex;
    sf::Font font;
    sf::Text nivelText[4]; // Aumenta el tama�o del arreglo para incluir "RETROCEDER"
    sf::Texture fondoTexture; // Nueva textura para el fondo
    sf::Sprite fondoSprite;   // Nuevo sprite para el fondo
};

#endif
