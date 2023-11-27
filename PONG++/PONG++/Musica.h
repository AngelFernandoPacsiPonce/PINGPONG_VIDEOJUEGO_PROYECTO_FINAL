#pragma once

#ifndef MUSICA_H
#define MUSICA_H

#include <SFML/Audio.hpp>

class Musica {
public:
    Musica();

    void cargarMusicaMenu();
    void cargarMusicaNivel1();
    void cargarMusicaNivel2();
    void cargarMusicaNivel3();
    void cargarSonidoChoquePelota();
    void reproducirMenu();
    void reproducirNivel1();
    void reproducirNivel2();
    void reproducirNivel3();
    void reproducirChoquePelota();
    void detener();
    void pausar();
    void reanudar();

private:
    sf::Music music;
    sf::SoundBuffer choquePelotaBuffer;
    sf::Sound choquePelotaSound;
    bool reproduciendo;
};

#endif // MUSICA_H
