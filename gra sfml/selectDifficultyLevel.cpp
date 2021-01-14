#include "selectDifficultyLevel.h"

#include <iostream>

SelectDifficultyLevel::SelectDifficultyLevel(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.TTF")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->selectedIndex = 0;
	this->selectedDiffIndex = 0;


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString(this->diffLeveltoPick[this->selectedIndex]);
	this->bounds[0] = menuOptions[0].getLocalBounds();
	this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 3 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString("POWROT");
	this->bounds[1] = menuOptions[1].getLocalBounds();
	this->menuOptions[1].setOrigin(bounds[1].left + bounds[1].width / 2.0f, bounds[1].top + bounds[1].height / 2.0f);
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 3 * 2));


}

SelectDifficultyLevel::~SelectDifficultyLevel()
{
}

void SelectDifficultyLevel::drawMenu(sf::RenderWindow* window)
{
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		window->draw(this->menuOptions[i]);
	}
}

int SelectDifficultyLevel::selectLeft()
{
	if (this->selectedIndex == 0) {
		if (this->selectedDiffIndex > 0) {

			this->selectedDiffIndex -= 1;
			this->menuOptions[0].setString(this->diffLeveltoPick[this->selectedDiffIndex]);
			this->bounds[0] = menuOptions[0].getLocalBounds();
			this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);

		}
	}
	return this->selectedDiffIndex;
}

int SelectDifficultyLevel::selectRight()
{
	if (this->selectedIndex == 0) {
		if (this->selectedDiffIndex < 3) {

			this->selectedDiffIndex += 1;
			this->menuOptions[0].setString(this->diffLeveltoPick[this->selectedDiffIndex]);
			this->bounds[0] = menuOptions[0].getLocalBounds();
			this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);

		}
	}
	return this->selectedDiffIndex;

}

void SelectDifficultyLevel::reset()
{
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[1].setFillColor(sf::Color::White);

}

void SelectDifficultyLevel::selectUp()
{

	if (this->selectedIndex > 0) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex -= 1;
		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
}

void SelectDifficultyLevel::selectDown()
{


	if (this->selectedIndex < 1) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex += 1;

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
}
