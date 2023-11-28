#include "Nivel3.h"
#include "Pausa.h"
#include "Ganador.h"
#include "PaletaFija.h"
#include <iostream>

Nivel3::Nivel3(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow),
    paleta1(30, 250),
    paleta2(1150, 250),
    paleta3(mainWindow.getSize().x / 2 - 10, mainWindow.getSize().y / 2 - 50),
    paleta4(mainWindow.getSize().x / 2 - 10, mainWindow.getSize().y / 2 - 205 + separacionEntrePaletas),
    paleta5(mainWindow.getSize().x / 2 - 10, window.getSize().y / 2 - 50 + 2 * separacionEntrePaletas),

    pelota(mainWindow.getSize().y / 2, mainWindow.getSize().x / 2, "pelota3.png"),
    musica(music),
    puntaje1(60, 20, "fuentenivel1.ttf"),
    puntaje2(900, 20, "fuentenivel1.ttf"),
    ganador(mainWindow, 0),
    fondoTexture(),
    fondoSprite(),
    separacionEntrePaletas(150.0f) // Ajusta el valor según sea necesario
{
    if (!fondoTexture.loadFromFile("fondonivel3.jpg"))
    {
        std::cerr << "Error al cargar la textura del fondo." << std::endl;
    }

    fondoSprite.setTexture(fondoTexture);

    paleta1.setTexture("paletita1.png");
    paleta2.setTexture("paletita2.png");

    puntaje1.resetearPuntaje();
    puntaje2.resetearPuntaje();

    musica.cargarMusicaNivel3();
    musica.reproducirNivel3();
}

void Nivel3::actualizarPosicionPaletasFijas() {
    paleta3.setPosition(window.getSize().x / 2 - 10, window.getSize().y / 2 - 320);
    paleta4.setPosition(window.getSize().x / 2 - 10, window.getSize().y / 2 - 170 + separacionEntrePaletas);
    paleta5.setPosition(window.getSize().x / 2 - 10, window.getSize().y / 2 - 35 + 2 * separacionEntrePaletas - 20);

    // Establece el color de las paletas fijas
    paleta3.setColor(sf::Color::Blue); // Cambia el color según tus necesidades
    paleta4.setColor(sf::Color::Blue);
    paleta5.setColor(sf::Color::Blue);
}

void Nivel3::run() {
    Pausa pausa(window);
    bool pausado = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    pausado = !pausado;

                    if (pausado) {
                        int resultado = pausa.mostrar();

                        if (resultado == 0) {
                            pausado = false;
                        }
                        else if (resultado == 1) {
                            if (pausa.shouldReturnToMenu()) {
                                musica.detener();
                                return;
                            }
                            window.close();
                        }
                    }
                }
            }
        }

        if (!pausado) {
            // Lógica del juego cuando no está pausado

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

            // Colisión de la pelota con las paletas
            if (pelota.getSprite().getGlobalBounds().intersects(paleta1.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta2.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta3.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta4.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta5.getShape().getGlobalBounds())) {

                pelota.reverseX();
            }

            // Colisión de la pelota con los bordes de la ventana
            if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - pelota.getRadio()) {
                if (pelota.getSprite().getPosition().x <= 0) {
                    puntaje2.aumentarPuntaje();
                }

                if (pelota.getSprite().getPosition().x >= window.getSize().x - pelota.getRadio()) {
                    puntaje1.aumentarPuntaje();
                }

                if (puntaje1.getPuntaje() >= 2 || puntaje2.getPuntaje() >= 2) {
                    int ganadorNum = (puntaje1.getPuntaje() >= 2) ? 1 : 2;
                    Ganador ganador(window, ganadorNum);
                    int opcion = ganador.mostrar();

                    if (opcion == 0) {
                        puntaje1.resetearPuntaje();
                        puntaje2.resetearPuntaje();
                        pelota.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                    }
                    else if (opcion == 1) {
                        // Lógica para pasar al siguiente nivel

                    }
                    else if (opcion == 2) {
                        musica.detener();
                        return;
                    }
                }

                pelota.reverseX();
                pelota.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                pelota.reverseY();
                pelota.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            }

            if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - pelota.getRadio() * 2) {
                pelota.reverseY();
            }
        }

        // Actualiza las posiciones de las paletas fijas antes de dibujar
        actualizarPosicionPaletasFijas();

        window.clear();
        window.draw(fondoSprite);
        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(paleta3.getShape());
        window.draw(paleta4.getShape());
        window.draw(paleta5.getShape());  // Agrega las nuevas paletas al dibujo

        window.draw(pelota.getSprite());
        window.draw(puntaje1.getTexto());
        window.draw(puntaje2.getTexto());
        window.display();
    }

    musica.detener();
}
