#include "Musica.h"

Musica::Musica() {
    // Constructor
}

void Musica::cargarMusica() {
    if (!music.openFromFile("musicamenu.mp3")) {
        // Manejo de errores si no se puede cargar la música.
    }
}
//futuras funciones para configurar musica del juego. =) ;-;
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
