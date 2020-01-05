#pragma once
#include "Piece.hpp"

class Queen : public Piece
{
public:
	Queen(bool isWhitePiece, Position const& pos);

	bool CanMoveToLocation(Position const& pos, int board[][8]) override;
	bool MoveToLocation(Position const& pos) override;
	void DrawPiece() override;
};