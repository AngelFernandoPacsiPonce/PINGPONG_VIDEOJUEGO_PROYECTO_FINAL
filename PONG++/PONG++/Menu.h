#pragma once
#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu {
public:
    Menu(float width, float height);

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();
    int getSelectedOption();

private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menuText[3];
};

#endif 
