#pragma once
#include <consolelib.hpp>
#include "Pawn.hpp"
#include "Common.hpp"

Pawn::Pawn(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_PAWN : Rank::BLACK_PAWN;
	position = pos;
}

bool Pawn::CanMoveToLocation(Position const& pos, int board[][8])
{

	return true;
}

bool Pawn::MoveToLocation(Position const& pos)
{

	return true;
}

void Pawn::DrawPiece()
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
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("     ()     ", posX, posY++, colour);
	g_Chess.WriteString("     {}     ", posX, posY++, colour);
	g_Chess.WriteString("    {__}    ", posX, posY++, colour);
}