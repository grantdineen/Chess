#pragma once

#include <View.hpp>
#include <Event.hpp>
#include "Board.hpp"
#include "Piece.hpp"

class BoardView : public View
{
private:
	Board& board_;
	int boardPosX_;
	int boardPosY_;
	const int BOARD_BORDER_X = 2;
	const int BOARD_BORDER_Y = 2;

public:
	BoardView(Board& b, int x, int y);

	void DrawBoard();
	void DrawPieces();
	void DrawBorder();
	void update(Event e);
};