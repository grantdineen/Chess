#include <iostream>
#include <stack>
#include "Chess.hpp"
#include "BoardView.hpp"
#include "CommandGenerator.hpp"

int Chess::execute() 
{
	SetTitle("Chess");
	ResizeWindow(150, 50);
	//HideCursor();
	SetCursorPos(100, 25);

	Board board;
	board.InitBoard();
	BoardView boardView(board, 1, 1);

	std::stack<Command*> commands;

	//attach observers
	board.attach(&boardView);

	boardView.DrawBoard();
	boardView.DrawPieces();

	std::string arguments;
	CommandGenerator commandGenerator(board);

	do {
		std::getline(std::cin, arguments);
		Command* command = commandGenerator.ParseCommand(arguments);
		if (command != nullptr) 
		{
			commands.push(command);
			command->execute();
			std::cout << command->ToString() << std::endl;
		}
	} while (arguments != "STOP");

	//cleanup commands
	while (!commands.empty())
	{
		delete commands.top();
		commands.pop();
	}

	//detach observers
	board.detach(&boardView);

	return 0;
}

Chess g_Chess;