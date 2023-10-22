#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

class Paleta {
public:
    Paleta(float startX, float startY) : x(startX), y(startY) {
        paleta.setSize(Vector2f(20, 100)); // Tamaño de la paleta
        paleta.setPosition(x, y);
        paleta.setFillColor(Color::White);
    }

    void moveUp() {
        if (y > 0) {
            y -= 0.7; // Ajusta la velocidad de movimiento
            paleta.setPosition(x, y);
        }
    }

    void moveDown(int windowHeight) {
        if (y < windowHeight - paleta.getSize().y) {
            y += 0.7; // Ajusta la velocidad de movimiento
            paleta.setPosition(x, y);
        }
    }

    RectangleShape getShape() {
        return paleta;
    }

private:
    float x, y;
    RectangleShape paleta;
};

