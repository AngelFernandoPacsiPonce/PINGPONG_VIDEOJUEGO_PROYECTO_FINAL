#include <SFML/Graphics.hpp>  
#include "Menu.h"             
#include "NivelMenu.h"      
#include "Musica.h"          
#include "Nivel1.h"          

int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 720), "Pong++");  // Crea una ventana de juego

    Menu menu(window.getSize().x, window.getSize().y);           // Crea una instancia de la clase Menu
    NivelMenu menuNiveles(window.getSize().x, window.getSize().y);  // Crea una instancia de la clase NivelMenu

    Musica musica;              // Crea una instancia de la clase Musica
    musica.cargarMusicaMenu();  // Carga la m�sica del men�
    musica.reproducirMenu();    // Reproduce la m�sica del men�

    bool inMenu = true;           // Bandera para controlar si estamos en el men�
    bool inNivelMenu = false;     // Bandera para controlar si estamos en el men� de selecci�n de niveles
    bool musicPlaying = true;     // Bandera para controlar si la m�sica est� sonando

    Nivel1 nivel1(window, musica);  // Crea una instancia de la clase Nivel1 pasando la ventana y la m�sica

    while (window.isOpen()) {  // Comienza un bucle principal que se ejecuta mientras la ventana est� abierta
        sf::Event event;        // Crea una instancia de sf::Event para manejar eventos
        while (window.pollEvent(event)) {  // Procesa eventos
            if (event.type == sf::Event::Closed) {  // Si se cierra la ventana, se sale del bucle
                window.close();
            }

            if (event.type == sf::Event::KeyReleased) {  // Si se libera una tecla
                if (event.key.code == sf::Keyboard::Up) {
                    if (inMenu) {
                        menu.MoveUp();  // Mueve la selecci�n hacia arriba en el men�
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveUp();  // Mueve la selecci�n hacia arriba en el men� de selecci�n de niveles
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (inMenu) {
                        menu.MoveDown();  // Mueve la selecci�n hacia abajo en el men�
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveDown();  // Mueve la selecci�n hacia abajo en el men� de selecci�n de niveles
                    }
                }
                if (event.key.code == sf::Keyboard::Return) {  // Si se presiona la tecla "Enter"
                    if (inMenu) {
                        int selectedOption = menu.getSelectedOption();
                        if (selectedOption == 1) {
                            inMenu = false;      // Sale del men� y va al men� de selecci�n de niveles
                            inNivelMenu = true;
                        }
                        else if (selectedOption == 2) {
                            window.close();      // Cierra la ventana
                        }
                    }
                    else if (inNivelMenu) {
                        if (menuNiveles.getSelectedNivel() == 3) {
                            inMenu = true;        // Regresa al men� principal
                            inNivelMenu = false;

                            // Detiene la m�sica al regresar al men�
                            if (musicPlaying) {
                                musica.detener();
                                musicPlaying = false;
                            }
                        }
                        else {
                            int selectedNivel = menuNiveles.getSelectedNivel();
                            if (selectedNivel == 0) {
                                inNivelMenu = false;  // Sale del men� de selecci�n de niveles

                                if (!musicPlaying) {
                                    musica.cargarMusicaNivel1();
                                    musica.reproducirNivel1();
                                    musicPlaying = true;
                                }

                                Nivel1 nivel1(window, musica);  // Crea una nueva instancia de Nivel1
                                nivel1.run();
                                inMenu = true;  // Regresa al men� principal
                            }
                        }
                    }
                }
            }
        }

        window.clear();  // Borra el contenido de la ventana

        if (inMenu) {
            menu.draw(window);  // Dibuja el men� en la ventana
        }
        else if (inNivelMenu) {
            menuNiveles.draw(window);  // Dibuja el men� de selecci�n de niveles en la ventana
        }

        window.display();  // Actualiza la ventana para mostrar los cambios
    }

    return 0;  // Retorna 0 para indicar que el programa se ejecut� con �xito
}
