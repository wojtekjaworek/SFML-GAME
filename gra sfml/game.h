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
#include "help.h"
#include "gameOver.h"
#include <map>
#include <vector>
#include <fstream>








class Game {

private:

	
	sf::RenderWindow* window; 

	//resourses
	std::map<std::string, sf::Texture* > textures; 
	std::vector<Obstacle*> obstacles;

	std::vector<Obstacle*> lights;
	sf::Clock spawnLightsClock;


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

	Help* help;
	bool helpFlag = false;


	 
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
		float totalScore;
		float lifeTime;
		float movementTime;
		float obstacleSpawnTime;
		int numberOfUnlockedCars;
		int numberOfUnlockedTracks;
		int unlockedDifficultyLevel;
		int selectedCar;
		int selectedTrack;
		int diffLevel;
	};

	loadSavedData loadSaved;
	std::vector<std::pair<std::string, std::vector<float>>> loadedDataFromSave;


	bool isDataLoaded = false;


	
	Player* player; 

	


	Collision* collisionDetection;

	int indexOfCollidingObstacle;
	bool collisionBool = false;


	Collision* collisionFor2Obstacles;
	sf::Vector2i indexes; 



	Lifebar* lifebar;
	bool lifebarFlag = false;
	int lifeCount = 5;
	
	GameOver* gameOver;
	bool gameOverFlag = false;

	bool endWtihCodeOne = false;
	bool endWithCodeZero = false;



	

	int numberOfUnlockedCars = 0;
	int numberOfUnlockedTracks = 0;
	int UnlockedDifficultyLevel = 0;
	float totalScore = 0.f;

	int change = 0;
	sf::Clock animateBackgroundClock;

	sf::Clock deleteObstacleClock;





	
	void initWindow();
	void initTextures();
	void initFonts(); 
	void initPlayer(sf::RenderWindow *window); 
	void initMainMenu();
	void initPauseMenu();
	void initSelectDifficultyLevel();
	void initSelectCarMenu();
	void initSelectTrackMenu();
	void initHelp();
	void initClocks();
	void initBackground();
	void initCollisionDetection();
	void initLifebar();
	void initGameOver();




public:

	Game();
	virtual ~Game();



	
	int run();

	
	void updatePollEvents(); 
	void updateInput(); 
	void updateObstacles();
	void updateObstaclesSpeed();
	void updateObstalesPosition();
	void updatePlayer();
	void updateBackground();
	void updateLights();
	void resetTime();
	void showMenu(sf::RenderWindow* window);
	void showPauseMenu(sf::RenderWindow* window);
	void showSelectDifficultyLevelMenu(sf::RenderWindow* window);
	void showSelectCarMenu(sf::RenderWindow* window);
	void showSelectTrackMenu(sf::RenderWindow* window);
	void showLifebar(sf::RenderWindow* window, int lifeCount);
	void showHelp(sf::RenderWindow* window);
	void showGameOver(sf::RenderWindow* window, float lifeTime_temp, sf::Time lifeTime);
	void saveGame();
	void loadSavedGame();
	void lookForCollision();
	void processCollision(); // kod wykonywany po zderzeniu z przeszkoda
	void update();
	void render();
	void pauseGame();
	void resumeGame();

	

	void gameProgress();
	void initLoadedVariables();
	void animateBackground();
	void gameOverFunc();


};