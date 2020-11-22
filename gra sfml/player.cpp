#include "player.h"

#include <iostream>


//private functions
void Player::initTexture()
{
	//load from file, if not problem occurs returns error message
	if (!this->texture.loadFromFile("textures/test.png")) {
		std::cout << "Error: player.cpp -> initTexture():: texture file not loaded!"<< std::endl;
	}

}


void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

	//resize the sprite, original texture will be high resolution, so it have to fit on the screen and keep desired size
	this->sprite.scale(1.f, 1.f);

}

void Player::initPosition(sf::RenderWindow* window)
{
	this->sprite.setPosition(window->getSize().x/2, window->getSize().y - this->sprite.getGlobalBounds().height - 10.f);
}


//public functions
void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

}



//constructor & destructor
Player::Player(sf::RenderWindow *window)
{

	this->movementSpeed = 10.f;
	this->initTexture(); //before initSprite!!
	this->initSprite();
	this->initPosition(window);

}

Player::~Player()
{ 
}
