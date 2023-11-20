#include "Nivel1.h"
#include "Musica.h"
#include "Pausa.h"

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
    ganador(mainWindow, 0) // El segundo parámetro es el jugador ganador, inicializado en 0
{
    paleta1.setTexture("paletita1.png");
    paleta2.setTexture("paletita2.png");

    // Llama a la función resetearPuntaje al inicio del juego
    puntaje1.resetearPuntaje();
    puntaje2.resetearPuntaje();

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
                // Incrementa el puntaje del jugador 2 si toca la pared izquierda
                if (pelota.getSprite().getPosition().x <= 0) {
                    puntaje2.aumentarPuntaje();
                }

                // Incrementa el puntaje del jugador 1 si toca la pared derecha
                if (pelota.getSprite().getPosition().x >= window.getSize().x - radioPelota) {
                    puntaje1.aumentarPuntaje();
                }

                // Verifica si hay un ganador
                if (puntaje1.getPuntaje() >= 2 || puntaje2.getPuntaje() >= 2) {
                    int ganadorNum = (puntaje1.getPuntaje() >= 2) ? 1 : 2;
                    Ganador ganador(window, ganadorNum);
                    int opcion = ganador.mostrar(); // Muestra la pantalla de ganador

                    // Maneja la opción seleccionada
                    if (opcion == 0) {
                        // Reiniciar el juego
                        puntaje1.resetearPuntaje();
                        puntaje2.resetearPuntaje();
                        pelota.setPosition(ancho / 2, alto / 2);
                    }
                    else if (opcion == 1) {
                        // Pasar al siguiente nivel
                        // Lógica para pasar al siguiente nivel
                        // ...
                    }
                    else if (opcion == 2) {
                        // Salir al menú principal
                        // Lógica para salir al menú principal
                        // ...
                        musica.detener();
                        return; // Regresar al menú principal
                    }
                }

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

        // Dibuja los puntajes
        window.draw(puntaje1.getTexto());
        window.draw(puntaje2.getTexto());

        window.display();
    }
    // detener la música del nivel1 antes de salir de la función
    musica.detener();
}
