#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class Lifebar
{
private:

	sf::Sprite sprite[5]; // sprajty to serduszka zycia
	sf::Texture texture;



	
	void initTextures();
	void initSprite();
	void initPosition();
	sf::RenderWindow* window;



public:
	Lifebar(sf::RenderWindow* window); 
	virtual ~Lifebar();

	void drawMenu(sf::RenderWindow* window, int lifeCount);



};

