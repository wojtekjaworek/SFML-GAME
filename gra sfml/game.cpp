#include "game.h"

#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include <Windows.h>

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Redline Racing", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initTextures()
{
	


	for (int i = 0;i < 6;i++) { // number of obstacle textures in folder

		this->textures["OBSTACLE" + std::to_string(i)] = new sf::Texture();
		this->textures["OBSTACLE" + std::to_string(i)]->loadFromFile("textures/obstacle" + std::to_string(i) + ".png");


	}



	for (int i = 0;i < 4;i++) { // number of tracks in folder

		this->textures["TRACK" + std::to_string(i)] = new sf::Texture();
		this->textures["TRACK" + std::to_string(i)]->loadFromFile("textures/track" + std::to_string(i) + ".png");
	}


	for (int i = 0;i < 1;i++) {
		this->textures["OTHER" + std::to_string(i)] = new sf::Texture();
		this->textures["OTHER" + std::to_string(i)]->loadFromFile("textures/other" + std::to_string(i) + ".png");
	}

}


void Game::initFonts()
{
	this->lifeTimeCounter_font.loadFromFile("fonts/BTTF.ttf"); 
	this->lifeTimeCounter.setFont(lifeTimeCounter_font);
}


void Game::initPlayer(sf::RenderWindow *window)
{
	this->player = new Player(window);

}

void Game::initMainMenu()
{
	this->mainMenu = new Menu(this->window);

}

void Game::initPauseMenu()
{
	this->pauseMenu = new PauseMenu(this->window);
}

void Game::initSelectDifficultyLevel() 
{
	this->selectDifficultyLevel = new SelectDifficultyLevel(this->window);
}

void Game::initSelectCarMenu()
{
	this->selectCarMenu = new SelectCarMenu(this->window);
}

void Game::initSelectTrackMenu()
{
	this->selectTrackMenu = new SelectTrackMenu(this->window);
}

void Game::initHelp()
{
	this->help = new Help(this->window);
}

void Game::initClocks()
{
	  
	this->obstacleSpawnClock.restart();
	this->movementSpeedClock.restart();
	this->lifeClock.restart();
	this->animateBackgroundClock.restart();
}

void Game::initBackground()
{
	this->background.setTexture(*this->textures["TRACK"  + std::to_string(this->selectedTrack)]);
	

	this->background.setPosition(sf::Vector2f(0.f, -300.f));
}



void Game::initCollisionDetection()
{
	this->collisionDetection = new Collision(this->player, this->obstacles);
	this->collisionFor2Obstacles = new Collision(this->obstacles, this->obstacles);
	this->indexes.x = 9999;
	this->indexes.y = 9999;
}

void Game::initLifebar()
{
	this->lifebar = new Lifebar(this->window);
}

void Game::initGameOver()
{
	this->gameOver = new GameOver(this->window);
}







int Game::run()
{

while (this->window->isOpen()) {

	if (this->lifeCount != 0) {
		if (this->mainMenuFlag == false && this->pauseMenuFlag == false && this->selectDifficultyLevelFlag == false) {


			this->obstacleSpawnTime = this->obstacleSpawnClock.getElapsedTime();
			this->lifeTime = this->lifeClock.getElapsedTime();
			this->movementSpeedTime = this->movementSpeedClock.getElapsedTime();
			this->lifeTimeCounter.setString(std::to_string(this->lifeTime_temp + this->lifeTime.asSeconds()));

		}
	
		this->update();
		this->render();
	}

	

	if (this->lifeCount == 0) {

		this->gameOverFlag = true;
		this->render();
		this->updatePollEvents();

	}
	if (this->endWithCodeZero == true) {
		return 0;
	}

	if (this->endWtihCodeOne == true) {
		this->saveGame();
		return 1;
	}
	
}

return 0;

}



