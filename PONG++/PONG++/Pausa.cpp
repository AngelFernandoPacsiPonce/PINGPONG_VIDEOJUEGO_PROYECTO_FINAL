#include "Pausa.h"
#include "pantalla.h"
#include <iostream>

Pausa::Pausa(sf::RenderWindow& mainWindow) : Pantalla(mainWindow), selectedItemIndex(0), returnToMenu(false) {
    if (!font.loadFromFile("fuentenivel1.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    // Ajuste para centrar horizontalmente
    float centerX = static_cast<float>(Pantalla::window.getSize().x) / 2;
    float centerY = static_cast<float>(Pantalla::window.getSize().y) / 2;

    textoPausa.setFont(font);
    textoPausa.setCharacterSize(80);
    textoPausa.setString("PAUSA");
    textoPausa.setFillColor(sf::Color::Yellow);
    textoPausa.setPosition(centerX - textoPausa.getLocalBounds().width / 2, centerY - 100);

    reanudarTexto.setFont(font);
    reanudarTexto.setCharacterSize(30);
    reanudarTexto.setString("Reanudar");
    reanudarTexto.setPosition(centerX - reanudarTexto.getLocalBounds().width / 2, centerY);
    reanudarTexto.setFillColor(sf::Color::Cyan);  // Color por defecto

    salirTexto.setFont(font);
    salirTexto.setCharacterSize(30);
    salirTexto.setString("Salir al Menu");
    salirTexto.setPosition(centerX - salirTexto.getLocalBounds().width / 2, centerY + 50);
    salirTexto.setFillColor(sf::Color::White);  // Color por defecto
}

int Pausa::mostrar() {
    selectedItemIndex = 0;
    returnToMenu = false;

    while (!returnToMenu) {
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
                        return getSelectedOption();
                    }
                    else if (getSelectedOption() == 1) {
                        returnToMenu = true;
                        return getSelectedOption();
                    }
                }
            }
        }
    }

    return 0;
}

void Pausa::MoveUp() {
    if (selectedItemIndex > 0) {
        selectedItemIndex--;
    }
    else {
        selectedItemIndex = 1;
    }

    reanudarTexto.setFillColor(selectedItemIndex == 0 ? sf::Color::Cyan : sf::Color::White);
    salirTexto.setFillColor(selectedItemIndex == 1 ? sf::Color::Cyan : sf::Color::White);
}

void Pausa::MoveDown() {
    if (selectedItemIndex < 1) {
        selectedItemIndex++;
    }
    else {
        selectedItemIndex = 0;
    }

    reanudarTexto.setFillColor(selectedItemIndex == 0 ? sf::Color::Cyan : sf::Color::White);
    salirTexto.setFillColor(selectedItemIndex == 1 ? sf::Color::Cyan : sf::Color::White);
}

int Pausa::getSelectedOption() {
    return selectedItemIndex;
}

bool Pausa::shouldReturnToMenu() {
    return returnToMenu;
}

