#include <iostream>
#include "Chess.hpp"
#include "BoardView.hpp"
#include "CommandParser.hpp"

int Chess::execute() 
{
	SetTitle("Chess");
	ResizeWindow(150, 50);
	//HideCursor();
	SetCursorPos(100, 25);

	Board board;
	board.InitBoard();
	BoardView boardView(board, 1, 1);

	//attach observers
	board.attach(&boardView);

	boardView.DrawBoard();
	boardView.DrawPieces();

	std::string testInput;

	do {
		std::getline(std::cin, testInput);
		CommandParser::ParseCommad(testInput);
		
	} while (testInput != "STOP");
	//std::cin.get();

	//detach observers
	board.detach(&boardView);

	return 0;
}


Chess g_Chess;