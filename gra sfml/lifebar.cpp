#include "lifebar.h"

void Lifebar::initTextures()
{
	if (!this->texture.loadFromFile("textures/life.png")) {
		std::cout << "nie zaladowano tekstury lifebar"<< std::endl;
	}

}

void Lifebar::initSprite()
{
	for (int i = 0;i < sizeof(this->sprite) / sizeof(*this->sprite); i++) {
		this->sprite[i].setTexture(this->texture);
	}
}

void Lifebar::initPosition()
{
	for (int i = 0;i < sizeof(this->sprite) / sizeof(*this->sprite); i++) {
		this->sprite[i].setPosition(sf::Vector2f(this->window->getSize().x - 150.f + i * (20.f+10.f), 10.f));
	}
}

Lifebar::Lifebar(sf::RenderWindow* window)
{

	this->window = window;
	this->initTextures();
	this->initSprite();
	this->initPosition();
}

Lifebar::~Lifebar()
{
}


void Lifebar::drawMenu(sf::RenderWindow* window, int lifeCount)
{


	for (int i = 0; i < lifeCount; i++) {
		window->draw(this->sprite[i]);

	}

}

