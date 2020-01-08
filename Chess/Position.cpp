#include <string>
#include "Position.hpp"
#include "Common.hpp"

Position::Position(std::string const& chessCoord)
{
	char letter = chessCoord[0];
	int number = (int)chessCoord[1] - 48; //conversion of a char to int

	//convert letter to index value
	switch (letter)
	{
	case 'a':
	case 'A':
		x = 0;
		break;
	case 'b':
	case 'B':
		x = 1;
		break;
	case 'c':
	case 'C':
		x = 2;
		break;
	case 'd':
	case 'D':
		x = 3;
		break;
	case 'e':
	case 'E':
		x = 4;
		break;
	case 'f':
	case 'F':
		x = 5;
		break;
	case 'g':
	case 'G':
		x = 6;
		break;
	case 'h':
	case 'H':
		x = 7;
		break;
	}

	//convert the number value (index is backwards from the visual layout)
	y = BOARD_WIDTH - number; // find the complement of the position selected
}

std::string Position::ToString() const
{
	std::string chessCoord = "";
	switch (x)
	{
	case 0:
		chessCoord += 'A';
		break;
	case 1:
		chessCoord += 'B';
		break;
	case 2:
		chessCoord += 'C';
		break;
	case 3:
		chessCoord += 'D';
		break;
	case 4:
		chessCoord += 'E';
		break;
	case 5:
		chessCoord += 'F';
		break;
	case 6:
		chessCoord += 'G';
		break;
	case 7:
		chessCoord += 'H';
		break;
	}

	chessCoord += std::to_string(BOARD_WIDTH - y);

	return chessCoord;
}