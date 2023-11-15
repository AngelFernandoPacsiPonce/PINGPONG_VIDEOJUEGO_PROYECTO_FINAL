#pragma once
#ifndef NIVELMENU_H
#define NIVELMENU_H
#include "pantalla.h"

#include <SFML/Graphics.hpp>

class NivelMenu : public Pantalla {
public:
    NivelMenu(float width, float height);
    void draw(sf::RenderWindow& window); // M�todo para dibujar el men� de selecci�n de niveles
    virtual void MoveUp() override; // M�todo para mover la selecci�n hacia arriba
    virtual void MoveDown() override; // M�todo para mover la selecci�n hacia abajo
    int getSelectedNivel(); // M�todo para obtener el nivel seleccionado
    bool isBackSelected(); // Nuevo m�todo para verificar la selecci�n de retroceder

private:
     
    sf::Text nivelText[4]; // Arreglo de texto para los niveles y retroceder
    sf::Texture fondoTexture; // Textura para el fondo del men�
    sf::Sprite fondoSprite; // Sprite para mostrar el fondo
};

#endif
