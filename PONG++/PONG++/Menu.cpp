#include "Menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fuente.ttf")) {
        //FUENTE BUSCALA TU
    }

    menuText[0].setFont(font);
    menuText[0].setFillColor(sf::Color::Red);
    menuText[0].setString("PONG I I ");
    menuText[0].setCharacterSize(80); // TAMAÑO TEXTO TITULO
    menuText[0].setPosition(sf::Vector2f(width / 2 - 200, height / 3 - 50)); // Ajusta las coordenadas X y Y

    menuText[1].setFont(font);
    menuText[1].setFillColor(sf::Color::White);
    menuText[1].setString("JUGAR");
    menuText[1].setCharacterSize(40); // TAMAÑO TEXTO JUGAR
    menuText[1].setPosition(sf::Vector2f(width / 2 - 40, height / 2 + 50)); //  X y Y

    menuText[2].setFont(font);
    menuText[2].setFillColor(sf::Color::White);
    menuText[2].setString("SALIR");
    menuText[2].setCharacterSize(40); // TAMAÑO TEXTO SALIR
    menuText[2].setPosition(sf::Vector2f(width / 2 - 40, height / 2 + 150)); // oordenadas X y Y

    selectedItemIndex = 1; // "JUGAR" seleccionado inicialmente
}

void Menu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(menuText[i]);
    }
}

void Menu::MoveUp() {
    if (selectedItemIndex - 1 >= 1) {
        menuText[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex--;
        menuText[selectedItemIndex].setFillColor(sf::Color::Cyan);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex + 1 < 3) {
        menuText[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex++;
        menuText[selectedItemIndex].setFillColor(sf::Color::Cyan);
    }
}

int Menu::getSelectedOption() {
    return selectedItemIndex;
}
