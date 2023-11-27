#include "Nivel1.h"
#include "Nivel2.h"
#include "Musica.h"
#include "Pausa.h"
#include <iostream>

int alto = 1200;
int ancho = 720;

Nivel1::Nivel1(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow),
    paleta1(30, 250),
    paleta2(1150, 250),
    pelota(alto / 2, ancho / 2, "pelota1.png"),
    musica(music),
    puntaje1(60, 20, "fuentenivel1.ttf"),
    puntaje2(900, 20, "fuentenivel1.ttf"),
    ganador(mainWindow, 0),
    fondoTexture(),
    fondoSprite()
{
    if (!fondoTexture.loadFromFile("fondonivel1.jpg")) {
        std::cerr << "Error al cargar la textura del fondo." << std::endl;
    }

    fondoSprite.setTexture(fondoTexture);

    paleta1.setTexture("paletita1.png");
    paleta2.setTexture("paletita2.png");

    puntaje1.resetearPuntaje();
    puntaje2.resetearPuntaje();

    musica.cargarMusicaNivel1();
    musica.reproducirNivel1();
}

void Nivel1::run() {
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

            float radioPelota = pelota.getRadio();

            if (pelota.getSprite().getGlobalBounds().intersects(paleta1.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta2.getShape().getGlobalBounds())) {
                pelota.reverseX();
            }

            if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - radioPelota) {
                musica.reproducirChoquePelota();  // Reproducir sonido de choque
                if (pelota.getSprite().getPosition().x <= 0) {
                    puntaje2.aumentarPuntaje();
                }

                if (pelota.getSprite().getPosition().x >= window.getSize().x - radioPelota) {
                    puntaje1.aumentarPuntaje();
                }

                if (puntaje1.getPuntaje() >= 2 || puntaje2.getPuntaje() >= 2) {
                    int ganadorNum = (puntaje1.getPuntaje() >= 2) ? 1 : 2;
                    Ganador ganador(window, ganadorNum);
                    int opcion = ganador.mostrar();

                    if (opcion == 0) {
                        puntaje1.resetearPuntaje();
                        puntaje2.resetearPuntaje();
                        pelota.setPosition(ancho / 2, alto / 2);
                    }
                    else if (opcion == 1) {
                        Nivel2 nivel2(window, musica);
                        nivel2.run();
                    }
                    else if (opcion == 2) {
                        musica.detener();
                        return;
                    }
                }

                pelota.reverseX();
                pelota.setPosition(ancho / 2, alto / 2);
                pelota.reverseY();
                pelota.setPosition(ancho / 2, alto / 2);
            }

            if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - radioPelota) {
                pelota.reverseY();
            }
        }

        window.clear();

        window.draw(fondoSprite);

        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(pelota.getSprite());

        window.draw(puntaje1.getTexto());
        window.draw(puntaje2.getTexto());

        window.display();
    }

    musica.detener();
}
