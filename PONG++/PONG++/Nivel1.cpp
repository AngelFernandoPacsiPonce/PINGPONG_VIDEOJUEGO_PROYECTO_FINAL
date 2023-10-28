#include "Nivel1.h"

Nivel1::Nivel1(int windowWidth, int windowHeight) : window(sf::VideoMode(windowWidth, windowHeight), "PONG C++"), paleta1(30, 250), paleta2(750, 250), pelota(400, 300, "pelota1.png") {
    // Aquí puedes agregar la carga de texturas si es necesario
}

void Nivel1::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            paleta1.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            paleta1.moveDown(window.getSize().y);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            paleta2.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            paleta2.moveDown(window.getSize().y);
        }

        pelota.updatePosition();

        // Calcular el radio de la pelota en función de la textura
        float radioPelota = static_cast<float>(pelota.getSprite().getTexture()->getSize().x) / 2.0f;

        // Colisión de la pelota con las paletas
        if (pelota.getSprite().getGlobalBounds().intersects(paleta1.getShape().getGlobalBounds()) ||
            pelota.getSprite().getGlobalBounds().intersects(paleta2.getShape().getGlobalBounds())) {
            pelota.reverseX();
        }

        // Colisión de la pelota con los bordes de la ventana
        if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - 2 * radioPelota) {
            pelota.reverseX();
        }

        if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - 2 * radioPelota) {
            pelota.reverseY();
        }

        window.clear();
        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(pelota.getSprite());
        window.display();
    }
}
