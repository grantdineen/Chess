#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include "CommandParser.hpp"
#include "Command.hpp"

Command* CommandParser::ParseCommad(std::string const& arg)
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
			
		}
	}

	return nullptr;
}