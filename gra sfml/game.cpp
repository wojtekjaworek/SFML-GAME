#include "game.h"

#include <iostream>
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




//public functions 
void Game::run()
{
while (this->window->isOpen()) {
	this->obstacleSpawnTime = this->obstacleSpawnClock.getElapsedTime();
	this->lifeTime = this->lifeClock.getElapsedTime();
	this->lifeTimeCounter.setString(std::to_string(this->lifeTime.asSeconds()));
	this->update();
	this->render();
}

}

void Game::updatePollEvents()
{
	sf::Event event;
	while (this->window->pollEvent(event)) {
		if (event.Event::type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void Game::updateInput()
{
	//move player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->player->move(0.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->player->move(0.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->player->move(1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->player->move(-1.f, 0.f);
	}


	if (this->obstacleSpawnTime.asSeconds() > (static_cast<float>(3))) { // spawn obstacle every 3 seconds

		this->obstacleSpawnClock.restart();
		this->obstacles.push_back(new Obstacle(this->textures["OBSTACLE"], 0.f, 0.f, 0.f, 1.f, 2.f));
		std::cout << "number of rendered obstacles <total>: " << obstacles.size() << std::endl;
	}


}

void Game::updateObstacles()
{

	for (auto* obstacle : this->obstacles) {
		obstacle->update();
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


	//draw game here
	this->player->render(*this->window); // decide where te render player,in this case: on the window (which is a pointer so * )

	for (auto* obstacle : this->obstacles) {
		obstacle->render(this->window);
	}


	//draw lifetime counter in the right top corner
	this->window->draw(this->lifeTimeCounter);



	//display everything 
	this->window->display();
}


//constructor &destructor
Game::Game()
{
	this->initWindow();
	this->initTextures();
	this->initStuff();
	this->initPlayer(this->window);
	
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