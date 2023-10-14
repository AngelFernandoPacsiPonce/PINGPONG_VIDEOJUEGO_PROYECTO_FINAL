#include "MenuPrincipal.h"


Menuu::Menuu(float width, float hight)
{
	if (!font.loadFromFile("font.ttf")){}

	//JUGAR
	mainMenu[0].setFont(font);
	mainMenu[0].setColor(Color::Blue);
	mainMenu[0].setString("JUGAR");
	mainMenu[0].setCharacterSize(50);
	mainMenu[0].setPosition(Vector2f(width/2-50, hight / (Max_main_menu + 1)));

	//OPCIONES
	mainMenu[1].setFont(font);
	mainMenu[1].setColor(Color::Blue);
	mainMenu[1].setString("OPCIONES
	mainMenu[1].setCharacterSize(50);
	mainMenu[1].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_menu *2)));


	//SALIR
	mainMenu[2].setFont(font);
	mainMenu[2].setColor(Color::Blue);
	mainMenu[2].setString("SALIR
	mainMenu[2].setCharacterSize(50);
	mainMenu[2].setPosition(Vector2f(width / 2 - 50, hight / (Max_main_menu * 3)));

	MainMenuSelected = 0;
		


}

Menuu::~Menuu()
{



}


//FUNCION PA DIBUJAR

void Menuu::draw(RenderWindow& window)
{
	for (int i = 0; 1 < 3; i++)
	{
		window.draw(mainMenu[i});
	}
}

//FUNCION PARA EL MOVEDOWN

void Menuu::MoveDown()
{
	if(mainMenuSelected+1<=Max_main_menu)
	{
		mainMenu[MainMenuSelected].setColor(Color::White);

		MainMenuSelected++;
		if(mainMenuSelected==3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[MainMenuSelected].setColor(Color::Blue);

	}

}


//FUNCION PARA EL MOVEUP

void Menuu::MoveUp()
{
	if (mainMenuSelected -1  >= -1)
	{
		mainMenu[MainMenuSelected].setColor(Color::White);

		MainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = -2;
		}
		mainMenu[MainMenuSelected].setColor(Color::Blue);

	}

}