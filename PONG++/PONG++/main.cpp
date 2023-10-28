#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "NivelMenu.h"
#include "Musica.h" // Incluye el archivo de cabecera de la clase Musica
#include "Nivel1.h" // Incluye el archivo de cabecera del Nivel 1

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 720), "Pong++");
    Menu menu(window.getSize().x, window.getSize().y);
    NivelMenu menuNiveles(window.getSize().x, window.getSize().y);

    Musica musica; // Crea una instancia de la clase Musica
    musica.cargarMusica(); // Carga la música desde "musicamenu.mp3"
    musica.reproducir(); // Reproduce la música

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
                //ENTRAR A LA OTRA VENTANA (CAMBIO DE VENTANAS)
                if (event.key.code == sf::Keyboard::Return) {
                    if (inMenu) {
                        int selectedOption = menu.getSelectedOption();
                        if (selectedOption == 1) {//JUGAR
                            inMenu = false;//ELIMINA LA VENTANA
                            inNivelMenu = true;// INGRESA A NUEVA VENTANA
                        }
                        else if (selectedOption == 2) {//SALIR
                            window.close();
                        }
                    }
                    else if (inNivelMenu) {
                        if (menuNiveles.getSelectedNivel() == 3) {
                            inMenu = true; // Cambia la bandera para volver al menú principal
                            inNivelMenu = false; // Salir de la pantalla de selección de niveles
                        }
                        else {
                            int selectedNivel = menuNiveles.getSelectedNivel();
                            if (selectedNivel == 0) { // NIVEL 1
                                inNivelMenu = false; // Sal de la pantalla de selección de niveles
                                // Crear e iniciar el Nivel 1
                                Nivel1 nivel1(window.getSize().x, window.getSize().y);
                                nivel1.run();
                                inMenu = true; // Regresar al menú principal después de que el nivel termine
                            }
                            // Puedes agregar más lógica para otros niveles aquí
                        }
                    }
                }
            }
        }
        //DIBUJAR LAS VENTANAS
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
