#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "CommandGenerator.hpp"
#include "Command.hpp"
#include "MovePieceCommand.hpp"
#include "Position.hpp"
#include "Common.hpp"

Command* CommandGenerator::ParseCommand(std::string const& arg)
{

	std::vector<std::string> args;
	boost::algorithm::split(args, arg, boost::algorithm::is_space()); //split string by space

	if (args.size() < 1)
		return nullptr;

	std::regex chessCoordRegex("[a-hA-H][1-8]");

	if (args.size() == 3)
	{
		if (std::regex_match(args[0], chessCoordRegex) && args[1] == "->" && std::regex_match(args[2], chessCoordRegex))
		{
			Position locationOfPieceToMove = convertChessPosition(args[0]);
			Position locationOfDestination = convertChessPosition(args[2]);

			if (isValidMove(locationOfPieceToMove, locationOfDestination))
			{
				return new MovePieceCommand(board_, locationOfPieceToMove, locationOfDestination);
			}
		}
	}

	return nullptr;
}

Position CommandGenerator::convertChessPosition(std::string const& pos)
{
	Position position;
	char letter = pos[0];
	int number = (int)pos[1] - 48; //conversion of a char to int

	//convert letter to index value
	switch (letter)
	{
	case 'a':
	case 'A':
		position.x = 0;
		break;
	case 'b':
	case 'B':
		position.x = 1;
		break;
	case 'c':
	case 'C':
		position.x = 2;
		break;
	case 'd':
	case 'D':
		position.x = 3;
		break;
	case 'e':
	case 'E':
		position.x = 4;
		break;
	case 'f':
	case 'F':
		position.x = 5;
		break;
	case 'g':
	case 'G':
		position.x = 6;
		break;
	case 'h':
	case 'H':
		position.x = 7;
		break;
	}

	//convert the number value (index is backwards from the visual layout)
	position.y = BOARD_WIDTH - number; // find the complement of the position selected

	return position;
}

bool CommandGenerator::isValidMove(Position const& origin, Position const& destination)
{
	Piece* piece = board_.GetPieceAtPosition(origin);

	//no piece found at the selected position
	if (piece == nullptr)
		return false;

	//Black is trying to move a white piece or vice versa
	if ((board_.isWhitePlayersTurn && piece->GetRank() < 0) || (!board_.isWhitePlayersTurn && piece->GetRank() > 0))
		return false;

	//piece is not capable of making this move
	if (!piece->CanMoveToLocation(destination, board_.board))
		return false;

	return true;
}