#include "Nivel3.h"
#include "Pausa.h"
#include "Ganador.h"
#include <iostream>

Nivel3::Nivel3(sf::RenderWindow& mainWindow, Musica& music)
    : window(mainWindow),
    paleta1(30, 250),
    paleta2(1150, 250),
    pelota(mainWindow.getSize().y / 2, mainWindow.getSize().x / 2, "pelota3.png"),
    musica(music),
    puntaje1(60, 20, "fuentenivel1.ttf"),
    puntaje2(900, 20, "fuentenivel1.ttf"),
    ganador(mainWindow, 0),
    fondoTexture(),
    fondoSprite()
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
    inicializarBarreras();  // Llamada para inicializar las barreras
}

void Nivel3::inicializarBarreras() {
    float separacionEntreBarreras = 50.0f;  // Puedes ajustar la separación según tu diseño
    float x = window.getSize().x / 2 - 5.0f;  // Posición inicial de la primera barrera

    barreras.clear();  // Limpiamos las barreras para evitar duplicados

    for (int i = 0; i < 3; ++i) {
        Barrera barrera(x, separacionEntreBarreras * i, 10, 100);
        std::cout << "Barrera " << i << " - Posición: " << barrera.getShape().getPosition().x << ", " << barrera.getShape().getPosition().y << std::endl;
        barreras.push_back(barrera);
    }
}

void Nivel3::run()
{
    Pausa pausa(window);
    bool pausado = false;

    // Variable para controlar si ya se reprodujo el sonido de choque con la pared
    bool choqueParedReproducido = false;
    inicializarBarreras();

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
                // No reproducir el sonido de choque de pelota aquí
            }

            // Colisión de la pelota con las barreras
            for (auto& barrera : barreras) {
                if (pelota.getSprite().getGlobalBounds().intersects(barrera.getShape().getGlobalBounds())) {
                    pelota.reverseX();
                    barrera.setPosition(-100, -100);  // Movemos la barrera fuera de la pantalla
                    // Puedes agregar aquí cualquier lógica adicional al colisionar con la barrera
                }
            }

            // Colisión de la pelota con los bordes de la ventana
            if (pelota.getSprite().getPosition().x <= 0 || pelota.getSprite().getPosition().x >= window.getSize().x - pelota.getRadio())
            {
                // Reproduce el sonido de choque de pelota aquí solo si no se reprodujo antes
                if (!choqueParedReproducido)
                {
                    musica.reproducirChoquePelota();
                    choqueParedReproducido = true;
                }

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
                        choqueParedReproducido = false;
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
            else
            {
                // Si la pelota no está en las paredes laterales, permite reproducir el sonido nuevamente
                choqueParedReproducido = false;
            }

            if (pelota.getSprite().getPosition().y <= 0 || pelota.getSprite().getPosition().y >= window.getSize().y - pelota.getRadio() * 2)
            {
                pelota.reverseY();
                // No reproducir el sonido de choque de pelota aquí
            }
        }

        window.clear();
        window.draw(fondoSprite);
        window.draw(paleta1.getShape());
        window.draw(paleta2.getShape());
        window.draw(pelota.getSprite());

        // Dibujar las barreras en el bucle principal
        std::cout << "Número de barreras a dibujar: " << barreras.size() << std::endl;

        for (const auto& barrera : barreras) {
            window.draw(barrera.getShape());
            std::cout << "Dibujando barrera en posición: " << barrera.getShape().getPosition().x << ", " << barrera.getShape().getPosition().y << std::endl;
        }

        window.draw(puntaje1.getTexto());
        window.draw(puntaje2.getTexto());
        window.display();
    }

    musica.detener();
}
