#include "Ganador.h"
#include "Pantalla.h"
#include <iostream>

Ganador::Ganador(sf::RenderWindow& mainWindow, int ganador)
    : Pantalla(mainWindow), selectedItemIndex(0) {
    if (!font.loadFromFile("fuentenivel1.ttf")) {
        
    }

    // Configuración del texto de ganador
    textoGanador.setFont(font);
    textoGanador.setCharacterSize(50);
    textoGanador.setString("GANADOR: JUGADOR " + std::to_string(ganador));
    textoGanador.setFillColor(sf::Color::Yellow);
    sf::FloatRect textBounds = textoGanador.getLocalBounds();
    textoGanador.setOrigin(textBounds.width / 2.0f, textBounds.height / 2.0f);
    textoGanador.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2.0f,
        static_cast<float>(Pantalla::window.getSize().y) / 4.0f);

    // Configuración de la opción de reiniciar
    reiniciarTexto.setFont(font);
    reiniciarTexto.setCharacterSize(20);
    reiniciarTexto.setString("Reiniciar Partida");
    reiniciarTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2.0f - 110.0f,
        static_cast<float>(Pantalla::window.getSize().y) / 2.0f - 25.0f);
    reiniciarTexto.setFillColor(sf::Color::Cyan);  // Reiniciar seleccionado inicialmente

    // Configuración de la opción de siguiente nivel
    siguienteNivelTexto.setFont(font);
    siguienteNivelTexto.setCharacterSize(20);
    siguienteNivelTexto.setString("Siguiente Nivel");
    siguienteNivelTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2.0f - 110.0f,
        static_cast<float>(Pantalla::window.getSize().y) / 2.0f + 25.0f);

    // Configuración de la opción de salir
    salirTexto.setFont(font);
    salirTexto.setCharacterSize(20);
    salirTexto.setString("Salir");
    salirTexto.setPosition(static_cast<float>(Pantalla::window.getSize().x) / 2.0f - 110.0f,
        static_cast<float>(Pantalla::window.getSize().y) / 2.0f + 75.0f);

    
}

int Ganador::mostrar() {
    selectedItemIndex = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::KeyReleased) {
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

        window.clear();
        window.draw(textoGanador);
        window.draw(reiniciarTexto);
        window.draw(siguienteNivelTexto);
        window.draw(salirTexto);
        window.display();

        
    }

    return 0;
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

void Ganador::Reiniciar() {
    // Lógica para reiniciar el juego
}

void Ganador::SiguienteNivel() {
    // Lógica para pasar al siguiente nivel
}

void Ganador::Salir() {
    // Lógica para salir al menú principal
}
