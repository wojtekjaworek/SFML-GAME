#pragma once
#include "player.h"
#include "obstacle.h"
#include "collision.h"
#include "save.h"
#include <map>
#include <fstream>

class Game {

private:

	//window
	sf::RenderWindow* window; //pointer to window

	//resourses, obstacles etc
	std::map<std::string, sf::Texture* > textures; //name of texture and texture itself, easy to navigate
	std::vector<Obstacle*> obstacles;

	std::vector<std::pair<std::string, std::vector<int>>> loadedDataFromSave;


	//new stuff
	sf::Clock obstacleSpawnClock;
	sf::Time obstacleSpawnTime;


	sf::Clock movementSpeedClock;
	sf::Time movementSpeedTime;
	float movementSpeed = 2; // initial value for speed of obstacles

	sf::Clock lifeClock;
	sf::Time lifeTime;


	sf::Text lifeTimeCounter;
	sf::Font lifeTimeCounter_font;


	struct loadSavedData {
		int score;
		int UnlockedCarID;
		int unlockedTrackID;
	};

	loadSavedData loadSaved;


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
	void saveGame();
	void loadSavedGame();
	void update();
	void render();

};