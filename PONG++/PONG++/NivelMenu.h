#pragma once
#ifndef NIVELMENU_H
#define NIVELMENU_H
#include "pantalla.h"

#include <SFML/Graphics.hpp>

class NivelMenu : public Pantalla {
public:
    NivelMenu(float width, float height);
    void draw(sf::RenderWindow& window); // Método para dibujar el menú de selección de niveles
    virtual void MoveUp() override; // Método para mover la selección hacia arriba
    virtual void MoveDown() override; // Método para mover la selección hacia abajo
    int getSelectedNivel(); // Método para obtener el nivel seleccionado
    bool isBackSelected(); // Nuevo método para verificar la selección de retroceder

private:
     
    sf::Text nivelText[4]; // Arreglo de texto para los niveles y retroceder
    sf::Texture fondoTexture; // Textura para el fondo del menú
    sf::Sprite fondoSprite; // Sprite para mostrar el fondo
};

#endif
