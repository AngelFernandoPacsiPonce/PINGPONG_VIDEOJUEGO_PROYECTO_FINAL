#include <SFML/Graphics.hpp>
#include "Menu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 720), "Pong++");
    Menu menu(window.getSize().x, window.getSize().y);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    menu.MoveUp();
                }
                if (event.key.code == sf::Keyboard::Down) {
                    menu.MoveDown();
                }
                if (event.key.code == sf::Keyboard::Return) {
                    int selectedOption = menu.getSelectedOption();
                    if (selectedOption == 1) {
                        
                        
                    }
                    else if (selectedOption == 2) {
                        window.close(); // Salir del juego
                    }
                }
            }
        }

        window.clear();
        menu.draw(window);
        window.display();
    }

    return 0;
}
