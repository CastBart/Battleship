#ifndef  GAME
#define GAME
#include "SFML\Graphics.hpp"
#include <Player.h>
#include <Board.h>
#include <AiPlayer.h>
#include <iostream>


class Game
{
public:
	Game(sf::ContextSettings settings);
	~Game();

	void run();
	
private:
	void update(sf::Time const &);
	void render();
	void proccessEvents();

	void giveTurn(bool & turn);
	void printRules();
	void displayShotResult(std::string result);
	Player inputName(std::string name);
	void processShot(Player&, AiPlayer&, sf::Vector2i&);
	void processShot(AiPlayer&, Player&, sf::Vector2i&);
	void checkWinner(AiPlayer&, Player&);
	void displayWinner();
	void displayWinnerScore();

	/* frames per second used fro updating the game */
	sf::Time const FRAMES_PER_SECOND = sf::seconds(1.0f / 60.0f);

	/* Render Window used to draw to screen */
	sf::RenderWindow m_window;
	
	/* clock used for rendering times */
	sf::Clock m_clock;

	/* time for tracking time in between updates */
	sf::Time m_elapsedTime;

};
#endif // ! GAME
