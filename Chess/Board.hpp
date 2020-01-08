#pragma once
#include <list>
#include <Observable.hpp>
#include <Event.hpp>
#include "Piece.hpp"
#include "Position.hpp"
#include "Common.hpp"

class Board : public Observable
{
public:
	std::list<Piece*> pieces;
	bool isWhitePlayersTurn;
	int board[BOARD_WIDTH][BOARD_LENGTH];

	~Board();

	void InitBoard();

	Piece* GetPieceAtPosition(Position const& pos);

	//Observable methods
	void attach(Observer* observer) override;
	void detach(Observer* observer) override;
	void notify(Event e) override;
};