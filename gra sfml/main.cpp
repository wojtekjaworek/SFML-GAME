#include "game.h"
#include <iostream>

int main() {

	Game* game;
	int newGame = 0;

	start:

	game = new Game();
	newGame = game->run();

	if (newGame == 1) {
		goto start;
	}

	
	return 0;
}
