#include "game.h"

#include <iostream>
#include <time.h>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>

//private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Redline Racing", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initTextures()
{
	this->textures["OBSTACLE"] = new sf::Texture();
	this->textures["OBSTACLE"]->loadFromFile("textures/test2.png");
}


void Game::initStuff()
{
	this->lifeTimeCounter_font.loadFromFile("fonts/arial.ttf"); // set font for the time counter
	this->lifeTimeCounter.setFont(lifeTimeCounter_font);
}


void Game::initPlayer(sf::RenderWindow *window)
{
	this->player = new Player(this->window);

}

void Game::initMainMenu()
{
	this->mainMenu = new Menu(window);

}

void Game::initPauseMenu()
{
	this->pauseMenu = new PauseMenu(window);
}




//public functions 
void Game::run()
{
while (this->window->isOpen()) {

	if (this->mainMenuFlag == false) {

		this->obstacleSpawnClock.restart();
		this->movementSpeedClock.restart();
		this->lifeClock.restart();

		this->obstacleSpawnTime = this->obstacleSpawnClock.getElapsedTime();
		this->lifeTime = this->lifeClock.getElapsedTime();
		this->movementSpeedTime = this->movementSpeedClock.getElapsedTime();
		this->lifeTimeCounter.setString(std::to_string(this->lifeTime.asSeconds()));

	}
	this->update();
	this->render();
}

}

