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
	void reset();
	int selectedIndex;
	int selectedDiffIndex;
	int diffLevel;


private:


	sf::Font menuFont;
	sf::Text menuOptions[2]; 
	sf::String diffLeveltoPick[4] = { L"< (1/4) £ATWY >", L"< (2/4) ŒREDNI >", L"< (3/4) TRUDY >", L"< (4/4) EKSTREMALNY >" };
	sf::FloatRect bounds[2];

};

