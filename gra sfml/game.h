#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
/*
Main game class
*/

class game
{

private: 
	//functions and variables that needs to be private


	sf::RenderWindow* window; // pointer to window
	sf::Event ev;
	sf::VideoMode VMode;
	
	sf::Sprite obstacles;
	sf::Texture obstacleTexture;

	void initVariables(); 
	void initWindow();
	void initObstacles();


public: // constructors & destructors
	game();
	virtual ~game();


	//accessors

	const bool checkIfWindowIsOpen() const;

	// functions
	void getEvents();
	void update();
	void render();
	



};
