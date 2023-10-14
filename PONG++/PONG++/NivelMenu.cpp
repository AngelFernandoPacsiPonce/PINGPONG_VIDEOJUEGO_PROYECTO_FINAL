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

    selectedNivelIndex = 0; // Iniciar con el primer nivel seleccionado
}

void NivelMenu::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 3; i++) {
        window.draw(nivelText[i]);
    }
}

void NivelMenu::MoveUp() {
    nivelText[selectedNivelIndex].setFillColor(sf::Color::White);
    selectedNivelIndex = (selectedNivelIndex - 1 + 3) % 3; // Para permitir ciclar hacia arriba
    nivelText[selectedNivelIndex].setFillColor(sf::Color::Cyan);
}

void NivelMenu::MoveDown() {
    nivelText[selectedNivelIndex].setFillColor(sf::Color::White);
    selectedNivelIndex = (selectedNivelIndex + 1) % 3; // Para permitir ciclar hacia abajo
    nivelText[selectedNivelIndex].setFillColor(sf::Color::Cyan);
}

int NivelMenu::getSelectedNivel() {
    return selectedNivelIndex;
}
