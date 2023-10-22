#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture>
#include <cstdlib>
#include <ctime>
#include "pelota.h"
#include "paleta.h"
using namespace std;
using namespace sf;


int main() {
    RenderWindow window(VideoMode(800, 600), "Juego de Paletas y Pelota");

    Paleta paleta1(30, 250);
    Paleta paleta2(750, 250);
    Pelota pelota(400, 300);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            paleta1.moveUp();
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            paleta1.moveDown(window.getSize().y);
        }

        if (Keyboard::isKeyPressed(Keyboard::W)) {
            paleta2.moveUp();
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            paleta2.moveDown(window.getSize().y);
        }

        pelota.updatePosition();

        // Colisión de la pelota con las paletas
        if (pelota.getShape().getGlobalBounds().intersects(paleta1.getShape().getGlobalBounds()) ||
            pelota.getShape().getGlobalBounds().intersects(paleta2.getShape().getGlobalBounds())) {
            pelota.reverseX();
        }

        // Colisión de la pelota con los bordes de la ventana
        if (pelota.getShape().getPosition().x <= 0 || pelota.getShape().getPosition().x >= window.getSize().x - 2 * pelota.getShape().getRadius()) {
            pelota.reverseX();
        }

        if (pelota.getShape().getPosition().y <= 0 || pelota.getShape().getPosition().y >= window.getSize().y - 2 * pelota.getShape().getRadius()) {
            pelota.reverseY();
        }

        window.clear();
        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(pelota.getShape());
        window.display();
    }

    return 0;
}