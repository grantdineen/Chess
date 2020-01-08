#include "Board.hpp"
#include "King.hpp"
#include "Queen.hpp"
#include "Bishop.hpp"
#include "Knight.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"

void Board::InitBoard()
{
	//white pieces
	pieces.push_back(new King(true, { 4, 7 }));
	pieces.push_back(new Queen(true, { 3, 7 }));
	pieces.push_back(new Bishop(true, { 5, 7 }));
	pieces.push_back(new Bishop(true, { 2, 7 }));
	pieces.push_back(new Knight(true, { 1, 7 }));
	pieces.push_back(new Knight(true, { 6, 7 }));
	pieces.push_back(new Rook(true, { 0, 7 }));
	pieces.push_back(new Rook(true, { 7, 7 }));
	pieces.push_back(new Pawn(true, { 0, 6 }));
	pieces.push_back(new Pawn(true, { 1, 6 }));
	pieces.push_back(new Pawn(true, { 2, 6 }));
	pieces.push_back(new Pawn(true, { 3, 6 }));
	pieces.push_back(new Pawn(true, { 4, 6 }));
	pieces.push_back(new Pawn(true, { 5, 6 }));
	pieces.push_back(new Pawn(true, { 6, 6 }));
	pieces.push_back(new Pawn(true, { 7, 6 }));

	//black pieces
	pieces.push_back(new King(false, { 3, 0 }));
	pieces.push_back(new Queen(false, { 4, 0 }));
	pieces.push_back(new Bishop(false, { 5, 0 }));
	pieces.push_back(new Bishop(false, { 2, 0 }));
	pieces.push_back(new Knight(false, { 1, 0 }));
	pieces.push_back(new Knight(false, { 6, 0 }));
	pieces.push_back(new Rook(false, { 0, 0 }));
	pieces.push_back(new Rook(false, { 7, 0 }));
	pieces.push_back(new Pawn(false, { 0, 1 }));
	pieces.push_back(new Pawn(false, { 1, 1 }));
	pieces.push_back(new Pawn(false, { 2, 1 }));
	pieces.push_back(new Pawn(false, { 3, 1 }));
	pieces.push_back(new Pawn(false, { 4, 1 }));
	pieces.push_back(new Pawn(false, { 5, 1 }));
	pieces.push_back(new Pawn(false, { 6, 1 }));
	pieces.push_back(new Pawn(false, { 7, 1 }));
	
	for (int i = 0; i < BOARD_WIDTH; i++)
	{
		for (int j = 0; j < BOARD_LENGTH; j++)
		{
			board[i][j] = 0;
		}
	}

	for (Piece* p : pieces)
		board[p->GetY()][p->GetX()] = p->GetRank();

	isWhitePlayersTurn = true;
}

Piece* Board::GetPieceAtPosition(Position const& pos)
{
	for (Piece* p : pieces)
	{
		if (p->GetX() == pos.x && p->GetY() == pos.y)
			return p;
	}

	return nullptr;
}

void Board::attach(Observer* observer)
{
	observers_.insert(observer);
}

void Board::detach(Observer* observer)
{
	observers_.erase(observer);
}

void Board::notify(Event e)
{
	for (Observer* p : observers_)
		p->update(e);
}

Board::~Board()
{
	while (!pieces.empty())
	{
		delete pieces.back();
		pieces.pop_back();
	}
}