#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Help
{

public:
	Help(sf::RenderWindow* window); 
	virtual ~Help();

	void drawMenu(sf::RenderWindow* window);


private:

	sf::Font menuFont;
	sf::Text menuOptions[5];
	sf::FloatRect bounds[5];
	


};

