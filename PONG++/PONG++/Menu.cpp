#include "Menu.h"

Menu::Menu(float width, float height) {
    if (!font.loadFromFile("fuente.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
        // Puedes agregar aquí un mensaje de error o acciones específicas en caso de falla.
    }

    // Carga la textura y configura el sprite del fondo
    if (!fondoTexture.loadFromFile("fondomenuprincipal.jpg")) {
        // Manejo de errores si no se puede cargar la textura del fondo.
        // Puedes agregar aquí un mensaje de error o acciones específicas en caso de falla.
    }

    fondoSprite.setTexture(fondoTexture);
    fondoSprite.setScale(width / fondoSprite.getGlobalBounds().width, height / fondoSprite.getGlobalBounds().height);

    menuText[0].setFont(font);
    menuText[0].setFillColor(sf::Color::Yellow);
    menuText[0].setString("PONG + +");
    menuText[0].setCharacterSize(110);
    menuText[0].setPosition(sf::Vector2f(width / 2 - 250, height / 3 - 50));

    menuText[1].setFont(font);
    menuText[1].setFillColor(sf::Color::Cyan);
    menuText[1].setString("JUGAR");
    menuText[1].setCharacterSize(40);
    menuText[1].setPosition(sf::Vector2f(width / 2 - 90, height / 2 + 50));

    menuText[2].setFont(font);
    menuText[2].setFillColor(sf::Color::White);
    menuText[2].setString("SALIR");
    menuText[2].setCharacterSize(40);
    menuText[2].setPosition(sf::Vector2f(width / 2 - 90, height / 2 + 150));

    selectedItemIndex = 1; // "JUGAR" seleccionado inicialmente
}

void Menu::draw(sf::RenderWindow& window) {
    // Dibuja el fondo antes de los elementos de texto
    window.draw(fondoSprite);

    for (int i = 0; i < 3; i++) {
        window.draw(menuText[i]);
    }
}

void Menu::MoveUp() {
    if (selectedItemIndex != 1) {
        menuText[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex = 1;
        menuText[selectedItemIndex].setFillColor(sf::Color::Cyan);
    }
}

void Menu::MoveDown() {
    if (selectedItemIndex != 2) {
        menuText[selectedItemIndex].setFillColor(sf::Color::White);
        selectedItemIndex = 2;
        menuText[selectedItemIndex].setFillColor(sf::Color::Cyan);
    }
}

int Menu::getSelectedOption() {
    return selectedItemIndex;
}
