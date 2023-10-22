#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
using namespace sf;

class Pelota {
public:
    Pelota(float startX, float startY) : x(startX), y(startY) {
        pelota.setRadius(10); // Radio de la pelota
        pelota.setPosition(x, y);
        pelota.setFillColor(Color::Red);
        velX = 0.2; // Velocidad en el eje X
        velY = 0.2; // Velocidad en el eje Y
    }

    void updatePosition() {
        x += velX;
        y += velY;
        pelota.setPosition(x, y);
    }

    void reverseX() {
        velX = -velX;
    }

    void reverseY() {
        velY = -velY;
    }

    CircleShape getShape() {
        return pelota;
    }

private:
    float x, y;
    float velX, velY;
    CircleShape pelota;
};
