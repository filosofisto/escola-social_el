#pragma once

#include <Windows.h>

class ConsoleColor
{
public:
	enum Color {LIGHT_BLUE, LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_PURPLE, LIGHT_YELLOW, WHITE};

	ConsoleColor();
	virtual ~ConsoleColor();

	void set(Color color);
	void reset();
private:
	HANDLE hConsole;
	Color color;
};

