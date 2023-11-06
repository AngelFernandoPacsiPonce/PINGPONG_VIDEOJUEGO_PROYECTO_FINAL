#pragma once
#ifndef MUSICA_H
#define MUSICA_H

#include <SFML/Audio.hpp>

class Musica {
public:
    Musica(); // Constructor de la clase Musica

    void cargarMusica(); // Método para cargar la música desde el archivo "musicamenu.mp3"
    void reproducir(); // Método para reproducir la música
    void detener(); // Método para detener la reproducción de música
    void pausar(); // Método para pausar la música
    void reanudar(); // Método para reanudar la reproducción de música

private:
    sf::Music music; // Objeto de la clase sf::Music para gestionar la música
};

#endif // MUSICA_H
