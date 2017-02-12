#pragma once
#include "Ship.h"
#include "Board.h"
#include <time.h>
#include <SFML\Graphics.hpp>
class AiPlayer
{
public:
	AiPlayer();
	~AiPlayer();

	int m_score;
	bool m_myTurn;

	Ship randomSize(int);
	void randomPosition(Ship &);
	void randomDirection(Ship &);
	std::vector<Ship> m_shipContainer;
	sf::Vector2i takeGuess();
	Board m_board;

};

