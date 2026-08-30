#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../game/game.hpp"
int main() {

	
	srand(time(nullptr));

	Game game;
	game.run();

#ifndef DEBUG
	system("pause");
#endif

	return 0;
}