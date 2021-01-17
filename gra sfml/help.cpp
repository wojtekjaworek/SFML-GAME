#include "help.h"

Help::Help(sf::RenderWindow* window)
{

	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.TTF")) {
	}

	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions));i++) {
		this->menuOptions[i].setFont(this->menuFont);
		this->menuOptions[i].setCharacterSize(20);
		this->menuOptions[i].setFillColor(sf::Color::White);
	}


	this->menuOptions[0].setString(L"STEROWANIE - KLAWISZE STRZA£EK \n                     ESC - MENU PAUZY, \n                    F1 - EKRAN POMOCY");
	this->bounds[0] = menuOptions[0].getLocalBounds();
	this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 1));

	this->menuOptions[1].setString(L"TWOIM ZADANIEM JEST OMIJAÆ NADJE¯D¯AJ¥CE POJAZDY,\nPO PI¥TEJ KOLIZJI Z NADJE¯D¯AJ¥CYM POJAZDEM PRZEGRYWASZ");
	this->bounds[1] = menuOptions[1].getLocalBounds();
	this->menuOptions[1].setOrigin(bounds[1].left + bounds[1].width / 2.0f, bounds[1].top + bounds[1].height / 2.0f);
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 3));

	this->menuOptions[2].setString(L"PUNKTY ODPOWIADAJ¥ CZASOWI, PRZEZ JAKI UDA CI SIÊ UTRZYMAÆ W GRZE!");
	this->bounds[2] = menuOptions[2].getLocalBounds();
	this->menuOptions[2].setOrigin(bounds[2].left + bounds[2].width / 2.0f, bounds[2].top + bounds[2].height / 2.0f);
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 4));

	this->menuOptions[3].setString(L"GRA ZAPISUJÊ SIÊ AUTOMATYCZNIE PO PRZEGRANEJ,\nLUB PO WYBRANIU ODPOWIEDNIEJ POZYCJI Z MENU PAUZY");
	this->bounds[3] = menuOptions[3].getLocalBounds();
	this->menuOptions[3].setOrigin(bounds[3].left + bounds[3].width / 2.0f, bounds[3].top + bounds[3].height / 2.0f);
	this->menuOptions[3].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 5));

	this->menuOptions[4].setString(L"NACIŒNIJ ESC, ABY WYRÓCIÆ");
	this->bounds[4] = menuOptions[4].getLocalBounds();
	this->menuOptions[4].setOrigin(bounds[4].left + bounds[4].width / 2.0f, bounds[4].top + bounds[4].height / 2.0f);
	this->menuOptions[4].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 7));



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
