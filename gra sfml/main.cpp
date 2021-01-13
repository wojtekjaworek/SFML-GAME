#include "game.h"
#include <iostream>
#include <Windows.h>

int main() {

	Game* game;
	int newGame = 0;

	start:

	game = new Game();
	newGame = game->run();
	game->~Game();

	if (newGame == 1) {
		goto start;
	}

	return 0;
}