void Game::updatePollEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event)) {

		if (event.Event::type == sf::Event::Closed) { //close window
			this->window->close();
		}


		if (this->mainMenuFlag == true) { //select desired position in main menu

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				this->mainMenu->selectUp();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				this->mainMenu->selectDown();
			}
		}


		if (this->mainMenuFlag == true && this->mainMenu->selectedIndex == 0) { // start gry
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					this->mainMenuFlag = false;
				}
			}
		}
		
		
		
		
		if (this->mainMenuFlag == true && this->mainMenu->selectedIndex == 1) { // kolejne menu, do dokonczenia
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					/*
					
					
					
					jeszcze nie zrobione,
					tutaj bedzie kolejne menu wyboru
					
					
					
					*/
				}
			}
		}




		if (this->mainMenuFlag == true && this->mainMenu->selectedIndex == 2) { // kolejne menu, do dokonczenia
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					/*



					jeszcze nie zrobione,
					tutaj bedzie kolejne menu wyboru



					*/
				}
			}
		}





		if (this->mainMenuFlag == true && this->mainMenu->selectedIndex == 3) { // informacje o grze i kodzie
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Enter) {
					/*



					informacje o grze i kodzie



					*/
				}
			}
		}









		if (this->mainMenuFlag == false) { // turn on/off pause menu
			switch (event.type) {
			case sf::Event::KeyReleased:
				if (event.key.code == sf::Keyboard::Escape) {
					this->pauseMenuFlag = !this->pauseMenuFlag;
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
					this->pauseMenuFlag = !this->pauseMenuFlag;
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

		if (this->pauseMenuFlag == true && this->pauseMenu->selectedIndex == 2) { // zapis gry gdy wybierzemy odpowiednia pozycje z menu pauzy
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

//TODO: uzale¿niæ prêdkoœci zmiany po³o¿enia (argumenty move) od prêdkoœci z jak¹ przeszkody poruszaj¹ siê,
{


	if (this->mainMenuFlag == false) {
		//move player
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && this->player->getPos().y >= 5.f) {
			this->player->move(0.f, -0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && this->player->getPos().y < this->window->getSize().y - this->player->getBounds().height) {
			this->player->move(0.f, 0.5f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && this->player->getPos().x < this->window->getSize().x - this->player->getBounds().width) {
			this->player->move(1.f, 0.f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && this->player->getPos().x >= 5.f) {
			this->player->move(-1.f, 0.f);
		}
	}


}

void Game::updateObstacles()
{
	//movementSpeed calculation, the longer player plays, the faster obstacles should move

		float movementSpeedLevel = this->movementSpeedTime.asSeconds();

		if (movementSpeedLevel > 10) {
			movementSpeedClock.restart();
			this->movementSpeed += 2;

		}


		//spawning obstacles, the longer player plays, the more obstacles should be spawned, becaulce they move faster and hence disappear faster 


		if (this->obstacleSpawnTime.asSeconds() > (static_cast<float>(4 / this->movementSpeed))) { // spawn obstacle every 3 seconds


			this->obstacleSpawnClock.restart();

			int positionX = rand() % this->window->getSize().x;


			if (this->obstacles.size() != 0) { //dont apply this code if theres no obstacles on the screen


				while (abs(positionX - this->obstacles.back()->getBounds().left) < (this->player->getBounds().width + 130 + this->obstacles.back()->getBounds().width)) { // space between obstacles cannot be so small that player doesnt have a chance to go through

					positionX = rand() % this->window->getSize().x;
				}

			}


			this->obstacles.push_back(new Obstacle(this->textures["OBSTACLE"], positionX, -50.0f, 0.f, 1.f, movementSpeed));
			//std::cout << "number of obstacles on the screen: " << obstacles.size() << std::endl;

		}

		for (auto* obstacle : this->obstacles) {
			obstacle->setMovementSpeed(movementSpeed);

		}






		unsigned int i = 0;
		for (auto* obstacle : this->obstacles) {
			obstacle->update();


			//delete obstacle when comes to the edge of the window
			if (obstacle->getBounds().top > this->window->getSize().y) {

				delete obstacle; //free memory
				this->obstacles.erase(this->obstacles.begin() + i); // delete from vector tracking total number of obstacles
				i--;
			}

			i++;
		}

}

void Game::showMenu(sf::RenderWindow* window)
{
	this->mainMenu->drawMenu(window);
}

void Game::showPauseMenu(sf::RenderWindow* window)
{
	this->pauseMenu->drawMenu(window);
}

void Game::saveGame()
{
	std::ofstream save;
	save.open("save.csv"); // saving to csv, first line contain names, second line contain values
	if (!save) {
		perror("ERROR: nie mozna otworzyc pliku do zapisu!");
	}

	if (save) {
		save << "score,unlockedCarID,unlockedTrackID" << std::endl;
		save << this->lifeTime.asMilliseconds() << "," << 0 << "," << 0 << std::endl;// zapisany przykladowy jeden parametr
		save.close();
	}

}

void Game::loadSavedGame() // NIEDOKOÑCZONA FUNKCJA
{
	std::ifstream file;
	file.open("save.csv");
	if (!file) {
		perror("ERROR: nie mozna zaladowac sejwa");
	}

	if (file) {
		std::string line, colname;
		int copy;
		std::getline(file, line); // get first line of file
		std::stringstream ss(line);

		while (std::getline(ss, colname, ',')) { // extract every column from first line 

			// Initialize and add <colname, int vector> pairs to loadedDataFromSave
			this->loadedDataFromSave.push_back({ colname, std::vector<int> {} });
		}


		// Read data, line by line
		while (std::getline(file, line))
		{
			
			std::stringstream ss(line);
			int index = 0;

			while (ss >> copy) {

				this->loadedDataFromSave.at(index).second.push_back(copy);

				if (ss.peek() == ',') ss.ignore(); // skip when comma

				index++;
			}
		}

		file.close();


	}


}

void Game::update()
{
	
	this->updatePollEvents();
	this->updateInput();
	this->updateObstacles();
	
}

void Game::render()
{
	this->window->clear();

	if (this->mainMenuFlag == true) {
		this->showMenu(window);
	}


	if (this->mainMenuFlag == false && this->pauseMenuFlag == true) {
		this->showPauseMenu(window);
	}

	if (this->mainMenuFlag == false && this->pauseMenuFlag == false) {

		//draw game here
		this->player->render(*this->window); // decide where te render player,in this case: on the window (which is a pointer so * )

		for (auto* obstacle : this->obstacles) {
			obstacle->render(this->window);
		}


		//draw lifetime counter in the right top corner
		this->window->draw(this->lifeTimeCounter);

	}

	//display everything 
	this->window->display();
}


//constructor &destructor
Game::Game()
{

	srand(time(NULL));

	this->initWindow();
	this->initTextures();
	this->initStuff();
	this->initPlayer(this->window);
	this->initMainMenu();
	this->initPauseMenu();
	
}

Game::~Game()
{
	delete this->window;
	delete this->player;
	
	// for loop to delete all the loaded textures and prevent memory leaks 
	for (auto& i : this->textures) {
		delete i.second;
	}

	//delete all the obstacles
	for (auto* i : this->obstacles) {
		delete i;
	}
}