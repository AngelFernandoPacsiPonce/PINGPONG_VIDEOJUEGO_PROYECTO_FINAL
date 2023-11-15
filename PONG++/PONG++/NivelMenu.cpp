#include "NivelMenu.h"
#include "pantalla.h"
#include <iostream>
#pragma once
NivelMenu::NivelMenu(float width, float height)
    : Pantalla(window) {

    selectedNivelIndex = 0;
    if (!font.loadFromFile("fuente.ttf")) {
       
        std::cout << "No hay fuente :( " << std::endl;
    }

    // Carga la textura y configura el sprite del fondo
    if (!fondoTexture.loadFromFile("fondomenuseleccion.jpg")) {
        
    }

    fondoSprite.setTexture(fondoTexture);
    fondoSprite.setScale(width / fondoSprite.getGlobalBounds().width, height / fondoSprite.getGlobalBounds().height);

    nivelText[0].setFont(font);
    nivelText[0].setFillColor(sf::Color::Cyan);
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
    nivelText[3].setString("RETROCEDER");
    nivelText[3].setCharacterSize(30);
    nivelText[3].setPosition(sf::Vector2f(width - 300, height - 100));

    selectedNivelIndex = 0; // "NIVEL 1" seleccionado inicialmente
}

void NivelMenu::draw(sf::RenderWindow& window) {
    // Dibuja el fondo antes de los elementos de texto
    window.draw(fondoSprite);

    for (int i = 0; i < 4; i++) {
        window.draw(nivelText[i]);
    }
}

void NivelMenu::MoveUp() {
    nivelText[selectedNivelIndex].setFillColor(sf::Color::White);
    selectedNivelIndex = (selectedNivelIndex - 1 + 4) % 4;
    nivelText[selectedNivelIndex].setFillColor(sf::Color::Cyan);
}

void NivelMenu::MoveDown() {
    nivelText[selectedNivelIndex].setFillColor(sf::Color::White);
    selectedNivelIndex = (selectedNivelIndex + 1) % 4;
    nivelText[selectedNivelIndex].setFillColor(sf::Color::Cyan);
}

int NivelMenu::getSelectedNivel() {
    return selectedNivelIndex;
}

bool NivelMenu::isBackSelected() {
    return selectedNivelIndex == 3;
}
