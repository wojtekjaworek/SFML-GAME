#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>


class Obstacle
{

private:
	sf::Sprite shape;


	sf::Vector2f direction;
	float movementSpeed; // speed of obstacles 

public:
	Obstacle(sf::Texture* texture, float posX, float posY, float dirX, float dirY, float movementSpeed);
	virtual ~Obstacle();


	//accessor
	const sf::FloatRect getBounds();
	const sf::Vector2f getPos();

	//functions
	void update();
	void render(sf::RenderTarget* target);
	float setMovementSpeed(float speed);

};

