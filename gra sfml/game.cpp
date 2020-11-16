#include "game.h"


//private functions
void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800,600), "Redline Racing", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(60);
	this->window->setVerticalSyncEnabled(false);

}

void Game::initPlayer()
{
	this->player = new Player();
}


//public functions 
void Game::run()
{
while (this->window->isOpen()) {
	this->update();
	this->render();
}

}

void Game::update()
{
	sf::Event event;
	while (this->window->pollEvent(event)) {
		if (event.Event::type == sf::Event::Closed) {
			this->window->close();
		}
	}

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
}

void Game::render()
{
	this->window->clear();


	//draw game here
	this->player->render(*this->window); // decide where te render player,in this case: on the window (which is a pointer so * )

	this->window->display();
}


//constructor &destructor
Game::Game()
{
	this->initWindow();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}