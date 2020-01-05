#pragma once
#include <consolelib.hpp>
#include "Bishop.hpp"
#include "Common.hpp"

Bishop::Bishop(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_BISHOP : Rank::BLACK_BISHOP;
	position = pos;
}

bool Bishop::CanMoveToLocation(Position const& pos, int board[][8])
{

	return true;
}

bool Bishop::MoveToLocation(Position const& pos)
{

	return true;
}

void Bishop::DrawPiece()
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

	int posX = position.x * 12;
	int posY = position.y * 6;

	// ASCII art for pieces by Joan G. Stark at https://www.asciiart.eu/sports-and-outdoors/chess
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("     ,      ", posX, posY++, colour);
	g_Chess.WriteString("    (^)     ", posX, posY++, colour);
	g_Chess.WriteString("    / \\     ", posX, posY++, colour);
	g_Chess.WriteString("    { }     ", posX, posY++, colour);
	g_Chess.WriteString("   {___}    ", posX, posY++, colour);
}