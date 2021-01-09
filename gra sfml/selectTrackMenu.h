#pragma once
#include <SFML/Graphics.hpp>

class SelectTrackMenu
{

public:
	SelectTrackMenu(sf::RenderWindow* window); //*window for height and width
	virtual ~SelectTrackMenu();

	void drawMenu(sf::RenderWindow* window);
	void selectUp(); // navigate inside menu
	void selectDown();
	void next();
	void previous();
	void reset();
	void initTextures();
	int selectedIndex;
	int selectedTrackIndex;

	std::map<std::string, sf::Texture* > textures; //name of texture and texture itself, easy to navigate


private:

	sf::Sprite trackImage;
	sf::Font menuFont;
	sf::Text menuOptions[3];

};
