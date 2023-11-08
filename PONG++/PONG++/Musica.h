#pragma once
#ifndef MUSICA_H
#define MUSICA_H

#include <SFML/Audio.hpp>

class Musica {
public:
    Musica();

    void cargarMusicaMenu();
    void cargarMusicaNivel1();
    void reproducirMenu();
    void reproducirNivel1();
    void detener();
    void pausar();
    void reanudar();

private:
    sf::Music music;
    bool reproduciendo;
};

#endif // MUSICA_H
