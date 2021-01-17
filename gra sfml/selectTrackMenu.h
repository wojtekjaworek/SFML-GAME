#pragma once
#include <SFML/Graphics.hpp>

class SelectTrackMenu
{

public:
	SelectTrackMenu(sf::RenderWindow* window); 
	virtual ~SelectTrackMenu();

	void drawMenu(sf::RenderWindow* window);
	void selectUp();
	void selectDown();
	int next();
	int previous();
	void reset();
	void initTextures();
	int selectedIndex;
	int selectedTrackIndex;

	std::map<std::string, sf::Texture* > textures; 

private:

	sf::Sprite trackImage;
	sf::Font menuFont;
	sf::Text menuOptions[3];
	sf::FloatRect bounds[3];
	sf::FloatRect imgBounds;

};
