#pragma once
#include "SFML/Graphics.hpp"

class Menu
{

public:

	Menu(sf::RenderWindow *window); //*window for height and width
	virtual ~Menu();

	void drawMenu(sf::RenderWindow* window);

	void selectUp(); // navigate inside menu
	void selectDown();
	int selectedIndex;



private:


	sf::Font menuFont;
	sf::Text menuOptions[6]; // three different options in main menu: start game, select track, select car, select diff level, informations
	sf::FloatRect bounds[6];
};

