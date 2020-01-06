#pragma once
#include <vector>
#include <Observable.hpp>
#include <Event.hpp>
#include "Piece.hpp"
#include "Common.hpp"

class Board : public Observable
{
public:
	std::vector<Piece*> pieces;
	int board[BOARD_WIDTH][BOARD_LENGTH];

	~Board();

	void InitBoard();

	void attach(Observer* observer) override;
	void detach(Observer* observer) override;
	void notify(Event e) override;
};