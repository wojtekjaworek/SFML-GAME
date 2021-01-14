#include "game.h"
#include <iostream>
#include <Windows.h>

int main() {

	start:

	Game* game;
	int newGame = 0;

	game = new Game();
	newGame = game->run();
	delete game;


	if (newGame == 1) {
		goto start;
	}

	return 0;
}
