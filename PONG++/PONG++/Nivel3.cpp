#include "Nivel3.h"
#include "Pausa.h"
#include "Ganador.h"
#include <iostream>

Nivel3::Nivel3(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow),
    paleta1(30, 250),
    paleta2(1150, 250),
    pelota(mainWindow.getSize().y / 2, mainWindow.getSize().x / 2, "pelota3.png"), // Asegúrate de tener la textura para la pelota del Nivel 3
    musica(music),
    puntaje1(60, 20, "fuentenivel1.ttf"),
    puntaje2(900, 20, "fuentenivel1.ttf"),
    ganador(mainWindow, 0),
    fondoTexture(),
    fondoSprite()
{
    if (!fondoTexture.loadFromFile("fondonivel3.jpg")) // Asegúrate de tener la textura para el fondo del Nivel 3
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

void Nivel3::run()
{
    Pausa pausa(window);
    bool pausado = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyReleased)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    pausado = !pausado;

                    if (pausado)
                    {
                        int resultado = pausa.mostrar();

                        if (resultado == 0)
                        {
                            pausado = false;
                        }
                        else if (resultado == 1)
                        {
                            if (pausa.shouldReturnToMenu())
                            {
                                musica.detener();
                                return;
                            }
                            window.close();
                        }
                    }
                }
            }
        }

        if (!pausado)
        {
            // Lógica del juego cuando no está pausado

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                paleta1.moveUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                paleta1.moveDown(window.getSize().y);
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                paleta2.moveUp();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                paleta2.moveDown(window.getSize().y);
            }

            pelota.updatePosition();

            // Colisión de la pelota con las paletas
            if (pelota.getSprite().getGlobalBounds().intersects(paleta1.getShape().getGlobalBounds()) ||
                pelota.getSprite().getGlobalBounds().intersects(paleta2.getShape().getGlobalBounds()))
            {
                pelota.reverseX();
            }

            // Colisión de la pelota con los bordes de la ventana
            if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - pelota.getRadio())
            {
                if (pelota.getSprite().getPosition().x <= 0)
                {
                    puntaje2.aumentarPuntaje();
                }

                if (pelota.getSprite().getPosition().x >= window.getSize().x - pelota.getRadio())
                {
                    puntaje1.aumentarPuntaje();
                }

                if (puntaje1.getPuntaje() >= 2 || puntaje2.getPuntaje() >= 2)
                {
                    int ganadorNum = (puntaje1.getPuntaje() >= 2) ? 1 : 2;
                    Ganador ganador(window, ganadorNum);
                    int opcion = ganador.mostrar();

                    if (opcion == 0)
                    {
                        puntaje1.resetearPuntaje();
                        puntaje2.resetearPuntaje();
                        pelota.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                    }
                    else if (opcion == 1)
                    {
                        // Lógica para pasar al siguiente nivel (Nivel 4, por ejemplo)
                        // ...
                    }
                    else if (opcion == 2)
                    {
                        musica.detener();
                        return;
                    }
                }

                pelota.reverseX();
                pelota.setPosition(window.getSize().x / 2, window.getSize().y / 2);
                pelota.reverseY();
                pelota.setPosition(window.getSize().x / 2, window.getSize().y / 2);
            }

            if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - pelota.getRadio() * 2)
            {
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
