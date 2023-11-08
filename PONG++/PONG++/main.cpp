#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "NivelMenu.h"
#include "Musica.h" // Incluye el archivo de cabecera de la clase Musica
#include "Nivel1.h" // Incluye el archivo de cabecera del Nivel 1

int main() {
    // Crea una ventana de SFML
    sf::RenderWindow window(sf::VideoMode(1200, 720), "Pong++");

    // Crea instancias de las clases Menu y NivelMenu
    Menu menu(window.getSize().x, window.getSize().y);
    NivelMenu menuNiveles(window.getSize().x, window.getSize().y);

    // Crea una instancia de la clase Musica
    Musica musica;
    musica.cargarMusica(); // Carga la música desde "musicamenu.mp3"
    musica.reproducir(); // Reproduce la música

    bool inMenu = true;
    bool inNivelMenu = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Cierra la ventana cuando se hace clic en el botón de cerrar
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    if (inMenu) {
                        menu.MoveUp(); // Mueve la selección hacia arriba en el menú principal
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveUp(); // Mueve la selección hacia arriba en el menú de niveles
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (inMenu) {
                        menu.MoveDown(); // Mueve la selección hacia abajo en el menú principal
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveDown(); // Mueve la selección hacia abajo en el menú de niveles
                    }
                }
                // Cambia entre el menú principal y el menú de niveles o inicia el juego
                if (event.key.code == sf::Keyboard::Return) {
                    if (inMenu) {
                        int selectedOption = menu.getSelectedOption();
                        if (selectedOption == 1) {//JUGAR
                            inMenu = false; // Elimina la ventana del menú principal
                            inNivelMenu = true; // Ingresa a la nueva ventana del menú de niveles
                        }
                        else if (selectedOption == 2) {//SALIR
                            window.close(); // Cierra la ventana y termina el juego
                        }
                    }
                    else if (inNivelMenu) {
                        if (menuNiveles.getSelectedNivel() == 3) {
                            inMenu = true; // Cambia la bandera para volver al menú principal
                            inNivelMenu = false; // Sale de la pantalla de selección de niveles
                        }
                        else {
                            int selectedNivel = menuNiveles.getSelectedNivel();
                            if (selectedNivel == 0) { // NIVEL 1
                                inNivelMenu = false; // Sale de la pantalla de selección de niveles
                                // Crea e inicia el Nivel 1, pasando la referencia de la ventana principal
                                Nivel1 nivel1(window); // Aquí utilizas el constructor correcto
                                nivel1.run();
                                inMenu = true; // Regresa al menú principal después de que el nivel termine
                            }
                            // Puedes agregar más lógica para otros niveles aquí
                        }
                    }
                }
            }
        }

        // Dibuja las ventanas en la pantalla
        window.clear();

        if (inMenu) {
            menu.draw(window); // Dibuja el menú principal
        }
        else if (inNivelMenu) {
            menuNiveles.draw(window); // Dibuja el menú de selección de niveles
        }

        window.display(); // Actualiza la pantalla
    }

    return 0;
}
