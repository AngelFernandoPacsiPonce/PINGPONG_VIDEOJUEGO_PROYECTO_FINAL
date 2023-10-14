#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "NivelMenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 720), "Pong++");
    Menu menu(window.getSize().x, window.getSize().y);
    NivelMenu menuNiveles(window.getSize().x, window.getSize().y);

    bool inMenu = true;
    bool inNivelMenu = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    if (inMenu) {
                        menu.MoveUp();
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveUp();
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (inMenu) {
                        menu.MoveDown();
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveDown();
                    }
                }
                if (event.key.code == sf::Keyboard::Return) {
                    if (inMenu) {
                        int selectedOption = menu.getSelectedOption();
                        if (selectedOption == 1) {
                            inMenu = false;
                            inNivelMenu = true;
                        }
                        else if (selectedOption == 2) {
                            window.close();
                        }
                    }
                    else if (inNivelMenu) {
                        int selectedNivel = menuNiveles.getSelectedNivel();
                        // Lógica para manejar la selección de niveles
                        // Puedes cambiar las banderas para salir del bucle
                    }
                }
            }
        }

        window.clear();

        if (inMenu) {
            menu.draw(window);
        }
        else if (inNivelMenu) {
            menuNiveles.draw(window);
        }

        window.display();
    }

    return 0;
}
