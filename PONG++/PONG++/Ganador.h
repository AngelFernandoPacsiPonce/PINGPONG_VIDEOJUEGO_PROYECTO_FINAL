#pragma once
#include <SFML/Graphics.hpp>
#include "Pantalla.h"

class Ganador : public Pantalla {
public:
    Ganador(sf::RenderWindow& mainWindow, int ganador);
    int mostrar();
    virtual void MoveUp() override;
    virtual void MoveDown() override;
    int getSelectedOption();

private:
    int selectedItemIndex;
    sf::Text textoGanador;
    sf::Text reiniciarTexto;
    sf::Text siguienteNivelTexto;
    sf::Text salirTexto;

    void Reiniciar();
    void SiguienteNivel();
    void Salir();
};
