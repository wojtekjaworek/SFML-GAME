#include "obstacle.h"





const sf::FloatRect Obstacle::getBounds()
{
	return this->shape.getGlobalBounds();
}

const sf::Vector2f Obstacle::getPos()
{
	return this->shape.getPosition();
}

const float Obstacle::getSpeed()
{
	return this->movementSpeed;
}







void Obstacle::update()
{
	

	this->shape.move(this->movementSpeed * this->direction);
}

void Obstacle::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}

void Obstacle::setNewTexture(sf::Texture* texture, bool resetRect)
{
	this->shape.setTexture(*texture, resetRect);
}

float Obstacle::setMovementSpeed(float speed)
{

	this->movementSpeed = speed;
	return this->movementSpeed;
}







Obstacle::Obstacle(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(posX, posY);
	
	
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = setMovementSpeed(movementSpeed);
}

Obstacle::~Obstacle()
{

}