#include "Musica.h"

Musica::Musica() {
    // Constructor, puedes agregar configuraciones iniciales aqu� si es necesario.
}

void Musica::cargarMusica() {
    if (!music.openFromFile("musicamenu.mp3")) {
        // Manejo de errores si no se puede cargar la m�sica.
    }
}

void Musica::reproducir() {
    music.play();
}

void Musica::detener() {
    music.stop();
}

void Musica::pausar() {
    music.pause();
}

void Musica::reanudar() {
    music.play();
}
