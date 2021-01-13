#include "help.h"

Help::Help(sf::RenderWindow* window)
{

	if (!this->menuFont.loadFromFile("fonts/arial.ttf")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::White);
	this->menuOptions[0].setString("pierwsza linijka tekstu");
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString("druga linijka tekstu");
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 2));

	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString("trzecia linijka tekstu");
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 3));

	this->menuOptions[3].setFont(this->menuFont);
	this->menuOptions[3].setFillColor(sf::Color::White);
	this->menuOptions[3].setString("NACISNIJ ESC ZEBY WYROCIC");
	this->menuOptions[3].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 4));
}

Help::~Help()
{
}



void Help::drawMenu(sf::RenderWindow* window)
{
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		window->draw(this->menuOptions[i]);
	}
}
