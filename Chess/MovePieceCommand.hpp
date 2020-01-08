#pragma once
#include <string>
#include "Command.hpp"
#include "Board.hpp"
#include "Position.hpp"

class MovePieceCommand : public Command
{
private:
	Board& board_;
	Position origin_;
	Position destination_;
	Piece* pieceMoved_;
	Piece* pieceCaptured_;
	bool wasPieceCaptured_;
public:
	MovePieceCommand(Board& board, Position const& origin, Position const& destination);
	~MovePieceCommand();

	void execute() override;
	void undo() override;
	std::string ToString() const override;
};