void Game::updatePollEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event)) {

		if (event.Event::type == sf::Event::Closed) {
			this->window->close();
			this->endWithCodeZero = true;
		}

		if (this->gameOverFlag == true) {
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->endWtihCodeOne = true;


				}
			}
		}


		if (this->mainMenuFlag == true && this->selectTrackMenuFlag == false && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false) { //select desired position in main menu

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				this->mainMenu->selectUp();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				this->mainMenu->selectDown();
			}
		}


		
		
		if (this->mainMenuFlag == true && this->selectTrackMenuFlag == false && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->mainMenu->selectedIndex == 0) { // wczytanie zapisu
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {

					if (this->isDataLoaded == false) {
						this->loadSavedGame();
					}
					else if (this->isDataLoaded == true) {
						std::cout << "GRA ZOSTALA JUZ WCZYTANA" << std::endl;
					}

					this->mainMenuFlag = true;

					this->lifeClock.restart();
					this->movementSpeedClock.restart();
					this->obstacleSpawnClock.restart();


				}
			}
		}

		
		if (this->mainMenuFlag == true && this->selectTrackMenuFlag == false && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->mainMenu->selectedIndex == 1) { // start gry
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->mainMenuFlag = false;
					this->lifebarFlag = true;
					this->lifeClock.restart();
					this->movementSpeedClock.restart();
					this->obstacleSpawnClock.restart();
				}
			}
		}



		
		if (this->mainMenuFlag == true && this->selectTrackMenuFlag == false && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->mainMenu->selectedIndex == 2) { // wybor auta
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->selectCarMenuFlag = true;
				}
			}
		}


		if (this->selectCarMenuFlag == true) { // nawigowanie w podmenu wyboru auta

			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Up) {
					this->selectCarMenu->selectUp();
				}

				if (event.key.code == sf::Keyboard::Down) {
					this->selectCarMenu->selectDown();
				}


				if (this->selectCarMenu->selectedIndex == 0) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectedCar = this->selectCarMenu->next();
						this->updatePlayer();
					}
				}

				if (this->selectCarMenu->selectedIndex == 1) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectedCar = this->selectCarMenu->previous();
						this->updatePlayer();

					}
				}

				if (this->selectCarMenu->selectedIndex == 2) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectCarMenuFlag = false;
						this->selectCarMenu->reset();
						this->selectCarMenu->selectedIndex = 0;
						std::cout << "selected car: " << this->selectedCar << std::endl;

					}
				}
			}
		}



		if (this->mainMenuFlag == true && this->selectTrackMenuFlag == false && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->mainMenu->selectedIndex == 3) { // wybor toru
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectTrackMenuFlag = true;
					}
				}
			}
		}




		if (this->selectTrackMenuFlag == true) { // nawigowanie w podmenu wyboru toru

			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Up) {
					this->selectTrackMenu->selectUp();
				}

				if (event.key.code == sf::Keyboard::Down) {
					this->selectTrackMenu->selectDown();
				}


				if (this->selectTrackMenu->selectedIndex == 0) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectedTrack = this->selectTrackMenu->next();
						this->updateBackground();
					}
				}

				if (this->selectTrackMenu->selectedIndex == 1) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectedTrack = this->selectTrackMenu->previous();
						this->updateBackground();

					}
				}

				if (this->selectTrackMenu->selectedIndex == 2) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectTrackMenuFlag = false;
						this->selectTrackMenu->reset();
						this->selectTrackMenu->selectedIndex = 0;
						std::cout << "selected track: " << this->selectedTrack << std::endl;

					}
				}
			}
		}




		if (this->mainMenuFlag == true && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->mainMenu->selectedIndex == 4) { // wybor trudnosci
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->selectDifficultyLevelFlag = true;
					
				}
			}
		}


		if (this->selectDifficultyLevelFlag == true) { // select position in difficulty selection menu


			switch (event.type) {
			case sf::Event::KeyReleased:

				if (event.key.code == sf::Keyboard::Up) {
					this->selectDifficultyLevel->selectUp();
				}

				if (event.key.code == sf::Keyboard::Down) {
					this->selectDifficultyLevel->selectDown();
				}

				if (this->selectDifficultyLevel->selectedIndex == 0) {
					if (event.key.code == sf::Keyboard::Left) {
						this->diffLevel = this->selectDifficultyLevel->selectLeft();
					}

					if (event.key.code == sf::Keyboard::Right) {
						this->diffLevel = this->selectDifficultyLevel->selectRight();

					}
				}

				if (this->selectDifficultyLevel->selectedIndex == 1) {
					if (event.key.code == sf::Keyboard::Enter) {
						this->selectDifficultyLevelFlag = false;
						this->selectDifficultyLevel->reset();
						this->selectDifficultyLevel->selectedIndex = 0;
						std::cout << "selected diff level: " << this->diffLevel << std::endl;

					}

				}
			}

		}



		


		if (this->mainMenuFlag == true && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->selectTrackMenuFlag == false && this->mainMenu->selectedIndex == 5) { // informacje o grze i kodzie
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->helpFlag = true;
				}
			}
		}


		









		if (this->mainMenuFlag == false && this->pauseMenuFlag == false) { // turn on/off pause menu and help menu
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape) {
					this->pauseMenuFlag = true;
					if (this->pauseMenuFlag == true) {

						this->pauseGame();


					}
				}

				if (event.key.code == sf::Keyboard::F1) {
					std::cout << "help menu" << std::endl;
					this->helpFlag = true;
					if (this->helpFlag == true) {
						this->pauseGame();
						std::cout << "game paused " << std::endl;
					}

				}




			}
		}



		if (this->helpFlag == true) { // po nacisnieciu enter ekran help zamyka sie 

			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape) {
					this->pauseMenuFlag = false;
					this->helpFlag = false;
					this->resumeGame();
				}
			}
		}




		if (this->pauseMenuFlag == true) { // select position in pause menu

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				this->pauseMenu->selectUp();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				this->pauseMenu->selectDown();
			}
		}


		if (this->pauseMenuFlag == true && this->pauseMenu->selectedIndex == 0) { // resume game in pause menu
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->pauseMenuFlag = false;
					if (this->pauseMenuFlag == false) {

						this->resumeGame();
						
					}
				}
			}
		}


		if (this->pauseMenuFlag == true && this->pauseMenu->selectedIndex == 1) { // zapis gry gdy wybierzemy odpowiednia pozycje z menu pauzy
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->saveGame();
				}
			}
		}

		if (this->pauseMenuFlag == true && this->pauseMenu->selectedIndex == 2) { // zamkniecie gry z menu pauzy
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->window->close();
				}
			}
		}

		

		


	}
}

