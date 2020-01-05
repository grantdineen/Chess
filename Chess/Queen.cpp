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

	//check that queen has moved up/down, left/right or diagonal
	int xDifference = abs(position.x - pos.x);
	int yDifference = abs(position.y - pos.y);
	if ((xDifference > 0 && yDifference == 0) || (yDifference > 0 && xDifference == 0) || (xDifference == yDifference))
		return true;

	return false;
}

bool Queen::MoveToLocation(Position const& pos)
{
	position = pos;
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