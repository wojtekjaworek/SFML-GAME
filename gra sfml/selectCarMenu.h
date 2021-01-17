#pragma once
#include "SFML\Graphics.hpp"


class SelectCarMenu
{

public:
	SelectCarMenu(sf::RenderWindow* window); 
	virtual ~SelectCarMenu();

	void drawMenu(sf::RenderWindow* window);
	void selectUp(); 
	void selectDown();
	int next();
	int previous();
	void reset();
	void initTextures();
	int selectedIndex;
	int selectedCarIndex;

	std::map<std::string, sf::Texture* > textures; 


private:


	sf::Sprite carImage;
	sf::Font menuFont;
	sf::Text menuOptions[3];
	sf::FloatRect bounds[3];
	sf::FloatRect imgBounds;

};

