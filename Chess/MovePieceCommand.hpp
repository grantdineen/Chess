#pragma once
#include "Command.hpp"
#include "Board.hpp"

class MovePieceCommand : public Command
{
private:
	Board& board_;
public:
	MovePieceCommand(Board& board);

	void execute() override;
	void undo() override;
};