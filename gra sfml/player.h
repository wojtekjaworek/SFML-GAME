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
	std::map<std::string, sf::Texture* > textures; 


	float movementSpeed;
	int textureIndex;

	
	void initTexture();
	void initSprite();
	void initPosition(sf::RenderWindow* window);

	



public:
	Player(sf::RenderWindow *window);
	virtual ~Player();



	
	const sf::FloatRect getBounds();
	const sf::Sprite getSprite();


	sf::Vector2f getPos();
	void move(const float dirX, const float dirY);
	void update(int textureIndex);
	void render(sf::RenderTarget& target);
};

