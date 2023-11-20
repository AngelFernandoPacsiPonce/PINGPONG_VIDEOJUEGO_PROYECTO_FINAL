// Pausa.cpp
#include "Pausa.h"
#include "pantalla.h"
#pragma once

Pausa::Pausa(sf::RenderWindow& mainWindow)
    : Pantalla(mainWindow), selectedItemIndex(0), returnToMenu(false) {
    if (!font.loadFromFile("fuente.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    textoPausa.setFont(font);
    textoPausa.setCharacterSize(50);
    textoPausa.setString("PAUSA");
    textoPausa.setFillColor(sf::Color::Yellow);

    // Ajuste de las posiciones y tamaños de los textos
    reanudarTexto.setCharacterSize(30);
    reanudarTexto.setString("Reanudar");
    reanudarTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2 - 80, static_cast<float>(Pantalla::window.getSize().y) / 2 - 20);

    salirTexto.setCharacterSize(30);
    salirTexto.setString("Salir");
    salirTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2 - 50, static_cast<float>(Pantalla::window.getSize().y) / 2 + 20);
}


int Pausa::mostrar() {
    selectedItemIndex = 0; // Reiniciamos la selección al mostrar la pantalla de pausa
    returnToMenu = false; // Reiniciamos la bandera

    while (true) {
        window.clear();
        window.draw(textoPausa);
        window.draw(reanudarTexto);
        window.draw(salirTexto);
        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    MoveUp();
                }
                else if (event.key.code == sf::Keyboard::Down) {
                    MoveDown();
                }
                else if (event.key.code == sf::Keyboard::Return) {
                    if (getSelectedOption() == 0) {
                        // Reanudar el juego
                        return getSelectedOption();
                    }
                    else if (getSelectedOption() == 1) {
                        // Salir al Menú
                        returnToMenu = true;
                        return getSelectedOption();
                    }
                }
            }
        }
    }
}

void Pausa::MoveUp() {
    if (selectedItemIndex > 0) {
        reanudarTexto.setFillColor(sf::Color::White);
        salirTexto.setFillColor(sf::Color::White);
        selectedItemIndex--;
        if (selectedItemIndex == 0) {
            reanudarTexto.setFillColor(sf::Color::Cyan);
        }
        else {
            salirTexto.setFillColor(sf::Color::Cyan);
        }
    }
}

void Pausa::MoveDown() {
    if (selectedItemIndex < 1) {
        reanudarTexto.setFillColor(sf::Color::White);
        salirTexto.setFillColor(sf::Color::White);
        selectedItemIndex++;
        if (selectedItemIndex == 0) {
            reanudarTexto.setFillColor(sf::Color::Cyan);
        }
        else {
            salirTexto.setFillColor(sf::Color::Cyan);
        }
    }
}

int Pausa::getSelectedOption() {
    return selectedItemIndex;
}

bool Pausa::shouldReturnToMenu() {
    return returnToMenu;
}
