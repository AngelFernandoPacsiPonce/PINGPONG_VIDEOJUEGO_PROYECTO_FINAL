#pragma once
#ifndef MUSICA_H
#define MUSICA_H

#include <SFML/Audio.hpp>

class Musica {
public:
    Musica();

    void cargarMusica(); // M�todo para cargar la m�sica desde el archivo "musicamenu.mp3"
    void reproducir();
    void detener();
    void pausar();
    void reanudar();

private:
    sf::Music music;
};

#endif // MUSICA_H
