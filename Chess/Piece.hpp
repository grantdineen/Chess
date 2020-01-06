#pragma once
#include "Position.hpp"
#include "Common.hpp"

class Piece
{
public:
	enum Rank { BLACK_KING = -1000, BLACK_QUEEN = -9, BLACK_ROOK = -7, BLACK_BISHOP = -5, BLACK_KNIGHT = -3, BLACK_PAWN = -1,
				WHITE_PAWN = 1, WHITE_KNIGHT = 3, WHITE_BISHOP = 5, WHITE_ROOK = 7, WHITE_QUEEN = 9, WHITE_KING = 1000};
protected:
	Position position_;
	Rank rank_;

public:
	virtual bool CanMoveToLocation(Position const& p, int board[BOARD_WIDTH][BOARD_LENGTH]) = 0;
	virtual bool MoveToLocation(Position const& p) = 0;
	virtual void DrawPiece(int x, int y) = 0;

	virtual int GetX() const { return position_.x; }
	virtual int GetY() const { return position_.y; }
	virtual int GetRank() const { return (int)rank_; }
};