#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;

	float movementSpeed;

	//functions
	void initTexture();
	void initSprite();
	


public:
	Player();
	virtual ~Player();

	//functions
	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};

