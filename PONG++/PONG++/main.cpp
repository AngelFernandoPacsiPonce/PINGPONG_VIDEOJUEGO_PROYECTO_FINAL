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
    musica.cargarMusica(); // Carga la m�sica desde "musicamenu.mp3"
    musica.reproducir(); // Reproduce la m�sica

    bool inMenu = true;
    bool inNivelMenu = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close(); // Cierra la ventana cuando se hace clic en el bot�n de cerrar
            }

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) {
                    if (inMenu) {
                        menu.MoveUp(); // Mueve la selecci�n hacia arriba en el men� principal
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveUp(); // Mueve la selecci�n hacia arriba en el men� de niveles
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (inMenu) {
                        menu.MoveDown(); // Mueve la selecci�n hacia abajo en el men� principal
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveDown(); // Mueve la selecci�n hacia abajo en el men� de niveles
                    }
                }
                // Cambia entre el men� principal y el men� de niveles o inicia el juego
                if (event.key.code == sf::Keyboard::Return) {
                    if (inMenu) {
                        int selectedOption = menu.getSelectedOption();
                        if (selectedOption == 1) {//JUGAR
                            inMenu = false; // Elimina la ventana del men� principal
                            inNivelMenu = true; // Ingresa a la nueva ventana del men� de niveles
                        }
                        else if (selectedOption == 2) {//SALIR
                            window.close(); // Cierra la ventana y termina el juego
                        }
                    }
                    else if (inNivelMenu) {
                        if (menuNiveles.getSelectedNivel() == 3) {
                            inMenu = true; // Cambia la bandera para volver al men� principal
                            inNivelMenu = false; // Sale de la pantalla de selecci�n de niveles
                        }
                        else {
                            int selectedNivel = menuNiveles.getSelectedNivel();
                            if (selectedNivel == 0) { // NIVEL 1
                                inNivelMenu = false; // Sale de la pantalla de selecci�n de niveles
                                // Crea e inicia el Nivel 1, pasando la referencia de la ventana principal
                                Nivel1 nivel1(window); // Aqu� utilizas el constructor correcto
                                nivel1.run();
                                inMenu = true; // Regresa al men� principal despu�s de que el nivel termine
                            }
                            // Puedes agregar m�s l�gica para otros niveles aqu�
                        }
                    }
                }
            }
        }

        // Dibuja las ventanas en la pantalla
        window.clear();

        if (inMenu) {
            menu.draw(window); // Dibuja el men� principal
        }
        else if (inNivelMenu) {
            menuNiveles.draw(window); // Dibuja el men� de selecci�n de niveles
        }

        window.display(); // Actualiza la pantalla
    }

    return 0;
}
