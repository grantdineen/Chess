#pragma once
#include <vector>
#include "Piece.hpp"
#include "Common.hpp"

class Board
{
public:
	std::vector<Piece*> pieces;
	int board[BOARD_WIDTH][BOARD_LENGTH];

	~Board();

	void InitBoard();
};