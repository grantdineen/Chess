#pragma once
#include "Piece.hpp"

class Bishop : public Piece
{
public:
	Bishop(bool isWhitePiece, Position const& pos);

	bool CanMoveToLocation(Position const& pos, int board[][8]) override;
	bool MoveToLocation(Position const& pos) override;
	void DrawPiece() override;
};