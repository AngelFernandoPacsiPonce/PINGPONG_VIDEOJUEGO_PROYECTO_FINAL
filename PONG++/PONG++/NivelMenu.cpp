#include "NivelMenu.h"

NivelMenu::NivelMenu(float width, float height) {
    if (!font.loadFromFile("fuente.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    nivelText[0].setFont(font);
    nivelText[0].setFillColor(sf::Color::Red); // Cambiar el color inicial al primer nivel
    nivelText[0].setString("NIVEL 1");
    nivelText[0].setCharacterSize(40);
    nivelText[0].setPosition(sf::Vector2f(width / 2 - 40, height / 3));

    nivelText[1].setFont(font);
    nivelText[1].setFillColor(sf::Color::White);
    nivelText[1].setString("NIVEL 2");
    nivelText[1].setCharacterSize(40);
    nivelText[1].setPosition(sf::Vector2f(width / 2 - 40, height / 2));

    nivelText[2].setFont(font);
    nivelText[2].setFillColor(sf::Color::White);
    nivelText[2].setString("NIVEL 3");
    nivelText[2].setCharacterSize(40);
    nivelText[2].setPosition(sf::Vector2f(width / 2 - 40, height / 2 + 100));

    nivelText[3].setFont(font);
    nivelText[3].setFillColor(sf::Color::White);
    nivelText[3].setString("RETROCEDER"); // Texto para retroceder
    nivelText[3].setCharacterSize(30);
    nivelText[3].setPosition(sf::Vector2f(width - 300, height - 100));

    selectedNivelIndex = 0; // Iniciar con el primer nivel seleccionado
}

void NivelMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 4; i++) { // Aumenta el tamaño del arreglo en el bucle
        window.draw(nivelText[i]);
    }
}

void NivelMenu::MoveUp() {
    nivelText[selectedNivelIndex].setFillColor(sf::Color::White);
    selectedNivelIndex = (selectedNivelIndex - 1 + 4) % 4; // Aumenta el módulo a 4
    nivelText[selectedNivelIndex].setFillColor(sf::Color::Cyan);
}

void NivelMenu::MoveDown() {
    nivelText[selectedNivelIndex].setFillColor(sf::Color::White);
    selectedNivelIndex = (selectedNivelIndex + 1) % 4; // Aumenta el módulo a 4
    nivelText[selectedNivelIndex].setFillColor(sf::Color::Cyan);
}

int NivelMenu::getSelectedNivel() {
    return selectedNivelIndex;
}

bool NivelMenu::isBackSelected() {
    return selectedNivelIndex == 3; // Devuelve verdadero si "RETROCEDER" está seleccionado
}
