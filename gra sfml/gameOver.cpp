
#include "gameOver.h"


GameOver::GameOver(sf::RenderWindow* window)
{

	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.TTF")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::White);
	this->menuOptions[0].setString(L"GAME OVER");
	this->bounds[0] = menuOptions[0].getLocalBounds();
	this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 1));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString(L"TWÓJ WYNIK TO:");
	this->bounds[1] = menuOptions[1].getLocalBounds();
	this->menuOptions[1].setOrigin(bounds[1].left + bounds[1].width / 2.0f, bounds[1].top + bounds[1].height / 2.0f);
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 2));

	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString(L"trzecia linijka tekstu");
	this->bounds[2] = menuOptions[2].getLocalBounds();
	this->menuOptions[2].setOrigin(bounds[2].left + bounds[2].width / 2.0f, bounds[2].top + bounds[2].height / 2.0f);
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 3));

	this->menuOptions[3].setFont(this->menuFont);
	this->menuOptions[3].setFillColor(sf::Color::White);
	this->menuOptions[3].setString(L"NACIŒNIJ ENTER ABY KONTYNUOWAÆ");
	this->bounds[3] = menuOptions[3].getLocalBounds();
	this->menuOptions[3].setOrigin(bounds[3].left + bounds[3].width / 2.0f, bounds[3].top + bounds[3].height / 2.0f);
	this->menuOptions[3].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 4));
}

GameOver::~GameOver()
{
}



void GameOver::drawMenu(sf::RenderWindow* window, float lifeTime_temp, sf::Time lifeTime)
{
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		if (i == 2) {
			this->menuOptions[i].setString(std::to_string(lifeTime_temp + lifeTime.asSeconds()));
			this->bounds[i] = menuOptions[i].getLocalBounds();
			this->menuOptions[i].setOrigin(bounds[i].left + bounds[i].width / 2.0f, bounds[i].top + bounds[i].height / 2.0f);
		}
		window->draw(this->menuOptions[i]);
	}
}
