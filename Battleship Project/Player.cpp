#include <iostream>
#include "Player.h"



Player::Player(std::string name) :
	m_score(0),
	m_name(name)
{
	std::cout << "Player instance Created" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Input Ship Size" << std::endl;
		int tempSize;
		std::cin >> tempSize;
		m_shipContainer.push_back(inputShipSize(tempSize));

		inputShipPosition(m_shipContainer.at(i));

		inputShipDirection(m_shipContainer.at(i));

		
	}
}


Player::~Player()
{
}

Ship Player::inputShipSize(int shipSize)
{
	return Ship(shipSize);
}

void Player::inputShipPosition(Ship & ship)
{
	std::cout << "Input Ship Row Position, MAX 15" << std::endl;
	
	std::cin >> ship.m_rowPosition;
	std::cout << "Input Ship Column Position, MAX 15" << std::endl;
	std::cin >> ship.m_colPosition;
}

void Player::inputShipDirection(Ship & ship)
{
	std::cout << "Sellect the Direction of your Ship" << std::endl;
	std::cout << "1 = TOP .... 2 = DOWN .... 3 = LEFT .... 4 = RIGHT" << std::endl;
	int direction;
	std::cin >> direction;

	switch (direction)
	{
	case 1:
		ship.m_currentDirection = Ship::Direction::Top;
	
		for (int i = 0; i < ship.m_size; i++)
		{
			m_board.m_board[ship.m_rowPosition + i][ship.m_colPosition].m_containsShip = true;
		}
		break;
	case 2:
		ship.m_currentDirection = Ship::Direction::Down;
		for (int i = 0; i < ship.m_size; i++)
		{
			m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
		}
		break;
	case 3:
		ship.m_currentDirection = Ship::Direction::Left;
		for (int i = 0; i < ship.m_size; i++)
		{
			m_board.m_board[ship.m_rowPosition][ship.m_colPosition + i].m_containsShip = true;
		}
		break;
	case 4:
		ship.m_currentDirection = Ship::Direction::Right;
		for (int i = 0; i < ship.m_size; i++)
		{
			m_board.m_board[ship.m_rowPosition][ship.m_colPosition - i].m_containsShip = true;
		}
		break;
	default:
		ship.m_currentDirection = Ship::Direction::Top;
		break;
	}
	
}



sf::Vector2i Player::takeGuess()
{
	int x;
	std::cout << "Take a guess for your Row coordinate" << std::endl;
	std::cin >> x;
	int y;
	std::cout << "Take a guess for your Column coordinate" << std::endl;
	std::cin >> y;
	return sf::Vector2i(x, y);
}



