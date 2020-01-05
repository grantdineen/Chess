#pragma once
#include <consolelib.hpp>
#include "Knight.hpp"
#include "Common.hpp"

Knight::Knight(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_KNIGHT : Rank::BLACK_KNIGHT;
	position = pos;
}

bool Knight::CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH])
{
	//TODO
	return true;
}

bool Knight::MoveToLocation(Position const& pos)
{
	//TODO
	return true;
}

void Knight::DrawPiece()
{
	//colour of piece
	int colour = rank > 0 ? WHITE_PIECE_COLOUR : BLACK_PIECE_COLOUR;

	//colour of background
	if (position.x % 2 == 0)
		if (position.y % 2 == 0)
			colour |= LIGHT_BOARD_COLOUR;
		else
			colour |= DARK_BOARD_COLOUR;
	else
		if (position.y % 2 == 0)
			colour |= DARK_BOARD_COLOUR;
		else
			colour |= LIGHT_BOARD_COLOUR;

	int posX = position.x * SQUARE_LENGTH;
	int posY = position.y * SQUARE_WIDTH;

	// ASCII art for pieces by Joan G. Stark at https://www.asciiart.eu/sports-and-outdoors/chess
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("    _,,     ", posX, posY++, colour);
	g_Chess.WriteString("  \"-=\\~   ", posX, posY++, colour);
	g_Chess.WriteString("     )(     ", posX, posY++, colour);
	g_Chess.WriteString("    /__\\   ", posX, posY++, colour);
}