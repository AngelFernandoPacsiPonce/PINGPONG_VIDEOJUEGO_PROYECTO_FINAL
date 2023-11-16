#include "Nivel1.h"
#include "Musica.h"
#include "Pausa.h"
#include "Puntaje.h"
#include <iostream> // Incluye la biblioteca iostream

int alto = 1200;
int ancho = 720;

Nivel1::Nivel1(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow), paleta1(30, 250), paleta2(1150, 250), pelota(alto / 2, ancho / 2, "pelota1.png"), musica(music), puntaje()
{
    paleta1.setTexture("paletita1.png");
    paleta2.setTexture("paletita2.png");

    musica.cargarMusicaNivel1();
    musica.reproducirNivel1();

    // Asegúrate de tener la fuente cargada y disponible antes de crear el objeto Puntaje
    sf::Font font;
    if (!font.loadFromFile("fuente.ttf")) {
        // Manejar error: no se pudo cargar la fuente
        std::cerr << "Error al cargar la fuente\n";
        // Puedes proporcionar una fuente predeterminada o cerrar la aplicación
    }

    // Inicializa Puntaje con la fuente
    puntaje = Puntaje(font);
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

            if (pelota.getSprite().getPosition().x <= 0) {
                puntaje.aumentarDerecha();
                pelota.setposition(ancho / 2, alto / 2);
            }
            else if (pelota.getSprite().getPosition().x >= window.getSize().x - 1 * radioPelota) {
                puntaje.aumentarIzquierda();
                pelota.setposition(ancho / 2, alto / 2);
            }

            if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - 1 * radioPelota) {
                pelota.reverseX();
            }

            if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - 1 * radioPelota) {
                pelota.reverseY();
            }
        }

        window.clear();
        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(pelota.getSprite());
        puntaje.dibujar(window);

        window.display();
    }

    musica.detener();
}
