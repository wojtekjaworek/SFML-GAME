#pragma once
#include "SFML/Graphics.hpp"

class Menu
{

public:

	Menu(sf::RenderWindow *window); 
	virtual ~Menu();

	void drawMenu(sf::RenderWindow* window);

	void selectUp(); 
	void selectDown();
	int selectedIndex;



private:


	sf::Font menuFont;
	sf::Text menuOptions[6]; 
	sf::FloatRect bounds[6];
};

