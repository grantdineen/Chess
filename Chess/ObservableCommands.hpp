#pragma once
#include <vector>
#include <Observable.hpp>
#include "Command.hpp"

class ObservableCommands : public Observable
{
private:
	std::vector<Command*> commands_;
public:

	void Push(Command* c);
	Command* Peek();
	std::vector<Command*> GetCommands() const& { return commands_; }
	void Clear();

	//Observable methods
	void attach(Observer* p);
	void detach(Observer* p);
	void notify(Event e);
};