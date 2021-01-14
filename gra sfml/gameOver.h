#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class GameOver
{
public:
	GameOver(sf::RenderWindow* window);
	virtual ~GameOver();

	void drawMenu(sf::RenderWindow* window, float lifeTime_temp, sf::Time lifeTime);


private:

	sf::Font menuFont;
	sf::Text menuOptions[4];
	sf::FloatRect bounds[4];

};

