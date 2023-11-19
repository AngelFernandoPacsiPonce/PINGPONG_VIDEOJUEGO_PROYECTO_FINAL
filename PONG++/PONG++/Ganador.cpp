#include "Ganador.h"
#include "Pantalla.h"

Ganador::Ganador(sf::RenderWindow& mainWindow, int ganador)
    : Pantalla(mainWindow), selectedItemIndex(0) {
    if (!font.loadFromFile("fuente.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    textoGanador.setFont(font);
    textoGanador.setCharacterSize(50);
    textoGanador.setString("GANADOR: JUGADOR " + std::to_string(ganador));
    textoGanador.setFillColor(sf::Color::Yellow);

    reiniciarTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2 - 100.0f, static_cast<float>(Pantalla::window.getSize().y) / 2.0f);
    siguienteNivelTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2 - 100.0f, static_cast<float>(Pantalla::window.getSize().y) / 2.0f + 50.0f);
    salirTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2 - 100.0f, static_cast<float>(Pantalla::window.getSize().y) / 2.0f + 100.0f);

    reiniciarTexto.setCharacterSize(20);
    reiniciarTexto.setString("Reiniciar Partida");

    siguienteNivelTexto.setCharacterSize(20);
    siguienteNivelTexto.setString("Siguiente Nivel");

    salirTexto.setCharacterSize(20);
    salirTexto.setString("Salir");
}

int Ganador::mostrar() {
    selectedItemIndex = 0; // Reiniciamos la selección al mostrar la pantalla de ganador

    while (true) {
        window.clear();
        window.draw(textoGanador);
        window.draw(reiniciarTexto);
        window.draw(siguienteNivelTexto);
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
                    return getSelectedOption();
                }
            }
        }
    }
}

void Ganador::MoveUp() {
    if (selectedItemIndex > 0) {
        reiniciarTexto.setFillColor(sf::Color::White);
        siguienteNivelTexto.setFillColor(sf::Color::White);
        salirTexto.setFillColor(sf::Color::White);
        selectedItemIndex--;
        if (selectedItemIndex == 0) {
            reiniciarTexto.setFillColor(sf::Color::Cyan);
        }
        else if (selectedItemIndex == 1) {
            siguienteNivelTexto.setFillColor(sf::Color::Cyan);
        }
        else {
            salirTexto.setFillColor(sf::Color::Cyan);
        }
    }
}

void Ganador::MoveDown() {
    if (selectedItemIndex < 2) {
        reiniciarTexto.setFillColor(sf::Color::White);
        siguienteNivelTexto.setFillColor(sf::Color::White);
        salirTexto.setFillColor(sf::Color::White);
        selectedItemIndex++;
        if (selectedItemIndex == 0) {
            reiniciarTexto.setFillColor(sf::Color::Cyan);
        }
        else if (selectedItemIndex == 1) {
            siguienteNivelTexto.setFillColor(sf::Color::Cyan);
        }
        else {
            salirTexto.setFillColor(sf::Color::Cyan);
        }
    }
}

int Ganador::getSelectedOption() {
    return selectedItemIndex;
}
