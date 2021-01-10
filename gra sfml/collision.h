#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "player.h"
#include "obstacle.h"

class Collision
{

private:
	sf::Sprite player;
	std::vector<Obstacle*> obstacles;
	


public:
	Collision(Player* player, std::vector<Obstacle*> obstacles);
	virtual ~Collision();

	int collidingIndex();
	bool collisionBool();
	int index;
	void update(Player* player, std::vector<Obstacle*> obstacles);
};

