#pragma once
#include <string>
#include "Command.hpp"

class CommandParser
{
public:
	static Command* ParseCommad(std::string const& arg);
};