void Game::updateInput()

{


	if (this->mainMenuFlag == false && this->pauseMenuFlag == false && this->helpFlag == false) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->player->getPos().y >= 5.f) {
			this->player->move(0.f, -0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->player->getPos().y < this->window->getSize().y - this->player->getBounds().height) {
			this->player->move(0.f, 0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->player->getPos().x < this->window->getSize().x - 80.f - this->player->getBounds().width) {
			this->player->move(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->player->getPos().x >= 85.f) {
			this->player->move(-1.f, 0.f);
		}
	}


}

void Game::updateObstacles()
{
	int a;
	if (this->diffLevel == 0) {
		a = 4;
	}
	if (this->diffLevel == 1) {
		a = 3;
	}
	if (this->diffLevel == 2) {
		a = 3;
	}
	if (this->diffLevel == 3) {
		a = 4;
	}



		
		if (this->obstacleSpawnTime.asSeconds() > (static_cast<float>(5 / this->movementSpeed))) { 

			int positionX;

			int speedDifferencePercentage;
			float speed;

			if (this->diffLevel == 0 || this->diffLevel == 1) {
				


				int trackNr = rand() % 3; // randomly picks one of three tracks
				int randomObstacleTexture = rand() % 6; // randomly picks one of six different obstacle textures
				
				 
				int tracksXcoord[3] = { this->window->getSize().x / 6 * 1, this->window->getSize().x / 6 * 3, this->window->getSize().x / 6 * 5 };

				positionX = tracksXcoord[trackNr] - this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)]->getSize().x / 2;

				if (this->diffLevel == 0) {
					this->movementSpeed = 3;
					speed = this->movementSpeed;
				}


				if (this->diffLevel == 1) {
					this->movementSpeed = 3;

					speedDifferencePercentage = rand() % 90 + 10;
					speed = this->movementSpeed + this->movementSpeed * speedDifferencePercentage / 100;

				}



				this->obstacles.push_back(new Obstacle(this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)], positionX, -1.f * (this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)]->getSize().y), 0.f, 1.f, speed));
				//std::cout << "number of obstacles on the screen: " << obstacles.size() << std::endl;
			}


			if (this->diffLevel == 2 || this->diffLevel == 3) {
				
				
				int randomObstacleTexture = rand() % 4; // randomly picks one of six different obstacle textures
				positionX = rand() % static_cast<int>(this->window->getSize().x - this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)]->getSize().x - 160.f) + 80.f;
				float movementSpeedLevel = static_cast<float>(this->lifeTime.asSeconds()) + this->lifeTime_temp;



				if (this->diffLevel == 2) {
					this->movementSpeed = 5 + ((movementSpeedLevel + 5) / 5) - sqrt((movementSpeedLevel + 5) / 5);
					speed = this->movementSpeed;
				}



				if (this->diffLevel == 3) {
					this->movementSpeed = 7 + 2 * ((movementSpeedLevel + 5) / 5) - sqrt((movementSpeedLevel + 5) / 5);

					speedDifferencePercentage = rand() % 40 + 10;
					speed = this->movementSpeed + this->movementSpeed * speedDifferencePercentage / 100;
				}

				
				



				
				if (this->obstacles.size() != 0) { //dont apply this code if theres no obstacles on the screen


					while (abs(positionX - this->obstacles.back()->getBounds().left) < (this->player->getBounds().width + 130 + this->obstacles.back()->getBounds().width)) { // space between obstacles cannot be so small that player doesnt have a chance to go through

						positionX = rand() % static_cast<int>(this->window->getSize().x - this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)]->getSize().x - 160.f) + 80.f;
					}

				}


				this->obstacles.push_back(new Obstacle(this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)], positionX, -1.f * (this->textures["OBSTACLE" + std::to_string(randomObstacleTexture)]->getSize().y), 0.f, 1.f, speed));
				
			}
			
			this->obstacleSpawnClock.restart();

		}


}

