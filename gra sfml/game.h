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
#include "lifebar.h"
#include <map>
#include <vector>
#include <fstream>

class Game {

private:

	
	sf::RenderWindow* window; 

	//resourses
	std::map<std::string, sf::Texture* > textures; 
	std::vector<Obstacle*> obstacles;

	std::vector<std::pair<std::string, std::vector<float>>> loadedDataFromSave;

	sf::Sprite background;

	Menu* mainMenu;
	bool mainMenuFlag = true;

	PauseMenu* pauseMenu;
	bool pauseMenuFlag = false;

	SelectDifficultyLevel* selectDifficultyLevel;
	bool selectDifficultyLevelFlag = false;
	int diffLevel = 0; 

	SelectCarMenu* selectCarMenu;
	bool selectCarMenuFlag = false;
	int selectedCar = 0;

	SelectTrackMenu* selectTrackMenu;
	bool selectTrackMenuFlag = false;
	int selectedTrack = 0;


	 
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
	Player* player; 

	


	Collision* collisionDetection;

	int indexOfCollidingObstacle;
	bool collisionBool = false;



	Lifebar* lifebar;
	bool lifebarFlag = false;
	int lifeCount = 5;




	//ZMIENNE DO TESTOWYCH FUNKCJI

	int numberOfUnlockedCars = 0;
	int numberOfUnlockedTracks = 0;
	int UnlockedDifficultyLevel = 0;
	float totalScore = 0.f;





	//private functions
	void initWindow();
	void initTextures();
	void initStuff(); // initialize other stuff like fonts etc.
	void initPlayer(sf::RenderWindow *window); // textureIndex is the same as selectedCar
	void initMainMenu();
	void initPauseMenu();
	void initSelectDifficultyLevel();
	void initSelectCarMenu();
	void initSelectTrackMenu();
	void initClocks();
	void initBackground();
	void initCollisionDetection();
	void initLifebar();




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
	void updatePlayer();
	void updateBackground();
	void resetTime();
	void showMenu(sf::RenderWindow* window);
	void showPauseMenu(sf::RenderWindow* window);
	void showSelectDifficultyLevelMenu(sf::RenderWindow* window);
	void showSelectCarMenu(sf::RenderWindow* window);
	void showSelectTrackMenu(sf::RenderWindow* window);
	void showLifebar(sf::RenderWindow* window, int lifeCount);
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