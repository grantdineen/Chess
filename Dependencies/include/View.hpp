/*
Author:		Grant Dineen
Program:	View.hpp
Date:		April 15, 2019
Purpose:	View abstract class to use as base for other views.
			Inherits from Observer
*/
#pragma once
#include "Observer.hpp"

//abstract View class
class View : public Observer
{
public:
	void update(Event e) override = 0;
	//determine if the mouse has clicked within the boundaries of this view
	bool isHit(int x, int y) { if (x >= startX_ && x < endX_ && y >= startY_ && y < endY_) return true; return false; }

	int width_;
	int height_;
	int posX_;
	int posY_;
	int startX_;
	int startY_;
	int endX_;
	int endY_;
};
