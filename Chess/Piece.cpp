#include "Piece.hpp"

bool Piece::IsPieceBlockingPath(Position const& p, int board[BOARD_WIDTH][BOARD_LENGTH])
{
	//figure out if which direction piece is trying to move. (UP/DOWN/LEFT/RIGHT/DIAGONAL)
	int incrementX = position_.x > p.x ? -1 : position_.x < p.x ? 1 : 0;
	int incrementY = position_.y > p.y ? -1 : position_.y < p.y ? 1 : 0;
	
	//get the position of the square just before the destination
	//it doesn't matter if there is a piece at the destination
	//we only care about the path from the piece to the destination here
	Position posEnd = p; 
	posEnd.x -= incrementX;
	posEnd.y -= incrementY;

	//get the position of the square just after the current position of the piece
	Position posStart = position_;
	posStart.x += incrementX;
	posStart.y += incrementY;

	for (int ix = posStart.x, iy = posStart.y; ix != p.x || iy != p.y; ix += incrementX, iy += incrementY)
	{
		if (board[iy][ix] != 0) //if not an empty square
			return true;
	}

	return false;
}