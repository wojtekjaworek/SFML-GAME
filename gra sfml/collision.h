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
	std::vector<Obstacle*> obstacles1;
	std::vector<Obstacle*> obstacles2;
	sf::Vector2i indexes;
	


public:
	Collision(Player* player, std::vector<Obstacle*> obstacles);
	Collision(std::vector<Obstacle*> obstacles1, std::vector<Obstacle*> obstacles2);
	virtual ~Collision();

	int collidingIndex();
	sf::Vector2i collidingIndexFor2Vectors();
	bool collisionBoolFor2Vectors();
	bool collisionBool();
	int index;
	void update(Player* player, std::vector<Obstacle*> obstacles);
	void updateFor2Vectors(std::vector<Obstacle*> obstacles1, std::vector<Obstacle*> obstacles2);

};

