#pragma once
#include "SFML\Graphics.hpp"


class PauseMenu
{

public:
	PauseMenu(sf::RenderWindow* window);
	virtual ~PauseMenu();

	void drawMenu(sf::RenderWindow* window);
	void selectUp(); 
	void selectDown();
	int selectedIndex;


private:

	
	sf::Font menuFont;
	sf::Text menuOptions[3]; 
	sf::FloatRect bounds[3];
};

