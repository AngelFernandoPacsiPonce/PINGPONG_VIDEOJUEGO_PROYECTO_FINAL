// Nivel1.cpp
#include "Nivel1.h"
#include "Musica.h"
#include "Pausa.h"

int alto = 1200;
int ancho = 720;

Nivel1::Nivel1(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow), paleta1(30, 250), paleta2(1150, 250), pelota(alto / 2, ancho / 2, "pelota1.png"), musica(music)
{
    paleta1.setTexture("paletita1.png");
    paleta2.setTexture("paletita2.png");

    musica.cargarMusicaNivel1();
    musica.reproducirNivel1();
}

void Nivel1::run() {
    Pausa pausa(window); // Crea una instancia de la clase Pausa
    bool pausado = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Manejo de eventos para pausar y reanudar el juego
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    pausado = !pausado;

                    // Si el juego se pausa, muestra la pantalla de pausa
                    if (pausado) {
                        int resultado = pausa.mostrar();

                        // Maneja el resultado según la elección del jugador
                        if (resultado == 0) {
                            // Reanudar el juego
                            pausado = false;
                        }
                        else if (resultado == 1) {
                            // Salir al Menú
                            if (pausa.shouldReturnToMenu()) {
                                // Detener la música del nivel1 antes de salir
                                musica.detener();
                                return; // Regresar al menú principal
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

            // Obtén el radio de la pelota
            float radioPelota = pelota.getRadio();

            // Colisión de la pelota con las paletas
            if (pelota.getSprite().getGlobalBounds().intersects(paleta1.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta2.getShape().getGlobalBounds())) {
                pelota.reverseX();
            }

            // Colisión de la pelota con los bordes de la ventana
            if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - radioPelota) {
                pelota.reverseX();
                pelota.setPosition(ancho / 2, alto / 2);  // Reposiciona en el centro horizontalmente
                pelota.reverseY();
                pelota.setPosition(ancho / 2, alto / 2);  // Reposiciona en el centro verticalmente
            }

            if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - radioPelota) {
                pelota.reverseY();
            }
        }

        window.clear();
        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(pelota.getSprite());

        window.display();
    }
    //  detener la música del nivel1 antes de salir de la función
    musica.detener();
}
