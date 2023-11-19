#include "Puntaje.h"

Puntaje::Puntaje(float x, float y, const std::string& fontPath)
    : puntaje(0) {
    if (!font.loadFromFile(fontPath)) {
        // Manejo de errores si no se puede cargar la fuente.
    }

    texto.setFont(font);
    texto.setCharacterSize(40);
    texto.setPosition(x, y);
    texto.setFillColor(sf::Color::White);
}

void Puntaje::aumentarPuntaje() {
    puntaje++;
    texto.setString(std::to_string(puntaje));
}

int Puntaje::getPuntaje() {
    return puntaje;
}

void Puntaje::resetearPuntaje() {
    puntaje = 0;
    texto.setString("0");
}

sf::Text& Puntaje::getTexto() {
    return texto;
}
