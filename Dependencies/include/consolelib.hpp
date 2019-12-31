/*
Author:		Grant Dineen
Program:	consolelib.hpp
Date:		March 1, 2019
Purpose:	Declares an Inner Facade that provides easy access to WinApi functions.
			Declares a Singleton Outer Facade that Clients can inherit from to get access
			to the Inner Facade.
*/
#pragma once
#include <Windows.h>
#include <vector>
#include <string>

//Holds input information
typedef struct InputInformation
{
	int mouseClick;
	int mouseX;
	int mouseY;
	char keys;
	bool keyReleased;

	static const int LEFT_CLICK = 1, RIGHT_CLICK = 2,
		MOUSE_LEFT_BUTTON_HELD_DOWN = 4;
	static const int C_KEY = 1, R_KEY = 2;

	InputInformation()
	{
		mouseClick = 0;
		mouseX = 0;
		mouseY = 0;
		keys = 0;
		keyReleased = false;
	}
} InputInformation;


//Inner facade
class Win32APIWrapper
{
	HANDLE						hConsoleInput_,
		hConsoleOutput_;
public:
	static bool					isDone_;

public:
	//Constructor and Destructor definitions
	Win32APIWrapper();
	~Win32APIWrapper();

	//OUTPUT methods
	std::vector<char> GetTitle();
	void SetTitle(std::string const& title);
	COORD GetWindowsSize();
	void SetWindowSize(COORD size);
	CONSOLE_SCREEN_BUFFER_INFO GetCSBI();
	void SetCSBI(CONSOLE_SCREEN_BUFFER_INFO csbi);
	CONSOLE_CURSOR_INFO GetCursor();
	void SetCursor(CONSOLE_CURSOR_INFO const& cci);
	void SetCursorPos(CONSOLE_SCREEN_BUFFER_INFO const& csbi);
	std::vector<CHAR_INFO> GetBuffer(CONSOLE_SCREEN_BUFFER_INFO csbi);
	void SetBuffer(std::vector< CHAR_INFO> const& buffer, CONSOLE_SCREEN_BUFFER_INFO const& csbi, COORD coord);
	void HideCursor();
	void ShowCursor();
	void ClearScreen(CONSOLE_SCREEN_BUFFER_INFO const& csbi);
	void ClearScreen(CONSOLE_SCREEN_BUFFER_INFO const& csbi, WORD const& colour);
	void WriteString(std::string const& msg);
	void WriteString(std::string const& msg, COORD loc);
	void WriteString(std::string const& msg, COORD loc, WORD colour);

	//INPUT methods
	static BOOL CtrlHandler(DWORD ctrlType);
	void InstallCtrlHandler();
	DWORD GetTheConsoleMode();
	void SetTheConsoleMode(DWORD cMode);
	void InitConsoleInput();
	DWORD GetConsoleInput(std::vector<INPUT_RECORD>& buffer);
	InputInformation MouseEventProc(MOUSE_EVENT_RECORD const& mer);
	InputInformation KeyEventProc(KEY_EVENT_RECORD const& ker);

};


//Outer facade
class ConsoleApplication
{
	Win32APIWrapper console_;
	std::vector<char> originalTitle_;
	CONSOLE_SCREEN_BUFFER_INFO originalCSBI_;
	std::vector<CHAR_INFO> originalBuffer_;
	DWORD originalConsoleMode_;
	COORD originalBufferCoord_;
	CONSOLE_CURSOR_INFO originalCCI_;
	std::vector<std::string> args_;
public:
	void SaveConsoleState();
	void RestoreConsole();

	void SetCSBI(CONSOLE_SCREEN_BUFFER_INFO const& csbi);
	void SetBuffer(std::vector<CHAR_INFO> const& buffer);
	void SetMode(DWORD mode);
	void SetCursor(CONSOLE_CURSOR_INFO const& cci);
	void SetCursorPos(int x, int y);
	void SetTitle(std::string const& title);
	CONSOLE_SCREEN_BUFFER_INFO GetCSBI();
	std::vector<CHAR_INFO> GetBuffer();
	DWORD GetMode();
	CONSOLE_CURSOR_INFO GetCursor();
	std::vector<char> GetTitle();
	int GetWindowWidth();
	int GetWindowHeight();
	void HideCursor();
	void ShowCursor();
	void ResizeWindow(int x, int y);
	void ClearScreen();
	void ClearScreen(WORD const& colour);
	void WriteString(std::string const& str);
	void WriteString(std::string const& str, int x, int y);
	void WriteString(std::string const& str, int x, int y, int colour);
	InputInformation DetectInput();
	bool IsDone();
	void IsDone(bool b);
private:
	static ConsoleApplication* thisApp_sm;
	friend int main(int argc, char* argv[]);
	int main(int argc, char* argv[]);
protected:
	ConsoleApplication();
	virtual ~ConsoleApplication() { RestoreConsole(); }
	virtual int execute();
	std::vector<std::string> const& get_args() { return args_; }
};

//Colours
class Colours
{
public:
	const static int B_RED = BACKGROUND_RED | BACKGROUND_INTENSITY;
	const static int B_GREEN = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	const static int B_BLUE = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
	const static int B_DARKRED = BACKGROUND_RED;
	const static int B_DARKGREEN = BACKGROUND_GREEN;
	const static int B_DARKBLUE = BACKGROUND_BLUE;
	const static int B_YELLOW = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
	const static int B_MAGENTA = BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_BLUE;
	const static int B_CYAN = BACKGROUND_INTENSITY | BACKGROUND_GREEN | BACKGROUND_BLUE;
	const static int B_WHITE = B_RED | B_GREEN | B_BLUE;
	const static int B_GRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;
	const static int B_BLACK = 0;
	const static int F_RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
	const static int F_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	const static int F_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
	const static int F_DARKRED = FOREGROUND_RED;
	const static int F_DARKGREEN = FOREGROUND_GREEN;
	const static int F_DARKBLUE = FOREGROUND_BLUE;
	const static int F_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
	const static int F_MAGENTA = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE;
	const static int F_CYAN = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE;
	const static int F_WHITE = F_RED | F_GREEN | F_BLUE;
	const static int F_BLACK = 0;

};

//KeyCodes
class KeyCodes
{
public:
	static const int C_KEY = 'c';
	static const int R_KEY = 'r';
};

//Exception class from class to help handle any exceptions from WINAPI calls
#pragma region XError
std::string ErrorDescription(DWORD dwMessageID);
/* Console error exception class. */
class XError {
public:
	using id_type = decltype(GetLastError());
	using file_type = char const*;
	using string_type = std::string;
private:
	id_type code_;
	int	line_;
	file_type file_;
public:
	XError(int line, file_type file) : code_(GetLastError()), line_(line), file_(file) {}
	auto code() const -> id_type { return code_; }
	auto line() const -> int { return line_; }
	auto file() const -> file_type { return file_; }

	string_type msg() const;
};

/* Console error exception throw helper macro. */
#define THROW_IF_CONSOLE_ERROR(res) if(!res) throw XError(__LINE__,__FILE__)
#define THROW_CONSOLE_ERROR() throw XError(__LINE__,__FILE__)

#pragma endregion