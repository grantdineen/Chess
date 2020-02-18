#include <consolelib.hpp>
#include "BoardView.hpp"
#include "Common.hpp"

BoardView::BoardView(Board& b, int x, int y) : board_(b)
{
	posX_ = x;
	posY_ = y;
	boardPosX_ = x + BOARD_BORDER_X;
	boardPosY_ = y + BOARD_BORDER_Y;
	endX_ = posX_ + SQUARE_LENGTH * 8 + BOARD_BORDER_X * 2;
	endY_ = posY_ + SQUARE_WIDTH * 8 + BOARD_BORDER_Y * 2;
}

void BoardView::DrawBoard()
{
	//x + y coords to draw location
	int x = boardPosX_;
	int y = boardPosY_;
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

			x = boardPosX_ + (j * SQUARE_LENGTH);
			y = boardPosY_ + (i * SQUARE_WIDTH);

			for(int z = 0; z < 6; z++)
				g_Chess.WriteString("            ", x, y++, colour);
		}
		x = boardPosX_;
		y++;
	}
}

void BoardView::DrawPieces()
{
	for (Piece* piece : board_.pieces)
		piece->DrawPiece(boardPosX_, boardPosY_);
}

void BoardView::DrawBorder()
{
	for (int i = 0; i < 8; i++)
	{
		g_Chess.WriteString(std::string(1, 'A' + i), ((posX_ + i) * SQUARE_LENGTH) + (SQUARE_LENGTH / 2), posY_);
		g_Chess.WriteString(std::string(1, 'A' + i), ((posX_ + i) * SQUARE_LENGTH) + (SQUARE_LENGTH / 2), endY_ - 1);

		g_Chess.WriteString(std::to_string(8 - i), posX_, ((posY_ + i) * SQUARE_WIDTH) + (SQUARE_WIDTH / 2));
		g_Chess.WriteString(std::to_string(8 - i), endX_ - 1, ((posY_ + i) * SQUARE_WIDTH) + (SQUARE_WIDTH / 2));
	}
}

void BoardView::update(Event e)
{
	DrawBoard();
	DrawPieces();
}