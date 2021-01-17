#include "selectTrackMenu.h"


#include <iostream>

SelectTrackMenu::SelectTrackMenu(sf::RenderWindow* window)
{
	if (!this->menuFont.loadFromFile("fonts/Oxanium-ExtraBold.TTF")) {
		perror("ERROR: nie zaladowano fontu w pliku menu.cpp");
	}


	this->selectedIndex = 0;
	this->selectedTrackIndex = 0;
	this->initTextures();

	this->trackImage.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrackIndex)]);
	this->imgBounds = trackImage.getLocalBounds();
	this->trackImage.setOrigin(imgBounds.left + imgBounds.width / 2.0f, imgBounds.top + imgBounds.height / 2.0f);
	this->trackImage.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 8 * 2));
	this->trackImage.setScale(0.2, 0.2);



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

SelectTrackMenu::~SelectTrackMenu()
{
	for (auto& i : this->textures) {
		delete i.second;
	}
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

	if (this->selectedTrackIndex < 3) {
		this->selectedTrackIndex += 1;
		this->trackImage.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrackIndex)]);
	}
	return this->selectedTrackIndex;
}

int SelectTrackMenu::previous()
{

	if (this->selectedTrackIndex > 0) {
		this->selectedTrackIndex -= 1;
		this->trackImage.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrackIndex)]);

	}
	return this->selectedTrackIndex;

}

void SelectTrackMenu::reset()
{
	this->menuOptions[0].setFillColor(sf::Color::Red);
	this->menuOptions[1].setFillColor(sf::Color::White);
	this->menuOptions[2].setFillColor(sf::Color::White);
}
