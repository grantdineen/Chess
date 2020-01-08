#pragma once
#include <consolelib.hpp>
#include "Queen.hpp"
#include "Common.hpp"

Queen::Queen(bool isWhitePiece, Position const& pos)
{
	rank_ = isWhitePiece ? Rank::WHITE_QUEEN : Rank::BLACK_QUEEN;
	position_ = pos;
}

bool Queen::CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH])
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

	//check that queen has moved up/down, left/right or diagonal
	int xDifference = abs(position_.x - pos.x);
	int yDifference = abs(position_.y - pos.y);
	if ((xDifference > 0 && yDifference == 0) || (yDifference > 0 && xDifference == 0) || (xDifference == yDifference))
		return true;

	return false;
}

bool Queen::MoveToLocation(Position const& pos)
{
	position_ = pos;
	return true;
}

void Queen::DrawPiece(int x, int y)
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
	g_Chess.WriteString("    _._     ", posX, posY++, colour);
	g_Chess.WriteString("    ( )     ", posX, posY++, colour);
	g_Chess.WriteString("    / \\    ", posX, posY++, colour);
	g_Chess.WriteString("    | |     ", posX, posY++, colour);
	g_Chess.WriteString("    { }     ", posX, posY++, colour);
	g_Chess.WriteString("   {___}    ", posX, posY++, colour);
}

std::string Queen::ToString() const
{
	return rank_ > 0 ? "White Queen" : "Black Queen";
}