#include "Puntaje.h"

Puntaje::Puntaje(float x, float y, const std::string& fuentePath) : puntaje(0) {
    if (!fuente.loadFromFile(fuentePath)) {
        // Manejo de error si la carga de la fuente falla
    }

    textoPuntaje.setFont(fuente);
    textoPuntaje.setCharacterSize(40);
    textoPuntaje.setFillColor(sf::Color::White);
    textoPuntaje.setPosition(x, y);

    actualizarTexto();
}

void Puntaje::aumentarPuntaje() {
    puntaje++;
    actualizarTexto();
}

void Puntaje::reiniciarPuntaje() {
    puntaje = 0;
    actualizarTexto();
}

void Puntaje::actualizarTexto() {
    textoPuntaje.setString("PUNTOS: " + std::to_string(puntaje));
}

sf::Text Puntaje::getTexto() {
    return textoPuntaje;
}

unsigned int Puntaje::getPuntaje() {
    return puntaje;
}