void Game::updateObstaclesSpeed()
{
	float movementSpeedLevel = static_cast<float>(this->lifeTime.asSeconds()) + this->lifeTime_temp;
	float tempXSpeed, tempYSpeed;


	if (this->diffLevel == 0) {
		this->movementSpeed = 3; 


	}


	if (this->diffLevel == 1) { 


		if (this->indexes.x != 9999 || this->indexes.y != 9999) {
			tempXSpeed = this->obstacles[this->indexes.x]->getSpeed();
			tempYSpeed = this->obstacles[this->indexes.y]->getSpeed();
			this->obstacles[this->indexes.x]->setMovementSpeed(6.f);
			this->obstacles[this->indexes.y]->setMovementSpeed(5.f);
			this->indexes.x = 9999;
			this->indexes.y = 9999;

		}


	}


	if (this->diffLevel == 2) {
		this->movementSpeed = 5 + ((movementSpeedLevel + 5) / 5) - sqrt((movementSpeedLevel + 5) / 5);

		

	}


	if (this->diffLevel == 3) {

		if (this->indexes.x != 9999 || this->indexes.y != 9999) {

			tempXSpeed = this->obstacles[this->indexes.x]->getSpeed();
			tempYSpeed = this->obstacles[this->indexes.y]->getSpeed();
			this->obstacles[this->indexes.x]->setMovementSpeed(10.f);
			this->obstacles[this->indexes.y]->setMovementSpeed(9.f);
			this->indexes.x = 9999;
			this->indexes.y = 9999;

		}

	}



}

void Game::updateObstalesPosition()
{
	unsigned int i = 0;
	for (auto* obstacle : this->obstacles) {

		obstacle->update();




		
		if (obstacle->getBounds().top > this->window->getSize().y) {

			delete obstacle; 
			this->obstacles.erase(this->obstacles.begin() + i); 
			i--;
		}

		i++;
	}
	this->collisionDetection->update(this->player, this->obstacles);
	this->collisionFor2Obstacles->updateFor2Vectors(this->obstacles, this->obstacles);



}

void Game::updatePlayer()
{
	this->player->update(this->selectedCar);
}

