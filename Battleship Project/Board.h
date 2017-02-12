#pragma once
#include "Square.h"
class Board
{
public:
	Board();
	~Board();

	
	static const int BOARD_SIZE = 15;

	Square m_board[BOARD_SIZE][BOARD_SIZE];

	
};

