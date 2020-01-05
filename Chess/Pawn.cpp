#pragma once
#include <consolelib.hpp>
#include <cstdlib>
#include "Pawn.hpp"
#include "Common.hpp"

Pawn::Pawn(bool isWhitePiece, Position const& pos)
{
	rank = isWhitePiece ? Rank::WHITE_PAWN : Rank::BLACK_PAWN;
	position = pos;
	hasFirstMoveOccurred = false;
}

bool Pawn::CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH])
{
	//check if new position is out of bounds
	if (pos.x > BOARD_LENGTH - 1 || pos.y > BOARD_WIDTH - 1 || pos.x < 0 || pos.y < 0)
		return false;

	//check there isn't a piece in front of the pawn
	if (board[pos.x][pos.y] != 0)
		return false;

	int oneForward = rank > 0 ? -1 : 1;
	
	int xDifference = abs(position.x - pos.x);
	int yDifference = (position.y - pos.y);
	bool isValidMove = false;

	if (xDifference == 0 && pos.y == position.y + oneForward) // pawn is trying to move one space forward
		isValidMove = true;
	else if (xDifference == 1 && yDifference == 1 && rank > 0 && pos.y == position.y + oneForward && (board[pos.x][pos.y] ^ rank) < 0) //check if the pawn is trying to capture enemy one diagonal to them
		isValidMove = true;
	else if (!hasFirstMoveOccurred && xDifference == 0 && pos.y == position.y + (oneForward * 2)) //allow pawn to move +2 sqaures if it's their first move
		isValidMove = true;

	return isValidMove;
}

bool Pawn::MoveToLocation(Position const& pos)
{
	hasFirstMoveOccurred = true;
	position = pos;
	return true;
}

void Pawn::DrawPiece()
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
	g_Chess.WriteString("            ", posX, posY++, colour);
	g_Chess.WriteString("     ()     ", posX, posY++, colour);
	g_Chess.WriteString("     {}     ", posX, posY++, colour);
	g_Chess.WriteString("    {__}    ", posX, posY++, colour);
}