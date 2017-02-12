#include "AiPlayer.h"



AiPlayer::AiPlayer()
{
	srand(time(NULL));
	std::cout << "Ai Player instance Created" << std::endl;
	for (int i = 0; i < 6; i++)
	{
		std::cout << "Input Ship Size" << std::endl;
		int tempSize;
		tempSize = rand() % 6 + 1;
		m_shipContainer.push_back(randomSize(tempSize));

		randomPosition(m_shipContainer.at(i));

		randomDirection(m_shipContainer.at(i));


	}
}


AiPlayer::~AiPlayer()
{
}

Ship AiPlayer::randomSize(int size)
{
	return Ship(size);
}

void AiPlayer::randomPosition(Ship & ship)
{
	int randomRow;
	int randomCol;

	randomRow = rand() % 15 + 1;

	ship.m_rowPosition = randomRow;
	randomCol = rand() % 15 + 1;
    ship.m_colPosition = randomCol;
}

void AiPlayer::randomDirection(Ship & ship)
{
	int direction;
	//check if ship spwned in bottom right corner
	if (ship.m_colPosition + ship.m_size > 15 && ship.m_rowPosition + ship.m_size > 15)
	{
		direction = rand() % 2 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Right;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition - i].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Down;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Right;
			break;
		}
	}
	//check if ship spawned in the top left corner
	else if (ship.m_colPosition - ship.m_size < 0 && ship.m_rowPosition - ship.m_size < 0)
	{
		direction = rand() % 2 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Left;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition + i].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Top;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition + i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Left;
			break;
		}
	}
	//check if the ship spawned in the bottom left
	else if (ship.m_colPosition - ship.m_size < 0 && ship.m_rowPosition + ship.m_size > 15)
	{
		direction = rand() % 2 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Left;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition + i].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Down;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Left;
			break;
		}
	}
	//check is ship spawned in the top right
	else if (ship.m_colPosition + ship.m_size > 15 && ship.m_rowPosition - ship.m_size < 0)
	{
		direction = rand() % 2 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Right;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition - i].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Top;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition + i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Right;
			break;
		}
	}


	else if (ship.m_rowPosition + ship.m_size > 15)
	{
		direction = rand() % 3 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Down;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Left;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition + i].m_containsShip = true;
			}
			break;
		case 3:
			ship.m_currentDirection = Ship::Direction::Right;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition - i].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Down;
			break;
		}
	}



	else if (ship.m_rowPosition - ship.m_size > 0)
	{
		direction = rand() % 3 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Top;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Left;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition + i].m_containsShip = true;
			}
			break;
		case 3:
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

	else if (ship.m_colPosition - ship.m_size > 0)
	{
		direction = rand() % 3 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Top;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Left;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition + i].m_containsShip = true;
			}
			break;
		case 3:
			ship.m_currentDirection = Ship::Direction::Down;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition + i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Left;
			break;
		}
	}

	else if (ship.m_colPosition + ship.m_size > 0)
	{
		direction = rand() % 3 + 1;
		switch (direction)
		{
		case 1:
			ship.m_currentDirection = Ship::Direction::Top;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		case 2:
			ship.m_currentDirection = Ship::Direction::Right;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition][ship.m_colPosition - i].m_containsShip = true;
			}
			break;
		case 3:
			ship.m_currentDirection = Ship::Direction::Down;
			for (int i = 0; i < ship.m_size; i++)
			{
				m_board.m_board[ship.m_rowPosition - i][ship.m_colPosition].m_containsShip = true;
			}
			break;
		default:
			ship.m_currentDirection = Ship::Direction::Right;
			break;
		}
	}

}

sf::Vector2i AiPlayer::takeGuess()
{
	int row;
	int col;
	
	row = rand() % 15 + 1;
	col = rand() % 15 + 1;
	return sf::Vector2i(row, col);
}




