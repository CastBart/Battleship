#pragma once
#include "Ship.h"
#include "Board.h"
#include "SFML\Graphics.hpp"
class Player
{
public:
	Player(std::string name);
	~Player();

	

	Ship inputShipSize(int shpSize);
	void inputShipPosition(Ship &);
	void inputShipDirection(Ship &);

	sf::Vector2i takeGuess();

	int m_score;
	std::string m_name;
	bool m_myTurn;
	std::vector<Ship> m_shipContainer;
	Board m_board;
};

