#pragma once
#include <consolelib.hpp>
#include "Queen.hpp"
#include "Common.hpp"

Queen::Queen(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_QUEEN : Rank::BLACK_QUEEN;
	position = pos;
}

bool Queen::CanMoveToLocation(Position const& pos, int board[BOARD_LENGTH][BOARD_LENGTH])
{
	//TODO
	return true;
}

bool Queen::MoveToLocation(Position const& pos)
{
	//TODO
	return true;
}

void Queen::DrawPiece()
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
	g_Chess.WriteString("    _._     ", posX, posY++, colour);
	g_Chess.WriteString("    ( )     ", posX, posY++, colour);
	g_Chess.WriteString("    / \\    ", posX, posY++, colour);
	g_Chess.WriteString("    | |     ", posX, posY++, colour);
	g_Chess.WriteString("    { }     ", posX, posY++, colour);
	g_Chess.WriteString("   {___}    ", posX, posY++, colour);
}