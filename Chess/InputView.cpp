#include <string>
#include "InputView.hpp"
#include "Common.hpp"

InputView::InputView(int x, int y, int length, int width)
{
	//setup the entire view dimensions
	posX_ = x;
	posY_ = y;
	startX_ = posX_;
	endX_ = startX_ + length;
	startY_ = posY_;
	endY_ = startY_ + width;
	width_ = endX_ - startX_;
	height_ = endY_ - startY_;

	//setup text field dimensions
	textFieldWidth_ = (int)width_ * 0.8;
	textFieldPosX_ = ((startX_ + endX_) / 2) - (textFieldWidth_ / 2);
	textFieldPosY_ = (startY_ + endY_) / 2;

	DrawView();
}

void InputView::DrawView()
{
	int x = startX_;
	int y = startY_;
	for(int i = 0; i < height_; i++)
		g_Chess.WriteString(std::string(width_, ' '), x, y++, Colours::B_DARKGREEN);

	ResetInputField();
}

void InputView::update(Event e)
{
	ResetInputField();
}

void InputView::ResetInputField()
{
	g_Chess.WriteString(std::string(textFieldWidth_, ' '), textFieldPosX_, textFieldPosY_, Colours::B_BLACK);
	g_Chess.SetCursorPos(textFieldPosX_, textFieldPosY_);
}