#pragma once
#include "SFML\Graphics.hpp"


class SelectCarMenu
{

public:
	SelectCarMenu(sf::RenderWindow* window); //*window for height and width
	virtual ~SelectCarMenu();

	void drawMenu(sf::RenderWindow* window);
	void selectUp(); // navigate inside menu
	void selectDown();
	void next();
	void previous();
	void initTextures();
	int selectedIndex;
	int selectedCarIndex;

	std::map<std::string, sf::Texture* > textures; //name of texture and texture itself, easy to navigate


private:

	sf::Sprite carImage;
	sf::Font menuFont;
	sf::Text menuOptions[3];

};

