#include <iostream>
#include <consolelib.hpp>

class Chess : public ConsoleApplication
{
	int execute() override {
		std::cout << "Hello World" << std::endl;
		std::cin.get();
		return 0;
	}
};

Chess g_Chess;