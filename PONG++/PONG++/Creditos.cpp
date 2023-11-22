#include "Creditos.h"

Creditos::Creditos(sf::RenderWindow& window)
    : window(window) {
    if (!font.loadFromFile("fuentenivel1.ttf")) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    textoFernando.setFont(font);
    textoFernando.setCharacterSize(30);
    textoFernando.setString("Fernando");
    textoFernando.setFillColor(sf::Color::White);

    // Ajusta la posición para colocar el texto en el centro izquierda
    textoFernando.setPosition(static_cast<float>(window.getSize().x) / 4, static_cast<float>(window.getSize().y) / 2 - 20);

    textoRuth.setFont(font);
    textoRuth.setCharacterSize(30);
    textoRuth.setString("Ruth");
    textoRuth.setFillColor(sf::Color::White);

    // Ajusta la posición para colocar el texto en el centro derecha
    textoRuth.setPosition(static_cast<float>(3 * window.getSize().x) / 4, static_cast<float>(window.getSize().y) / 2 - 20);

    textoRetroceder.setPosition(20, static_cast<float>(window.getSize().y) - 20);
    textoRetroceder.setFont(font);
    textoRetroceder.setFillColor(sf::Color::Cyan);
    textoRetroceder.setString("RETROCEDER");
    textoRetroceder.setCharacterSize(30);
    textoRetroceder.setOrigin(0, textoRetroceder.getLocalBounds().height);  // Ajusta el origen a la parte inferior del texto
}

void Creditos::Mostrar() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Return) {
                    Retroceder();
                    return;
                }
            }
        }

        window.clear();
        window.draw(textoFernando);
        window.draw(textoRuth);
        window.draw(textoRetroceder);
        window.display();
    }
}

void Creditos::Retroceder() {
    // Código para redirigir al menú principal
    window.clear();
    window.display();
}
