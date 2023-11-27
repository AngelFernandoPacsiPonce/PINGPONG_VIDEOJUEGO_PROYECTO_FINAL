#include "Musica.h"

Musica::Musica() {
    // Constructor
}

void Musica::cargarMusicaMenu() {
    if (!music.openFromFile("musicamenu.mp3")) {
        // Manejo de errores si no se puede cargar la m�sica.
    }
}

void Musica::cargarMusicaNivel1() {
    if (!music.openFromFile("musicanivel1.mp3")) {
        // Manejo de errores si no se puede cargar la m�sica.
    }
}
void Musica::cargarMusicaNivel2() {
    if (!music.openFromFile("musicanivel2.mp3")) {
        // Manejo de errores si no se puede cargar la m�sica.
    }
}

void Musica::reproducirMenu() {
    if (music.openFromFile("musicamenu.mp3")) {
        music.play();
        reproduciendo = true;
    }
}

void Musica::reproducirNivel1() {
    if (!reproduciendo) {
        detener(); // Detener la m�sica del men� antes de reproducir la del nivel 1
        if (!music.openFromFile("musicanivel1.mp3")) {
            // Manejo de errores si no se puede cargar la m�sica.
        }
    }
    music.play();
    reproduciendo = true;
}
void Musica::reproducirNivel2() {
    if (!reproduciendo) {
        detener(); // Detener la m�sica del men� antes de reproducir la del nivel 1
        if (!music.openFromFile("musicanivel2.mp3")) {
            // Manejo de errores si no se puede cargar la m�sica.
        }
    }
    music.play();
    reproduciendo = true;
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
