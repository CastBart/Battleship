#include <iostream>
#include "Game.h"


int main()
{
	sf::ContextSettings settings;
	settings.depthBits = 24u;
	settings.antialiasingLevel = 4u;
	Game& game = Game(settings);
	game.run();


	system("pause");
}