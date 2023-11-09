#include "Nivel1.h"
#include "Musica.h"

Nivel1::Nivel1(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow), paleta1(30, 250), paleta2(1150, 250), pelota(400, 300, "pelota1.png"), musica(music)
{
    musica.cargarMusicaNivel1();
    musica.reproducirNivel1();
}

void Nivel1::run() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            paleta1.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            paleta1.moveDown(window.getSize().y);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            paleta2.moveUp();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            paleta2.moveDown(window.getSize().y);
        }

        pelota.updatePosition();

        // Obtén el radio de la pelota
        float radioPelota = pelota.getRadio();

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
