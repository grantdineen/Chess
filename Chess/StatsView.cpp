#include <string>
#include "StatsView.hpp"
#include "Common.hpp"

StatsView::StatsView(Board& board, ObservableCommands& commands, int x, int y, int length, int width) : board_(board), commands_(commands)
{
	posX_ = x;
	posY_ = y;
	startX_ = posX_;
	endX_ = startX_ + length;
	startY_ = posY_;
	endY_ = startY_ + width;
	width_ = endX_ - startX_;
	height_ = endY_ - startY_;

	//setup command box dimensions
	commandsBoxWidth_ = (int)width_ * 0.8;
	commandsBoxHeight_ = 3;
	commandsBoxPosX_ = ((startX_ + endX_) / 2) - (commandsBoxWidth_ / 2);
	commandsBoxPosY_ = (startY_ + endY_) / 4;

	//setup players box dimensions
	playersBoxPosX_ = ((startX_ + endX_) / 2) - (width_ / 4);
	playersBoxPosY_ = (startY_ + endY_) / 2;

	DrawView();
}

void StatsView::DrawView()
{
	int x = startX_;
	int y = startY_;
	for (int i = 0; i < height_; i++)
		g_Chess.WriteString(std::string(width_, ' '), x, y++, Colours::B_DARKBLUE);

	DrawCommandsWindow();
	DrawPlayersWindow();
}

void StatsView::DrawCommandsWindow()
{
	for (int i = 0; i < commandsBoxHeight_; i++)
	{
		g_Chess.WriteString(std::string(commandsBoxWidth_, ' '), commandsBoxPosX_, commandsBoxPosY_ + i, Colours::B_BLACK);
	}
}

void StatsView::DrawPlayersWindow()
{
	std::string player1Name = "Player 1";
	std::string player2Name = "Player 2";

	g_Chess.WriteString(player1Name, playersBoxPosX_, playersBoxPosY_, Colours::F_WHITE | Colours::B_DARKBLUE);
	g_Chess.WriteString(player2Name, playersBoxPosX_, playersBoxPosY_ + 2, Colours::F_WHITE | Colours::B_DARKBLUE);

	if (board_.isWhitePlayersTurn)
	{
		g_Chess.WriteString("   <--", playersBoxPosX_ + player1Name.size(), playersBoxPosY_, Colours::F_WHITE | Colours::B_DARKBLUE);
		g_Chess.WriteString("      ", playersBoxPosX_ + player2Name.size(), playersBoxPosY_ + 2, Colours::F_WHITE | Colours::B_DARKBLUE);
	}
	else
	{
		g_Chess.WriteString("      ", playersBoxPosX_ + player1Name.size(), playersBoxPosY_, Colours::F_WHITE | Colours::B_DARKBLUE);
		g_Chess.WriteString("   <--", playersBoxPosX_ + player2Name.size(), playersBoxPosY_ + 2, Colours::F_WHITE | Colours::B_DARKBLUE);
	}
}

void StatsView::update(Event e)
{
	DrawCommandsWindow();
	int counter = 3;
	int x = commandsBoxPosX_;
	int y = commandsBoxPosY_;
	std::vector<Command*> commands = commands_.GetCommands();
	for(std::vector<Command*>::reverse_iterator it = commands.rbegin(); it != commands.rend(); it++)
	{
		if (--counter < 0)
			break;
		g_Chess.WriteString((*it)->ToString(), x, y++, Colours::B_BLACK | Colours::F_WHITE);
	}

	DrawPlayersWindow();
}