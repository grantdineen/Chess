#pragma once
#include <View.hpp>
#include <vector>
#include "ObservableCommands.hpp"
#include "Command.hpp"
#include "Board.hpp"

class StatsView : public View
{
private:
	Board& board_;
	ObservableCommands& commands_;

	int commandsBoxWidth_;
	int commandsBoxHeight_;
	int commandsBoxPosX_;
	int commandsBoxPosY_;

	int playersBoxPosX_;
	int playersBoxPosY_;
public:
	StatsView(Board& board, ObservableCommands& commands, int x, int y, int length, int width);

	void DrawView();
	void update(Event e) override;

private:
	void DrawCommandsWindow();
	void DrawPlayersWindow();
};