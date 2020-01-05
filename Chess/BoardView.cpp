#include <consolelib.hpp>
#include "BoardView.hpp"
#include "Common.hpp"

BoardView::BoardView(Board& b, int x, int y) : board(b)
{
	posX_ = x;
	posY_ = y;
}

void BoardView::DrawBoard()
{
	//x + y coords to draw location
	int x = posX_;
	int y = posY_;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int colour;
			if (i % 2 == 0)
				if (j % 2 == 0)
					colour = Colours::B_WHITE;
				else
					colour = Colours::B_BLACK;
			else
				if (j % 2 == 0)
					colour = Colours::B_BLACK;
				else
					colour = Colours::B_WHITE;

			x = posX_ + (j * 12);
			y = posY_ + (i * 6);
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
	for (Piece* piece : board.pieces)
		piece->DrawPiece();
}

void BoardView::update(Event e)
{

}