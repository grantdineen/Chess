#pragma once
#include <consolelib.hpp>
#include "Queen.hpp"
#include "Common.hpp"

Queen::Queen(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_QUEEN : Rank::BLACK_QUEEN;
	position = pos;
}

bool Queen::CanMoveToLocation(Position const& pos, int board[][8])
{

	return true;
}

bool Queen::MoveToLocation(Position const& pos)
{

	return true;
}

void Queen::DrawPiece()
{
	//colour of piece
	int colour = rank > 0 ? Colours::F_GREEN : Colours::F_RED;

	//colour of background
	if (position.x % 2 == 0)
		if (position.y % 2 == 0)
			colour |= Colours::B_WHITE;
		else
			colour |= Colours::B_BLACK;
	else
		if (position.y % 2 == 0)
			colour |= Colours::B_BLACK;
		else
			colour |= Colours::B_WHITE;

	int posX = position.x * 12;
	int posY = position.y * 6;

	// ASCII art for pieces by Joan G. Stark at https://www.asciiart.eu/sports-and-outdoors/chess
	g_Chess.WriteString("    _._     ", posX, posY++, colour);
	g_Chess.WriteString("    ( )     ", posX, posY++, colour);
	g_Chess.WriteString("    / \\    ", posX, posY++, colour);
	g_Chess.WriteString("    | |     ", posX, posY++, colour);
	g_Chess.WriteString("    { }     ", posX, posY++, colour);
	g_Chess.WriteString("   {___}    ", posX, posY++, colour);
}