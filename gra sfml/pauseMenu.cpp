#include "pauseMenu.h"


#include <iostream>

PauseMenu::PauseMenu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.TTF")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString(L"WZNÓW");
	this->bounds[0] = menuOptions[0].getLocalBounds();
	this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString(L"ZAPISZ");
	this->bounds[1] = menuOptions[1].getLocalBounds();
	this->menuOptions[1].setOrigin(bounds[1].left + bounds[1].width / 2.0f, bounds[1].top + bounds[1].height / 2.0f);
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 4 * 2));


	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString(L"WYJD Z GRY");
	this->bounds[2] = menuOptions[2].getLocalBounds();
	this->menuOptions[2].setOrigin(bounds[2].left + bounds[2].width / 2.0f, bounds[2].top + bounds[2].height / 2.0f);
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
