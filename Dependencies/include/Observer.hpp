/*
Author:		Grant Dineen
Program:	Observer.hpp
Date:		April 15, 2019
Purpose:	Abstract Observer class for Views to inherit from.
*/
#pragma once
#include "Event.hpp"

//Abstract observer class for views to inherit from
class Observer
{
public:
	virtual void update(Event e) = 0;
	virtual ~Observer() {}
};
