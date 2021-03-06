#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>


class Obstacle
{

private:
	sf::Sprite shape;


	sf::Vector2f direction;
	float movementSpeed; 

public:
	Obstacle(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Obstacle();


	
	const sf::FloatRect getBounds();
	const sf::Vector2f getPos();
	const float getSpeed();
	
	
	void update();
	void render(sf::RenderTarget* target);
	void setNewTexture(sf::Texture* texture, bool resetRect);
	float setMovementSpeed(float speed);

};

