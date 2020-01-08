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
			//use the Position constructor that takes a chess coord string
			Position locationOfPieceToMove(args[0]);
			Position locationOfDestination(args[2]);

			if (isValidMove(locationOfPieceToMove, locationOfDestination))
			{
				return new MovePieceCommand(board_, locationOfPieceToMove, locationOfDestination);
			}
		}
	}

	return nullptr;
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