void Game::updateBackground()
{
	this->background.setTexture(*this->textures["TRACK" + std::to_string(this->selectedTrack)]);
	std::cout << "selcted track: " << this->selectedTrack << std::endl;

}

void Game::updateLights()
{

	float posY[2] = { 20.f, 800.f - 20.f - this->textures["OTHER0"]->getSize().x };
	int r = rand() % 2;

	if (this->spawnLightsClock.getElapsedTime().asSeconds() > 4.f) {
		this->lights.push_back(new Obstacle(this->textures["OTHER0"], posY[r], -1.f * (this->textures["OTHER0"]->getSize().y), 0.f, 1.f, 5.f));
		this->spawnLightsClock.restart();
	}

	unsigned int i = 0;
	for (auto* item : this->lights) {

		item->update();




		
		if (item->getBounds().top > this->window->getSize().y) {

			delete item; 
			this->lights.erase(this->lights.begin() + i); 
			i--;
		}

		i++;
	}
}


void Game::resetTime()
{
	this->lifeTime = sf::seconds(0);
	this->obstacleSpawnTime = sf::seconds(0);
	this->movementSpeedTime = sf::seconds(0);
}

void Game::showMenu(sf::RenderWindow* window)
{
	this->mainMenu->drawMenu(window);
}

void Game::showPauseMenu(sf::RenderWindow* window)
{
	this->pauseMenu->drawMenu(window);
}

void Game::showSelectDifficultyLevelMenu(sf::RenderWindow* window)
{
	this->selectDifficultyLevel->drawMenu(window);
}

void Game::showSelectCarMenu(sf::RenderWindow* window)
{
	this->selectCarMenu->drawMenu(window);
}

void Game::showSelectTrackMenu(sf::RenderWindow* window)
{
	this->selectTrackMenu->drawMenu(window);
}

void Game::showLifebar(sf::RenderWindow* window, int lifeCount)
{
	this->lifebar->drawMenu(window, lifeCount);
}

void Game::showHelp(sf::RenderWindow* window)
{
	this->help->drawMenu(window);
}

void Game::showGameOver(sf::RenderWindow* window, float lifeTime_temp, sf::Time lifeTime)
{
	this->gameOver->drawMenu(window, lifeTime_temp, lifeTime);
}



void Game::saveGame()
{

	this->totalScore += this->lifeTime.asSeconds();
	std::ofstream save;
	save.open("save.csv"); 
	if (!save) {
		perror("ERROR: nie mozna otworzyc pliku do zapisu!");
	}

	this->selectedCar;
	this->selectedTrack;
	this->diffLevel;


	if (save) {
		save << "totalScore,lifeTime,movementTime,obstacleSpawnTime,numberOfUnlockedCars,numberOfUnlockedTracks,unlockedDifficultyLevel,selectedCar,selectedTrack,diffLevel" << std::endl;
		save << this->totalScore <<","<< this->lifeTime.asSeconds() <<","<< this->movementSpeedTime.asSeconds() << "," << this->obstacleSpawnTime.asSeconds() <<","
			 << this->numberOfUnlockedCars << "," << this->numberOfUnlockedTracks << "," << this->UnlockedDifficultyLevel << "," << this->selectedCar << "," 
			 << this->selectedTrack << "," << this->diffLevel <<  std::endl;
		save.close();
		std::cout << "Gra zapisana!" << std::endl;
	}

}

