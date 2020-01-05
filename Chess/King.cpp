#pragma once
#include <consolelib.hpp>
#include <cstdlib>
#include "King.hpp"
#include "Common.hpp"

King::King(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_KING : Rank::BLACK_KING;
	position = pos;
}

bool King::CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH])
{
	//check if new position is out of bounds
	if (pos.x > BOARD_LENGTH - 1 || pos.y > BOARD_WIDTH - 1 || pos.x < 0 || pos.y < 0)
		return false;

	//check that the player doesn't already have a piece in the selected location
	if (rank > 0)
	{
		if (board[pos.x][pos.y] > 0)
			return false;
	}
	else
	{
		if (board[pos.x][pos.y] < 0)
			return false;
	}

	//check that the king is only moving one block away from current position
	int xDifference = abs(position.x - pos.x);
	int yDifference = abs(position.y = pos.y);
	if (xDifference > 1 || yDifference > 1)
		return true;

	//TODO
	//Castling ?

	return false;
}

bool King::MoveToLocation(Position const& pos)
{
	position = pos;
	return true;
}

void King::DrawPiece()
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
	g_Chess.WriteString("     +      ", posX, posY++, colour);
	g_Chess.WriteString("    ( )     ", posX, posY++, colour);
	g_Chess.WriteString("    / \\    ", posX, posY++, colour);
	g_Chess.WriteString("    | |     ", posX, posY++, colour);
	g_Chess.WriteString("    { }     ", posX, posY++, colour);
	g_Chess.WriteString("   {___}    ", posX, posY++, colour);
}