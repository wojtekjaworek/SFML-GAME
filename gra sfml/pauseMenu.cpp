#include "pauseMenu.h"


#include <iostream>

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/arial.ttf")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString("WZNOW");
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString("ZAPISZ");
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4 * 2));


	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString("WYJDZ Z GRY");
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4 * 3));

	this->selectedIndex = 0;
}

PauseMenu::~PauseMenu()
{
}

void PauseMenu::drawMenu(sf::RenderWindow* window)
{
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		window->draw(this->menuOptions[i]);
	}
}

void PauseMenu::selectUp()
{

	if (this->selectedIndex > 0) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex -= 1;
		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
}

void PauseMenu::selectDown()
{

	if (this->selectedIndex < 2) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex += 1;

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
}
