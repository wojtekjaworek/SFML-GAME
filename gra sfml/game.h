#pragma once
#include "player.h"
#include "obstacle.h"
#include "collision.h"
#include "save.h"
#include "menu.h"
#include "pauseMenu.h"
#include "selectDifficultyLevel.h"
#include "selectCarMenu.h"
#include "selectTrackMenu.h"
#include <map>
#include <vector>
#include <fstream>

class Game {

private:

	//window
	sf::RenderWindow* window; //pointer to window

	//resourses, obstacles etc
	std::map<std::string, sf::Texture* > textures; //name of texture and texture itself, easy to navigate
	std::vector<Obstacle*> obstacles;

	std::vector<std::pair<std::string, std::vector<float>>> loadedDataFromSave;

	sf::Sprite background;

	Menu* mainMenu;
	bool mainMenuFlag = true;

	PauseMenu* pauseMenu;
	bool pauseMenuFlag = false;

	SelectDifficultyLevel* selectDifficultyLevel;
	bool selectDifficultyLevelFlag = false;
	int diffLevel = 0; //int in range 0,1,2,3, where 0 = easy, 1 = mid, 2 = hard, 3 = extreme

	SelectCarMenu* selectCarMenu;
	bool selectCarMenuFlag = false;
	int selectedCar = 0;

	SelectTrackMenu* selectTrackMenu;
	bool selectTrackMenuFlag = false;


	//stuff 
	sf::Clock obstacleSpawnClock;
	sf::Time obstacleSpawnTime;
	float obstacleSpawnTime_temp;

	sf::Clock movementSpeedClock;
	sf::Time movementSpeedTime;
	float movementSpeedTime_temp;
	float movementSpeed = 2; // initial value for speed of obstacles

	sf::Clock lifeClock;
	sf::Time lifeTime;
	float lifeTime_temp;


	sf::Text lifeTimeCounter;
	sf::Font lifeTimeCounter_font;


	struct loadSavedData {
		int score;
		int UnlockedCarID;
		int unlockedTrackID;
	};

	loadSavedData loadSaved;

	bool isDataLoaded = false;


	//player 
	Player* player; //pointer to player to control it on the screen

	


	Collision* collisionDetection;

	int indexOfCollidingObstacle;

	//ZMIENNE DO TESTOWYCH FUNKCJI

	int numberOfUnlockedCars = 0;
	int numberOfUnlockedTracks = 0;
	int UnlockedDifficultyLevel = 0;
	float totalScore = 0.f;





	//private functions
	void initWindow();
	void initTextures();
	void initStuff(); // initialize other stuff like fonts etc.
	void initPlayer(sf::RenderWindow *window);
	void initMainMenu();
	void initPauseMenu();
	void initSelectDifficultyLevel();
	void initSelectCarMenu();
	void initSelectTrackMenu();
	void initClocks();
	void initBackground();
	void initCollisionDetection();
	




public:

	Game();
	virtual ~Game();



	//public functions
	void run();


	void updatePollEvents(); 
	void updateInput(); 
	void updateObstacles();
	void updateObstaclesSpeed();
	void updateObstalesPosition();
	void resetTime();
	void showMenu(sf::RenderWindow* window);
	void showPauseMenu(sf::RenderWindow* window);
	void showSelectDifficultyLevelMenu(sf::RenderWindow* window);
	void showSelectCarMenu(sf::RenderWindow* window);
	void showSelectTrackMenu(sf::RenderWindow* window);
	void saveGame();
	void loadSavedGame();
	void lookForCollision();
	void processCollision(); // kod wykonywany po zderzeniu z przeszkoda
	void update();
	void render();
	void pauseGame();
	void resumeGame();

	//TESTOWE FUNKCJE

	void gameProgress();
	void initLoadedVariables();



};