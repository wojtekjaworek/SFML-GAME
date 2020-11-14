#include "game.h"

//constructor & destructors 
game::game() {

	this->initVariables();
	this->initWindow();
	this->initObstacles();


}

game::~game() {

	delete this->window; // prevent memory leaks

}

//functions from game.h


//public functions from game.h


void game::getEvents() {

	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type) {
		case sf::Event::Closed :


			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape) {
				this->window->close();
				break;
			}
		}
	}
}


void game::update() {

	this->getEvents();

}

void game::render() {

	//clear existing frame
	this->window->clear();


	//draw game





	this->window->draw(this->obstacles);
	this->window->display();
	

}


//accessors from game.h
const bool game::checkIfWindowIsOpen() const
{
	return this->window->isOpen();
}


//private functions from game.h
void game::initVariables() {

	this->window == nullptr;
	this->obstacleTexture.loadFromFile("test.jpg"); 

}

void game::initWindow() {


	this->VMode.height = 480;
	this-> VMode.width = 640;
	this->window = new sf::RenderWindow(this->VMode, "Redline Racing", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void game::initObstacles() {

	this->obstacles.setTexture(this->obstacleTexture);
	this->obstacles.setPosition(100.f,100.f);


}
