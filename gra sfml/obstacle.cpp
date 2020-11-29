#include "obstacle.h"




//accessors
const sf::FloatRect Obstacle::getBounds()
{
	return this->shape.getGlobalBounds();
}





//private functions

// there are currently none

//



//public functions
void Obstacle::update()
{
	//movement of the obstacles

	this->shape.move(this->movementSpeed * this->direction);
}

void Obstacle::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}




//constructor and destructor

Obstacle::Obstacle(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed)
{
	this->shape.setTexture(*texture);
	this->shape.setPosition(posX, posY);
	
	//direction is a Vector2f, dirX, dirY are passed in
	this->direction.x = dirX;
	this->direction.y = dirY;
	this->movementSpeed = movementSpeed;
}

Obstacle::~Obstacle()
{

}