void Game::loadSavedGame() 
{



	std::ifstream file;
	file.open("save.csv");
	if (!file) {
		std::cout << "Nie mozna zaladowac save'a!" << std::endl;
	}

	else if (file) {
		std::string line, colname;
		float copy;
		std::getline(file, line); // get first line of file
		std::stringstream ss(line);

		while (std::getline(ss, colname, ',')) { // extract every column from first line 

			// Initialize and add <colname, int vector> pairs to loadedDataFromSave
			this->loadedDataFromSave.push_back({ colname, std::vector<float> {} });
		}


		// Read data, line by line
		while (std::getline(file, line))
		{
			
			std::stringstream ss(line);
			int index = 0;

			while (ss >> copy) {

				this->loadedDataFromSave.at(index).second.push_back(copy);

				if (ss.peek() == ',') ss.ignore(); 

				index++;
			}
		}

		file.close();



		std::cout << "Gra wczytana!" << std::endl;

		for (int i = 0; i <= this->loadedDataFromSave.size() - 1; i++) {
			std::cout << this->loadedDataFromSave[i].first << ":  " << this->loadedDataFromSave[i].second[0] << std::endl;
		}


		this->numberOfUnlockedCars = this->loadedDataFromSave[4].second[0];
		this->numberOfUnlockedTracks = this->loadedDataFromSave[5].second[0];
		this->UnlockedDifficultyLevel = this->loadedDataFromSave[6].second[0];
		this->totalScore = this->loadedDataFromSave[0].second[0];
		this->selectedCar = this->loadedDataFromSave[7].second[0];
		this->selectedTrack = this->loadedDataFromSave[8].second[0];
		this->diffLevel= this->loadedDataFromSave[9].second[0];



	}



	this->isDataLoaded = true;
}



void Game::lookForCollision()
{
	this->indexOfCollidingObstacle = this->collisionDetection->collidingIndex();
	this->collisionBool = this->collisionDetection->collisionBool();

	this->indexes = this->collisionFor2Obstacles->collidingIndexFor2Vectors();
	

	
	

}

void Game::processCollision()
{


	this->lifeCount--;

	if (this->indexOfCollidingObstacle != 9999) {
		
		delete this->obstacles[this->indexOfCollidingObstacle];
		this->obstacles.erase(this->obstacles.begin() + this->indexOfCollidingObstacle);
		this->indexOfCollidingObstacle = 9999;
	}
}



void Game::update()
{
	

	this->updatePollEvents();
	this->updateInput();
	if (this->diffLevel > 1) {
		for (int i = 0; i < this->diffLevel - 1; i++) {
			this->animateBackground();
		}
	}
	else {
		this->animateBackground();
	}
	if (this->lifeCount == 0) {

		this->gameOverFunc();
	}
	
	


	if (this->pauseMenuFlag == false && this->mainMenuFlag == false && this->helpFlag == false) {
		this->updateObstacles();
		this->updateObstaclesSpeed();
		this->updateObstalesPosition();
		this->updateLights();
		this->lookForCollision();
		if (this->collisionBool == true) {
			this->processCollision();
		}


	}


	this->gameProgress();

}

void Game::render()
{
	this->window->clear();

	if (this->mainMenuFlag == true && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->selectTrackMenuFlag == false && this->helpFlag == false && this->gameOverFlag == false) {
		this->showMenu(this->window);
	}

	if (this->mainMenuFlag == true && this->selectDifficultyLevelFlag == true && this->selectCarMenuFlag == false && this->selectTrackMenuFlag == false && this->helpFlag == false && this->gameOverFlag == false) {
		this->showSelectDifficultyLevelMenu(this->window);
	}

	if (this->mainMenuFlag == true && this->selectCarMenuFlag == true && this->selectDifficultyLevelFlag == false && this->selectTrackMenuFlag == false && this->helpFlag == false && this->gameOverFlag == false) {
		this->showSelectCarMenu(this->window);
	}

	if (this->mainMenuFlag == true && this->selectTrackMenuFlag == true && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->helpFlag == false && this->gameOverFlag == false) {
		this->showSelectTrackMenu(this->window);
	}

	if (this->mainMenuFlag == true && this->selectTrackMenuFlag == false && this->selectDifficultyLevelFlag == false && this->selectCarMenuFlag == false && this->helpFlag == true && this->gameOverFlag == false) {
		this->showHelp(this->window);
	}
	else if (this->mainMenuFlag == false && this->pauseMenuFlag == false && this->helpFlag == true && this->gameOverFlag == false) {
		this->showHelp(this->window);
	}


	if (this->mainMenuFlag == false && this->pauseMenuFlag == true && this->helpFlag == false && this->gameOverFlag == false) {
		this->showPauseMenu(this->window);
	}

	if (this->gameOverFlag == true) {
		this->showGameOver(this->window, this->lifeTime_temp, this->lifeTime);

	}


	
	if (this->mainMenuFlag == false && this->pauseMenuFlag == false && this->helpFlag == false && this->gameOverFlag == false) {

		//draw game here
		this->window->draw(this->background);


		this->player->render(*this->window); 

		for (auto* obstacle : this->obstacles) {
			obstacle->render(this->window);
		}

		for (auto* item : this->lights) {
			item->render(this->window);
		}


		this->showLifebar(this->window, this->lifeCount);
		this->window->draw(this->lifeTimeCounter);

	}

	
	this->window->display();
}

