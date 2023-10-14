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

private:
    int selectedNivelIndex;
    sf::Font font;
    sf::Text nivelText[3];
};

#endif // NIVELMENU_H
