#include "Musica.h"
#include <iostream>

Musica::Musica() {
    cargarSonidoChoquePelota();
}

void Musica::cargarMusicaMenu() {
    if (!music.openFromFile("musicamenu.mp3")) {
        std::cerr << "Error al cargar la música del menú." << std::endl;
    }
}

void Musica::cargarMusicaNivel1() {
    if (!music.openFromFile("musicanivel1.mp3")) {
        std::cerr << "Error al cargar la música del nivel 1." << std::endl;
    }
}

void Musica::cargarMusicaNivel2() {
    if (!music.openFromFile("musicanivel2.mp3")) {
        std::cerr << "Error al cargar la música del nivel 2." << std::endl;
    }
}

void Musica::cargarMusicaNivel3() {
    if (!music.openFromFile("musicanivel3.mp3")) {
        std::cerr << "Error al cargar la música del nivel 3." << std::endl;
    }
}

void Musica::cargarSonidoChoquePelota() {
    if (!choquePelotaBuffer.loadFromFile("choquepelota.mp3")) {
        std::cerr << "Error al cargar el sonido de choque de la pelota." << std::endl;
    }
    choquePelotaSound.setBuffer(choquePelotaBuffer);
}

void Musica::reproducirMenu() {
    if (music.openFromFile("musicamenu.mp3")) {
        music.play();
        reproduciendo = true;
    }
}

void Musica::reproducirNivel1() {
    if (!reproduciendo) {
        detener();
        if (!music.openFromFile("musicanivel1.mp3")) {
            std::cerr << "Error al cargar la música del nivel 1." << std::endl;
        }
    }
    music.play();
    reproduciendo = true;
}

void Musica::reproducirNivel2() {
    if (!reproduciendo) {
        detener();
        if (!music.openFromFile("musicanivel2.mp3")) {
            std::cerr << "Error al cargar la música del nivel 2." << std::endl;
        }
    }
    music.play();
    reproduciendo = true;
}

void Musica::reproducirNivel3() {
    if (!reproduciendo) {
        detener();
        if (!music.openFromFile("musicanivel3.mp3")) {
            std::cerr << "Error al cargar la música del nivel 3." << std::endl;
        }
    }
    music.play();
    reproduciendo = true;
}

void Musica::reproducirChoquePelota() {
    choquePelotaSound.play();
}

void Musica::detener() {
    music.stop();
    reproduciendo = false;
}

void Musica::pausar() {
    music.pause();
}

void Musica::reanudar() {
    music.play();
    reproduciendo = true;
}
