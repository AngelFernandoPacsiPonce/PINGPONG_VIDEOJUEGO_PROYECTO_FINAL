// Creditos.cpp
#include "Creditos.h"
#include <iostream>

Creditos::Creditos(sf::RenderWindow& window)
    : window(window), retrocederSeleccionado(false) {
    // Cargar el fondo
    if (!fondoTexture.loadFromFile("fondocreditos.png")) {
        // Manejo de errores si no se puede cargar el fondo
    }
    fondoSprite.setTexture(fondoTexture);

    if (!font.loadFromFile("fuentenivel1.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    textoFernando.setFont(font);
    textoFernando.setCharacterSize(50);
    textoFernando.setString("Fernando");
    textoFernando.setFillColor(sf::Color::Blue);
    textoFernando.setPosition(static_cast<float>(0.9 * window.getSize().x) / 5, static_cast<float>(window.getSize().y) / 2 - 220);

    textoRuth.setFont(font);
    textoRuth.setCharacterSize(50);
    textoRuth.setString("Ruth");
    textoRuth.setFillColor(sf::Color::Green);
    textoRuth.setPosition(static_cast<float>(3.3 * window.getSize().x) / 5, static_cast<float>(window.getSize().y) / 2 - 220);

    float retrocederX = 900;  // Ajusta el valor 20 según tu preferencia
    float retrocederY = static_cast<float>(window.getSize().y) - textoRetroceder.getLocalBounds().height - 50;  // Ajusta el valor 20 según tu preferencia
    textoRetroceder.setPosition(retrocederX, retrocederY);
    textoRetroceder.setFont(font);
    textoRetroceder.setFillColor(sf::Color::Cyan);
    textoRetroceder.setString("RETROCEDER");
    textoRetroceder.setCharacterSize(30);
    textoRetroceder.setOrigin(0, textoRetroceder.getLocalBounds().height);  // Ajusta el origen a la parte inferior del texto
}

void Creditos::Mostrar() {
    retrocederSeleccionado = false;  // Reiniciamos el estado

    while (window.isOpen() && !retrocederSeleccionado) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Return) {
                    Retroceder();
             
 
                    return;  // Salir de la función después de procesar el evento de retroceso
                }
            }
        }

        window.clear();

        // Dibujar el fondo
        window.draw(fondoSprite);

        // Dibujar el resto de los elementos
        window.draw(textoFernando);
        window.draw(textoRuth);
        window.draw(textoRetroceder);

        window.display();
    }
}

void Creditos::Retroceder() {
    // Código para redirigir al menú principal
    retrocederSeleccionado = true;

}

bool Creditos::getRetrocederSeleccionado() const {
    return retrocederSeleccionado;
}
