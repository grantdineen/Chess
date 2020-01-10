#pragma once
#include <View.hpp>

class InputView : public View
{
private:
	int textFieldWidth_;
	int textFieldPosX_;
	int textFieldPosY_;

public:
	InputView(int x, int y, int length, int width);

	void DrawView();
	void update(Event e) override;

private:
	void ResetInputField();
};