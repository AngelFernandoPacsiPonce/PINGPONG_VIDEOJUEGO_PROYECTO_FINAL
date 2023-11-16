#include "Puntaje.h"

// Implementación del constructor predeterminado
Puntaje::Puntaje() : puntosIzquierda(0), puntosDerecha(0) {
    // Resto de tu código...
}

// Implementación del constructor que recibe la fuente
Puntaje::Puntaje(sf::Font& font) : puntosIzquierda(0), puntosDerecha(0) {
    textoIzquierda.setFont(font);
    textoIzquierda.setCharacterSize(30);
    textoIzquierda.setFillColor(sf::Color::White);
    textoIzquierda.setPosition(50, 50);

    textoDerecha.setFont(font);
    textoDerecha.setCharacterSize(30);
    textoDerecha.setFillColor(sf::Color::White);
    textoDerecha.setPosition(1100, 50);
}

void Puntaje::aumentarIzquierda() {
    puntosIzquierda++;
}

void Puntaje::aumentarDerecha() {
    puntosDerecha++;
}

int Puntaje::getPuntosIzquierda() {
    return puntosIzquierda;
}

int Puntaje::getPuntosDerecha() {
    return puntosDerecha;
}

void Puntaje::resetear() {
    puntosIzquierda = 0;
    puntosDerecha = 0;
}

void Puntaje::dibujar(sf::RenderWindow& window) {
    // Actualiza el texto mostrado en pantalla
    textoIzquierda.setString(std::to_string(puntosIzquierda));
    textoDerecha.setString(std::to_string(puntosDerecha));

    // Dibuja los textos en la ventana
    window.draw(textoIzquierda);
    window.draw(textoDerecha);
}
