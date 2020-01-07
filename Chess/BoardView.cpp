#include <consolelib.hpp>
#include "BoardView.hpp"
#include "Common.hpp"

BoardView::BoardView(Board& b, int x, int y) : board_(b)
{
	posX_ = x;
	posY_ = y;
}

void BoardView::DrawBoard()
{
	//x + y coords to draw location
	int x = posX_;
	int y = posY_;
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_LENGTH; j++)
		{
			int colour;
			if (i % 2 == 0)
				if (j % 2 == 0)
					colour = LIGHT_BOARD_COLOUR;
				else
					colour = DARK_BOARD_COLOUR;
			else
				if (j % 2 == 0)
					colour = DARK_BOARD_COLOUR;
				else
					colour = LIGHT_BOARD_COLOUR;

			x = posX_ + (j * SQUARE_LENGTH);
			y = posY_ + (i * SQUARE_WIDTH);
			g_Chess.WriteString("            ", x, y++, colour);
			g_Chess.WriteString("            ", x, y++, colour);
			g_Chess.WriteString("            ", x, y++, colour);
			g_Chess.WriteString("            ", x, y++, colour);
			g_Chess.WriteString("            ", x, y++, colour);
			g_Chess.WriteString("            ", x, y++, colour);
		}
		x = posX_;
		y++;
	}
}

void BoardView::DrawPieces()
{
	for (Piece* piece : board_.pieces)
		piece->DrawPiece(posX_, posY_);
}

void BoardView::update(Event e)
{
	DrawBoard();
	DrawPieces();
}