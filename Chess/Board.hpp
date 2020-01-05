#pragma once
#include <vector>
#include "Piece.hpp"

class Board
{
private:
	static const int BOARD_WIDTH = 8;
	static const int BOARD_HEIGHT = 8;
public:
	std::vector<Piece*> pieces;
	int board[BOARD_HEIGHT][BOARD_WIDTH];

	~Board();

	void InitBoard();
};