void Game::pauseGame()
{
	this->lifeTime_temp += this->lifeTime.asSeconds();
	


	this->obstacleSpawnTime_temp = this->obstacleSpawnTime.asSeconds();
	


	this->movementSpeedTime_temp = this->movementSpeedTime.asSeconds();
	

}

void Game::resumeGame()
{
	this->lifeTime = sf::seconds(0);
	this->lifeClock.restart();
	this->lifeTime = this->lifeClock.getElapsedTime();


	this->obstacleSpawnTime = sf::seconds(0);
	this->obstacleSpawnClock.restart();
	this->obstacleSpawnTime = this->obstacleSpawnClock.getElapsedTime();


	this->movementSpeedTime = sf::seconds(0);
	this->movementSpeedClock.restart();
	this->movementSpeedTime = this->movementSpeedClock.getElapsedTime();

}









void Game::gameProgress() 
{
	float lifeTimeTemp = this->lifeTime.asSeconds();
	float movementSpeedTemp = this->movementSpeedTime.asSeconds();
	float obstacleSpawnTimeTemp = this->obstacleSpawnTime.asSeconds();


	if ((static_cast<int>(lifeTimeTemp)) == 10) {
		if (this->numberOfUnlockedCars < 1) {
			this->numberOfUnlockedCars = 1;
		}
	}


	if ((static_cast<int>(lifeTimeTemp)) == 20) {
		if (this->numberOfUnlockedCars < 2) {
			this->numberOfUnlockedCars = 2;
		}
	}


	if ((static_cast<int>(lifeTimeTemp)) == 30) {
		if (this->numberOfUnlockedCars < 3) {
			this->numberOfUnlockedCars = 3; 
		}
	}

	if (this->totalScore > 20) {
		this->numberOfUnlockedTracks = 1;
	}

	if (this->totalScore > 40) {
		this->numberOfUnlockedTracks = 2;
	}

	if (this->totalScore > 100) {
		this->numberOfUnlockedTracks = 3;
	}


}

void Game::initLoadedVariables()
{
	this->numberOfUnlockedCars = this->loadedDataFromSave[4].second[0];
	std::cout << this->numberOfUnlockedCars<<std::endl;
	this->numberOfUnlockedTracks = this->loadedDataFromSave[5].second[0];
	std::cout << this->numberOfUnlockedTracks << std::endl;
	this->UnlockedDifficultyLevel = this->loadedDataFromSave[6].second[0];
	std::cout << this->UnlockedDifficultyLevel << std::endl;
	this->totalScore = this->loadedDataFromSave[0].second[0];
	std::cout << this->totalScore << std::endl;
}

void Game::animateBackground()
{


	

	if (this->change < 60) { 

		this->background.setPosition(sf::Vector2f(0.f, -300.f + 5.f * this->change));
		this->change++;
	}

	if (this->change == 60) {
		this->change = 0;
	}

	this->animateBackgroundClock.restart();
}


void Game::gameOverFunc()
{
	std::cout << "game over" << std::endl;
}






Game::Game()
{

	srand(time(NULL));

	this->initWindow();
	this->initTextures();
	this->initFonts();
	this->initClocks();
	this->initPlayer(this->window);
	this->initMainMenu();
	this->initPauseMenu();
	this->initSelectDifficultyLevel();
	this->initSelectCarMenu();
	this->initSelectTrackMenu();
	this->initHelp();
	this->initBackground();
	this->initCollisionDetection();
	this->initLifebar();
	this->initGameOver();
	
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	
	for (auto& i : this->textures) {
		delete i.second;
	}

	for (auto* i : this->obstacles) {
		delete i;
	}


}