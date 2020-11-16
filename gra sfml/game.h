#pragma once
#include "player.h"

class Game {

private:
	sf::RenderWindow* window; //pointer to window

	//player 
	Player* player; //pointer to player to control it on the screen


	//private functions
	void initWindow();
	void initPlayer();



public:

	Game();
	virtual ~Game();

	//public functions
	void run();

	void update();
	void render();

};