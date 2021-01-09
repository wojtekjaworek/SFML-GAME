#include "menu.h"
#include <iostream>

Menu::Menu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/arial.ttf")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString("WCZYTAJ ZAPISANA GRE");
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString("ROZPOCZNIJ GRE");
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 2));

	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString("WYBIERZ AUTO");
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 3));

	this->menuOptions[3].setFont(this->menuFont);
	this->menuOptions[3].setFillColor(sf::Color::White);
	this->menuOptions[3].setString("WYBIERZ TOR");
	this->menuOptions[3].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 4));

	this->menuOptions[4].setFont(this->menuFont);
	this->menuOptions[4].setFillColor(sf::Color::White);
	this->menuOptions[4].setString("WYBIERZ POZIOM TRUDNOSCI");
	this->menuOptions[4].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 7 * 5));

	this->menuOptions[5].setFont(this->menuFont);
	this->menuOptions[5].setFillColor(sf::Color::White);
	this->menuOptions[5].setString("INFORMACJE");
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
