#pragma once
#include <iostream>
class Ship
{
public:
	Ship(int size);
	~Ship();
	static enum class Direction {Top, Down, Left, Right};

	Direction m_currentDirection;
	int m_size;
	int m_rowPosition;
	int m_colPosition;
	bool alive;
};

