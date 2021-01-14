#include "collision.h"
#include <iostream>

Collision::Collision(Player* player, std::vector<Obstacle*> obstacles)
{
	this->player = player->getSprite();
	this->obstacles = obstacles;
	

}

Collision::Collision(std::vector<Obstacle*> obstacles1, std::vector<Obstacle*> obstacles2)
{
	this->obstacles1 = obstacles1;
	this->obstacles2 = obstacles2;

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

sf::Vector2i Collision::collidingIndexFor2Vectors()
{
	if (this->obstacles1.size() > 1 && this->obstacles2.size() > 1) {
		for (int i = 0; i < this->obstacles1.size(); i++) {
			for (int j = 0;j < obstacles2.size(); j++) {
				if (i != j) {
					if (this->obstacles1[i]->getBounds().intersects(this->obstacles2[j]->getBounds())) {
						this->indexes.x = i;
						this->indexes.y = j;

						return indexes;
					}

					if ((i == this->obstacles1.size() - 1) && (!this->obstacles1[i]->getBounds().intersects(this->obstacles2[j]->getBounds()))) {
						this->indexes.x = 9999;
						this->indexes.y = 9999;

						return indexes;
					}
				}
			}
		}
	}
	else {
		this->indexes.x = 9999;
		this->indexes.y = 9999;
		return indexes;
	}
}

bool Collision::collisionBoolFor2Vectors()
{
	if (this->obstacles1.size() > 1 && this->obstacles2.size() > 1) {
		for (int i = 0; i < this->obstacles1.size(); i++) {
			for (int j = 0;j < obstacles2.size(); j++) {
				if (i != j) {
					if (this->obstacles1[i]->getBounds().intersects(this->obstacles2[j]->getBounds())) {
						return true;
					}

					if ((i == this->obstacles1.size() - 1) && (!this->obstacles1[i]->getBounds().intersects(this->obstacles2[j]->getBounds()))) {
						return false;
					}
				}
			}
		}
	}
	else {
		return false;
	}
}

bool Collision::collisionBool()
{
	if (this->obstacles.size() > 0) {
		for (int i = 0; i < this->obstacles.size(); i++) {
			if (this->player.getGlobalBounds().intersects(this->obstacles[i]->getBounds())) {
				return true;
			}
			if ((i == this->obstacles.size() - 1) && (!this->player.getGlobalBounds().intersects(this->obstacles[i]->getBounds()))) {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

void Collision::update(Player* player, std::vector<Obstacle*> obstacles)
{
	this->player = player->getSprite();
	this->obstacles = obstacles;
}

void Collision::updateFor2Vectors(std::vector<Obstacle*> obstacles1, std::vector<Obstacle*> obstacles2)
{
	this->obstacles1 = obstacles1;
	this->obstacles2 = obstacles2;
}
