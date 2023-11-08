#include "Musica.h"

Musica::Musica() {
    // Constructor
}

void Musica::cargarMusicaMenu() {
    if (!music.openFromFile("musicamenu.mp3")) {
        // Manejo de errores si no se puede cargar la música.
    }
}

void Musica::cargarMusicaNivel1() {
    if (!music.openFromFile("musicanivel1.mp3")) {
        // Manejo de errores si no se puede cargar la música.
    }
}

void Musica::reproducirMenu() {
    if (music.openFromFile("musicamenu.mp3")) {
        music.play();
        reproduciendo = true;
    }
}

void Musica::reproducirNivel1() {
    if (music.openFromFile("musicanivel1.mp3")) {
        music.play();
        reproduciendo = true;
    }
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
