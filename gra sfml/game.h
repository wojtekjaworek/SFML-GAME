#pragma once
#include "player.h"
#include "obstacle.h"
#include <map>

class Game {

private:

	//window
	sf::RenderWindow* window; //pointer to window

	//resourses, obstacles etc
	std::map<std::string, sf::Texture* > textures; //name of texture and texture itself, easy to navigate
	std::vector<Obstacle*> obstacles;


	//new stuff
	sf::Clock obstacleSpawnClock;
	sf::Clock lifeClock;
	sf::Time obstacleSpawnTime;
	sf::Time lifeTime;
	sf::Text lifeTimeCounter;
	sf::Font lifeTimeCounter_font;
	 
	//player 
	Player* player; //pointer to player to control it on the screen


	//private functions
	void initWindow();
	void initTextures();
	void initStuff(); // initialize other stuff like fonts etc.
	void initPlayer(sf::RenderWindow *window);
	



public:

	Game();
	virtual ~Game();

	//public functions
	void run();


	void updatePollEvents(); //speaks for itself
	void updateInput(); // control player class from keyboard etc
	void updateObstacles();
	void update();
	void render();

};