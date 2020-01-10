#include "ObservableCommands.hpp"

void ObservableCommands::Push(Command* c)
{
	commands_.push_back(c);
	notify(Event::INPUT_VIEW);
}

Command* ObservableCommands::Peek()
{
	if (commands_.size() < 1)
		return nullptr;
	return commands_.back();
}

void ObservableCommands::Clear()
{
	while (!commands_.empty())
	{
		delete commands_.back();
		commands_.pop_back();
	}
	notify(Event::INPUT_VIEW);
}

void ObservableCommands::attach(Observer* p)
{
	observers_.insert(p);
}

void ObservableCommands::detach(Observer* p)
{
	observers_.erase(p);
}

void ObservableCommands::notify(Event e)
{
	for (Observer* p : observers_)
		p->update(e);
}