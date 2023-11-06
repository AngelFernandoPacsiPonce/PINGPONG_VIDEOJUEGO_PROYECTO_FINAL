#pragma once
#ifndef MUSICA_H
#define MUSICA_H

#include <SFML/Audio.hpp>

class Musica {
public:
    Musica(); // Constructor de la clase Musica

    void cargarMusica(); // M�todo para cargar la m�sica desde el archivo "musicamenu.mp3"
    void reproducir(); // M�todo para reproducir la m�sica
    void detener(); // M�todo para detener la reproducci�n de m�sica
    void pausar(); // M�todo para pausar la m�sica
    void reanudar(); // M�todo para reanudar la reproducci�n de m�sica

private:
    sf::Music music; // Objeto de la clase sf::Music para gestionar la m�sica
};

#endif // MUSICA_H
