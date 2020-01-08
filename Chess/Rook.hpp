#pragma once
#include <string>
#include "Piece.hpp"
#include "Common.hpp"

class Rook : public Piece
{
public:
	Rook(bool isWhitePiece, Position const& pos);

	bool CanMoveToLocation(Position const& pos, int board[BOARD_WIDTH][BOARD_LENGTH]) override;
	bool MoveToLocation(Position const& pos) override;
	void DrawPiece(int x, int y) override;
	std::string ToString() const override;
};