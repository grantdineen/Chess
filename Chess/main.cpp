#include <iostream>
#include <stack>
#include "Chess.hpp"
#include "BoardView.hpp"
#include "InputView.hpp"
#include "StatsView.hpp"
#include "ObservableCommands.hpp"
#include "CommandGenerator.hpp"

int Chess::execute() 
{
	SetTitle("Chess");
	ResizeWindow(150, 50);
	//HideCursor();
	SetCursorPos(100, 25);

	ObservableCommands commands;
	Board board;
	board.InitBoard();
	BoardView boardView(board, 1, 1);
	StatsView statsView(board, commands, 97, 1, 53, 15);
	InputView inputView(97, 16, 53, 15);


	//attach observers
	board.attach(&boardView);
	board.attach(&statsView);

	commands.attach(&statsView);

	boardView.DrawBoard();
	boardView.DrawPieces();

	std::string arguments;
	CommandGenerator commandGenerator(board);

	do {
		std::getline(std::cin, arguments);
		Command* command = commandGenerator.ParseCommand(arguments);
		if (command != nullptr) 
		{
			commands.Push(command);
			command->execute();
			
		}
		inputView.update(Event::INPUT_VIEW);
	} while (arguments != "STOP");

	//cleanup commands
	commands.Clear();

	//detach observers
	board.detach(&boardView);
	board.detach(&statsView);
	commands.detach(&statsView);

	return 0;
}

Chess g_Chess;