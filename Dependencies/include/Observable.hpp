/*
Author:		Grant Dineen
Program:	Observable.hpp
Date:		April 15, 2019
Purpose:    Observable abstract class for Models to inherit from.
*/
#pragma once
#include <set>
#include "Observer.hpp"
#include "Event.hpp"

//abstract observable class for the models to inherit from
class Observable
{
protected:
	std::set<Observer*> observers_;
public:
	virtual void attach(Observer* p) = 0;
	virtual void detach(Observer* p) = 0;
	virtual void notify(Event e) = 0;
	virtual ~Observable() {}
};