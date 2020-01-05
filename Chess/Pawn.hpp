#pragma once
#include "Piece.hpp"
#include "Common.hpp"

class Pawn : public Piece
{
private:
	bool hasFirstMoveOccurred;

public:
	Pawn(bool isWhitePiece, Position const& pos);

	bool CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH]) override;
	bool MoveToLocation(Position const& pos) override;
	void DrawPiece() override;
};