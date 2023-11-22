#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "NivelMenu.h"
#include "Musica.h"
#include "Nivel1.h"
#include "Creditos.h" // Agregado para manejar la ventana de cr�ditos

int main() {
    int alto = 1200;
    int ancho = 720;
    sf::RenderWindow window(sf::VideoMode(alto, ancho), "Pong++");

    Menu menu(window.getSize().x, window.getSize().y);
    NivelMenu menuNiveles(window.getSize().x, window.getSize().y);

    Musica musica;
    bool inMenu = true;
    bool inNivelMenu = false;
    bool inCreditos = false; // Agregado para manejar la ventana de cr�ditos
    bool musicPlaying = false;  // Inicializa en false

    Nivel1 nivel1(window, musica);
    Creditos creditos(window);

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
                    // Agregado para "CR�DITOS"
                    else if (inCreditos) {
                        // L�gica para manejar la ventana de cr�ditos
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (inMenu) {
                        menu.MoveDown();
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveDown();
                    }
                    // Agregado para "CR�DITOS"
                    else if (inCreditos) {
                        // L�gica para manejar la ventana de cr�ditos
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
                        // Agregado para "CR�DITOS"
                        else if (selectedOption == 3) {
                            inMenu = false;
                            inCreditos = true;
                        }
                    }
                    else if (inNivelMenu) {
                        if (menuNiveles.getSelectedNivel() == 3) {
                            inMenu = true;
                            inNivelMenu = false;

                            if (musicPlaying) {
                                musica.detener();
                                musicPlaying = false;
                            }
                        }
                        else {
                            int selectedNivel = menuNiveles.getSelectedNivel();
                            if (selectedNivel == 0) {
                                inNivelMenu = false;

                                if (!musicPlaying) {
                                    musica.detener();  // Detiene la m�sica del men� si estabas en el men� antes de ir al men� de selecci�n de niveles
                                    musica.cargarMusicaNivel1();
                                    musica.reproducirNivel1();
                                    musicPlaying = true;
                                }

                                Nivel1 nivel1(window, musica);
                                nivel1.run();
                                inMenu = true;
                            }
                        }
                    }
                    // Agregado para "CR�DITOS"
                    else if (inCreditos) {
                        // L�gica para manejar la ventana de cr�ditos
                        creditos.Retroceder(); // Retrocede desde la ventana de cr�ditos
                        inCreditos = false;
                        inMenu = true;
                    }
                }
            }
        }

        window.clear();

        if (inMenu) {
            if (!musicPlaying) {
                musica.reproducirMenu();
                musicPlaying = true;
            }
            menu.draw(window);
        }
        else if (inNivelMenu) {
            if (!musicPlaying) {
                musica.detener();
                musica.cargarMusicaNivel1();
                musica.reproducirNivel1();
                musicPlaying = true;
            }
            menuNiveles.draw(window);
        }
        // Agregado para "CR�DITOS"
        else if (inCreditos) {
            // L�gica para manejar la ventana de cr�ditos
            creditos.Mostrar();
        }

        window.display();
    }

    return 0;
}
