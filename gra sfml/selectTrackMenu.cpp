#include "selectTrackMenu.h"


#include <iostream>

SelectTrackMenu::SelectTrackMenu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/arial.ttf")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->selectedIndex = 0;
	this->selectedTrackIndex = 0;
	this->initTextures();

	this->trackImage.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrackIndex)]);
	this->trackImage.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 2));
	this->trackImage.setScale(0.2, 0.2);



	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString("KOLEJNY");
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 5));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString("POPRZEDNI");
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 6));

	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString("POWROT");
	this->menuOptions[2].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 7));


}

SelectTrackMenu::~SelectTrackMenu()
{
}

void SelectTrackMenu::drawMenu(sf::RenderWindow* window)
{
	window->draw(this->trackImage);
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		window->draw(this->menuOptions[i]);

	}
}



void SelectTrackMenu::initTextures()
{

	for (int i = 0;i < 4;i++) { // number of tracks in folder!!!!!!!!!!!!!

		this->textures["TRACK" + std::to_string(i)] = new sf::Texture();
		this->textures["TRACK" + std::to_string(i)]->loadFromFile("textures/track" + std::to_string(i) + ".png");


	}
}

void SelectTrackMenu::selectUp()
{
	if (this->selectedIndex > 0) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex -= 1;
		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}

}

void SelectTrackMenu::selectDown()
{
	if (this->selectedIndex < 2) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex += 1;

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}

}

int SelectTrackMenu::next()
{
	std::cout << "index przed: " << this->selectedTrackIndex << std::endl;

	if (this->selectedTrackIndex < 3) {
		this->selectedTrackIndex += 1;
		this->trackImage.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrackIndex)]);
		std::cout << "index po: " << this->selectedTrackIndex << std::endl;
	}
	return this->selectedTrackIndex;
}

int SelectTrackMenu::previous()
{
	std::cout << "index przed: " << this->selectedTrackIndex << std::endl;

	if (this->selectedTrackIndex > 0) {
		this->selectedTrackIndex -= 1;
		this->trackImage.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrackIndex)]);
		std::cout << "index po: " << this->selectedTrackIndex << std::endl;

	}
	return this->selectedTrackIndex;

}

void SelectTrackMenu::reset()
{
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[2].setFillColor(sf::Color::White);
}
