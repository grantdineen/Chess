#pragma once
#include <string>

class Position
{
public:
	int x;
	int y;

	//Constructors
	Position() : x(0), y(0) {}
	Position(int x, int y) : x(x), y(y) {}
	Position(std::string const& chessCoord); // get position from chess coord

	std::string ToString() const;
};