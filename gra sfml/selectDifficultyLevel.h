#pragma once
#include "SFML\Graphics.hpp"


class SelectDifficultyLevel
{

public:
	SelectDifficultyLevel(sf::RenderWindow* window); //*window for height and width
	virtual ~SelectDifficultyLevel();

	void drawMenu(sf::RenderWindow* window);
	void selectUp(); // navigate inside menu
	void selectDown();
	int selectLeft();
	int selectRight();
	int selectedIndex;
	int selectedDiffIndex;
	int diffLevel;


private:


	sf::Font menuFont;
	sf::Text menuOptions[2]; 
	std::string diffLeveltoPick[4] = { "< (1/4) latwy >", "< (2/4) sredni >", "< (3/4) trudny >", "< (4/4) eksremalny >" };


};

