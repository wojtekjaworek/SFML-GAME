#include "collision.h"
#include <iostream>

Collision::Collision(Player* player, std::vector<Obstacle*> obstacles)
{
	this->player = player->getSprite();
	this->obstacles = obstacles;
	

}

Collision::~Collision()
{
}

int Collision::collidingIndex()
{
	if (this->obstacles.size() > 0) {
		for (int i = 0; i < this->obstacles.size(); i++) {
			if (this->player.getGlobalBounds().intersects(this->obstacles[i]->getBounds())) {
				return i;
			}
			if ((i == this->obstacles.size() - 1) && (!this->player.getGlobalBounds().intersects(this->obstacles[i]->getBounds()))) {
				return 9999;
			}
		}
	}
	else {
		return 9999;
	}
	
}

void Collision::update(Player* player, std::vector<Obstacle*> obstacles)
{
	this->player = player->getSprite();
	this->obstacles = obstacles;
}
