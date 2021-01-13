#include "selectCarMenu.h"

#include <iostream>

SelectCarMenu::SelectCarMenu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/arial.ttf")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->selectedIndex = 0;
	this->selectedCarIndex = 0;
	this->initTextures();

	this->carImage.setTexture(*this->textures["PLAYER" + std::to_string(this->selectedCarIndex)]);
	this->carImage.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 2));



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

SelectCarMenu::~SelectCarMenu()
{
	for (auto& i : this->textures) {
		delete i.second;
	}
}

void SelectCarMenu::drawMenu(sf::RenderWindow* window)
{
	window->draw(this->carImage);
	for (int i = 0; i < (sizeof(this->menuOptions) / sizeof(*this->menuOptions)); i++) {
		window->draw(this->menuOptions[i]);
		
	}
}



void SelectCarMenu::initTextures()
{

	for (int i = 0;i < 4;i++) {
		this->textures["PLAYER" + std::to_string(i)] = new sf::Texture();
		this->textures["PLAYER" + std::to_string(i)]->loadFromFile("textures/player" + std::to_string(i) + ".png");


	}
}

void SelectCarMenu::selectUp()
{
	if (this->selectedIndex > 0) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex -= 1;
		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}
	
}

void SelectCarMenu::selectDown()
{
	if (this->selectedIndex < 2) {

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::White);
		this->selectedIndex += 1;

		this->menuOptions[this->selectedIndex].setFillColor(sf::Color::Red);

	}

}

int SelectCarMenu::next()
{
	std::cout << "index przed: " << this->selectedCarIndex << std::endl;

	if (this->selectedCarIndex < 3) {
		this->selectedCarIndex += 1;
		this->carImage.setTexture(*this->textures["PLAYER" + std::to_string(this->selectedCarIndex)]);
		std::cout << "index po: " << this->selectedCarIndex << std::endl;
	}
	return this->selectedCarIndex;
}

int SelectCarMenu::previous()
{
	std::cout << "index przed: " << this->selectedCarIndex << std::endl;

	if (this->selectedCarIndex > 0) {
		this->selectedCarIndex -= 1;
		this->carImage.setTexture(*this->textures["PLAYER" + std::to_string(this->selectedCarIndex)]);
		std::cout << "index po: " << this->selectedCarIndex << std::endl;

	}
	return this->selectedCarIndex;

}

void SelectCarMenu::reset()
{
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[2].setFillColor(sf::Color::White);
}
