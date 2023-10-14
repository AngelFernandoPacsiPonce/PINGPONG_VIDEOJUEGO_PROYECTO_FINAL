#pragma once
#include <SFML/Graphics.hpp>
#define Max_main_menu 3

using namespace std;
using namespace sf;
class Menuu
{

public:
	Menuu(float width, float hight);
	
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();

	~Menuu();

private:
	int MainMenuSelected;
	Font font;
	Text mainMenu[Max_main_menu];

};