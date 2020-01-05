#pragma once

#include <View.hpp>
#include <Event.hpp>
#include "Board.hpp"
#include "Piece.hpp"

class BoardView : public View
{
private:
	Board& board;

public:
	BoardView(Board& b, int x, int y);

	void DrawBoard();
	void DrawPieces();
	void update(Event e);
};