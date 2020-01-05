#include <iostream>
#include "Chess.hpp"
#include "BoardView.hpp"
#include "Rook.hpp"

int Chess::execute() 
{
	SetTitle("Chess");
	ResizeWindow(150, 48);
	//HideCursor();
	SetCursorPos(100, 25);

	Board board;
	board.InitBoard();
	BoardView boardView(board, 0, 0);

	boardView.DrawBoard();
	boardView.DrawPieces();

	//std::string testInput;
	//std::cin >> testInput;
	std::cin.get();
	return 0;
}


Chess g_Chess;