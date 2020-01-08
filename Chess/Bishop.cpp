#pragma once
#include <consolelib.hpp>
#include <cstdlib>
#include "Bishop.hpp"
#include "Common.hpp"

Bishop::Bishop(bool isWhitePiece, Position const& pos)
{
	rank_ = isWhitePiece ? Rank::WHITE_BISHOP : Rank::BLACK_BISHOP;
	position_ = pos;
}

bool Bishop::CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH])
{
	//check if new position is out of bounds
	if (pos.x > BOARD_LENGTH - 1 || pos.y > BOARD_WIDTH - 1 || pos.x < 0 || pos.y < 0)
		return false;

	//check that the player doesn't already have a piece in the selected location
	if (rank_ > 0)
	{
		if (board[pos.y][pos.x] > 0)
			return false;
	}
	else
	{
		if (board[pos.y][pos.x] < 0)
			return false;
	}
		
	//check that the new position is diagonal from the current position
	int xDifference = abs(position_.x - pos.x);
	int yDifference = abs(position_.y - pos.y);
	if (xDifference == yDifference)
		return true;

	return false;
}

bool Bishop::MoveToLocation(Position const& pos)
{
	position_ = pos;
	return true;
}

void Bishop::DrawPiece(int x, int y)
{
	//colour of piece
	int colour = rank_ > 0 ? WHITE_PIECE_COLOUR : BLACK_PIECE_COLOUR;

	//colour of background
	if (position_.x % 2 == 0)
		if (position_.y % 2 == 0)
			colour |= LIGHT_BOARD_COLOUR;
		else
			colour |= DARK_BOARD_COLOUR;
	else
		if (position_.y % 2 == 0)
			colour |= DARK_BOARD_COLOUR;
		else
			colour |= LIGHT_BOARD_COLOUR;

	int posX = x + (position_.x * SQUARE_LENGTH);
	int posY = y + (position_.y * SQUARE_WIDTH);

	// ASCII art for pieces by Joan G. Stark at https://www.asciiart.eu/sports-and-outdoors/chess
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("     ,      ", posX, posY++, colour);
	g_Chess.WriteString("    (^)     ", posX, posY++, colour);
	g_Chess.WriteString("    / \\     ", posX, posY++, colour);
	g_Chess.WriteString("    { }     ", posX, posY++, colour);
	g_Chess.WriteString("   {___}    ", posX, posY++, colour);
}