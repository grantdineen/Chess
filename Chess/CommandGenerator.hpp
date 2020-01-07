#pragma once
#include <string>
#include "Command.hpp"
#include "Position.hpp"
#include "Board.hpp"

class CommandGenerator
{
private:
	Board& board_;

public:
	CommandGenerator(Board& board) : board_(board) {}

	Command* ParseCommand(std::string const& arg);
private:
	Position convertChessPosition(std::string const& pos);
	bool isValidMove(Position const& origin, Position const& destination);
};