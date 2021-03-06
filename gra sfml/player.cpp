#include "player.h"

#include <iostream>
#include <string>



//private functions
void Player::initTexture()
{
	


	for (int i = 0;i < 4;i++) {

		this->textures["PLAYER" + std::to_string(i)] = new sf::Texture();
		if (!this->textures["PLAYER" + std::to_string(i)]->loadFromFile("textures/player" + std::to_string(i) + ".png")) {
			std::cout << "ERROR player texture not loaded!" << std::endl;
		}
		


	}


}


void Player::initSprite()
{
	this->sprite.setTexture(*this->textures["PLAYER" + std::to_string(this->textureIndex)]);

	
	this->sprite.scale(1.f, 1.f);

}

void Player::initPosition(sf::RenderWindow* window)
{
	this->sprite.setPosition(window->getSize().x/2, window->getSize().y - this->sprite.getGlobalBounds().height - 10.f);
}



const sf::FloatRect Player::getBounds()
{
	return this->sprite.getGlobalBounds();
}

const sf::Sprite Player::getSprite()
{
	return this->sprite;
}




sf::Vector2f Player::getPos()
{
	return this->sprite.getPosition();
}



void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update(int textureIndex)
{
	this->sprite.setTexture(*this->textures["PLAYER" + std::to_string(textureIndex)]);
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);

}




Player::Player(sf::RenderWindow *window)
{

	this->movementSpeed = 10.f;
	this->initTexture(); 
	this->initSprite();
	this->initPosition(window);

}



Player::~Player()
{   

	for (auto& i : this->textures) {
		delete i.second;
	}
}
