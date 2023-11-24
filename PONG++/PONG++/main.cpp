#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "NivelMenu.h"
#include "Musica.h"
#include "Nivel1.h"
#include "Creditos.h"
#include "Pausa.h"

int main() {
    int alto = 1200;
    int ancho = 720;
    sf::RenderWindow window(sf::VideoMode(alto, ancho), "Pong++");

    Menu menu(window.getSize().x, window.getSize().y);
    NivelMenu menuNiveles(window.getSize().x, window.getSize().y);

    Musica musica;
    bool inMenu = true;
    bool inNivelMenu = false;
    bool inCreditos = false;
    bool inPausa = false;
    bool musicPlaying = false;

    Nivel1 nivel1(window, musica);
    Creditos creditos(window);
    Pausa pausa(window);

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
                    else if (inCreditos) {
                        // Lógica para manejar la ventana de créditos
                    }
                    else if (inPausa) {
                        pausa.MoveUp();
                    }
                }
                if (event.key.code == sf::Keyboard::Down) {
                    if (inMenu) {
                        menu.MoveDown();
                    }
                    else if (inNivelMenu) {
                        menuNiveles.MoveDown();
                    }
                    else if (inCreditos) {
                        // Lógica para manejar la ventana de créditos
                    }
                    else if (inPausa) {
                        pausa.MoveDown();
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
                                    musica.detener();
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
                    else if (inCreditos) {
                        // Lógica para manejar la ventana de créditos
                        creditos.Mostrar();
                        if (creditos.getRetrocederSeleccionado()) {
                            inCreditos = false;
                            inMenu = true;
                        }
                    }
                    else if (inPausa) {
                        int pausaOption = pausa.mostrar();
                        if (pausaOption == 0) {
                            inPausa = false;
                        }
                        else if (pausaOption == 1) {
                            inPausa = false;
                            inMenu = true;
                        }
                    }
                }
                else if (event.key.code == sf::Keyboard::P) {
                    if (!inPausa) {
                        inPausa = true;
                    }
                    else {
                        inPausa = false;
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
        else if (inCreditos) {
            creditos.Mostrar();
            if (creditos.getRetrocederSeleccionado()) {
                inCreditos = false;
                inMenu = true;
            }
        }
        else if (inPausa) {
            pausa.mostrar();
        }

        window.display();
    }

    return 0;
}
