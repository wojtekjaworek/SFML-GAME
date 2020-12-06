#pragma once
#include "SFML\Graphics.hpp"


class PauseMenu
{

public:
	PauseMenu(sf::RenderWindow* window); //*window for height and width
	virtual ~PauseMenu();

	void drawMenu(sf::RenderWindow* window);
	void selectUp(); // navigate inside menu
	void selectDown();
	int selectedIndex;


private:

	
	sf::Font menuFont;
	sf::Text menuOptions[3]; // three different options in main menu: start game, select track, select car, informations

};

