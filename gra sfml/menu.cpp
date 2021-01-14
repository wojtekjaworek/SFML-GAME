#include "menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.ttf")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString(L"WCZYTAJ ZAPISANA GRÊ");
	this->bounds[0] = menuOptions[0].getLocalBounds();
	this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString(L"ROZPOCZNIJ GRÊ");
	this->bounds[1] = menuOptions[1].getLocalBounds();
	this->menuOptions[1].setOrigin(bounds[1].left + bounds[1].width / 2.0f, bounds[1].top + bounds[1].height / 2.0f);
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 2));

	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString(L"WYBIERZ AUTO");
	this->bounds[2] = menuOptions[2].getLocalBounds();
	this->menuOptions[2].setOrigin(bounds[2].left + bounds[2].width / 2.0f, bounds[2].top + bounds[2].height / 2.0f);
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 3));

	this->menuOptions[3].setFont(this->menuFont);
	this->menuOptions[3].setFillColor(sf::Color::White);
	this->menuOptions[3].setString(L"WYBIERZ TOR");
	this->bounds[3] = menuOptions[3].getLocalBounds();
	this->menuOptions[3].setOrigin(bounds[3].left + bounds[3].width / 2.0f, bounds[3].top + bounds[3].height / 2.0f);
	this->menuOptions[3].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 4));

	this->menuOptions[4].setFont(this->menuFont);
	this->menuOptions[4].setFillColor(sf::Color::White);
	this->menuOptions[4].setString(L"WYBIERZ POZIOM TRUDNOŒCI");
	this->bounds[4] = menuOptions[4].getLocalBounds();
	this->menuOptions[4].setOrigin(bounds[4].left + bounds[4].width / 2.0f, bounds[4].top + bounds[4].height / 2.0f);
	this->menuOptions[4].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 5));

	this->menuOptions[5].setFont(this->menuFont);
	this->menuOptions[5].setFillColor(sf::Color::White);
	this->menuOptions[5].setString(L"INFORMACJE");
	this->bounds[5] = menuOptions[5].getLocalBounds();
	this->menuOptions[5].setOrigin(bounds[5].left + bounds[5].width / 2.0f, bounds[5].top + bounds[5].height / 2.0f);
	this->menuOptions[5].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 6));

	


	this->selectedIndex = 0;
}

Menu::~Menu()
{
}

void Menu::drawMenu(sf::RenderWindow* window)
{
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		window->draw(this->menuOptions[i]);
	}
}

void Menu::selectUp()
{

	if (this->selectedIndex > 0) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex -= 1;
		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
}

void Menu::selectDown()
{

	if (this->selectedIndex < 5) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex += 1;

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
}
