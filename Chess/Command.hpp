#pragma once
#include <string>

class Command
{
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual std::string ToString() const { return "Command"; }
	virtual ~Command() {}
};