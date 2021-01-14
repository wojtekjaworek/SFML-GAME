#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Help
{

public:
	Help(sf::RenderWindow* window); //*window for height and width
	virtual ~Help();

	void drawMenu(sf::RenderWindow* window);


private:

	sf::Font menuFont;
	sf::Text menuOptions[4];
	


};

