#include "selectCarMenu.h"

#include <iostream>

SelectCarMenu::SelectCarMenu(sf::RenderWindow* window)
{

	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.TTF")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->selectedIndex = 0;
	this->selectedCarIndex = 0;
	this->initTextures();

	this->carImage.setTexture(*this->textures["PLAYER" + std::to_string(this->selectedCarIndex)]);
	this->imgBounds = carImage.getLocalBounds();
	this->carImage.setOrigin(imgBounds.left + imgBounds.width / 2.0f, 0.f);
	this->carImage.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 2));



	this->menuOptions[0].setFont(this->menuFont);
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[0].setString(L"KOLEJNY");
	this->bounds[0] = menuOptions[0].getLocalBounds();
	this->menuOptions[0].setOrigin(bounds[0].left + bounds[0].width / 2.0f, bounds[0].top + bounds[0].height / 2.0f);
	this->menuOptions[0].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 5));

	this->menuOptions[1].setFont(this->menuFont);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[1].setString(L"POPRZEDNI");
	this->bounds[1] = menuOptions[1].getLocalBounds();
	this->menuOptions[1].setOrigin(bounds[1].left + bounds[1].width / 2.0f, bounds[1].top + bounds[1].height / 2.0f);
	this->menuOptions[1].setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 6));

	this->menuOptions[2].setFont(this->menuFont);
	this->menuOptions[2].setFillColor(sf::Color::White);
	this->menuOptions[2].setString(L"POWRÓT");
	this->bounds[2] = menuOptions[2].getLocalBounds();
	this->menuOptions[2].setOrigin(bounds[2].left + bounds[2].width / 2.0f, bounds[2].top + bounds[2].height / 2.0f);
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

	if (this->selectedCarIndex < 3) {
		this->selectedCarIndex += 1;
		this->carImage.setTexture(*this->textures["PLAYER" + std::to_string(this->selectedCarIndex)]);
		this->imgBounds = carImage.getLocalBounds();
		this->carImage.setOrigin(imgBounds.left + imgBounds.width / 2.0f, 0.f);
	}

	return this->selectedCarIndex;
}

int SelectCarMenu::previous()
{

	if (this->selectedCarIndex > 0) {
		this->selectedCarIndex -= 1;
		this->carImage.setTexture(*this->textures["PLAYER" + std::to_string(this->selectedCarIndex)]);
		this->imgBounds = carImage.getLocalBounds();
		this->carImage.setOrigin(imgBounds.left + imgBounds.width / 2.0f, 0.f);

	}
	return this->selectedCarIndex;

}

void SelectCarMenu::reset()
{
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[2].setFillColor(sf::Color::White);
}
