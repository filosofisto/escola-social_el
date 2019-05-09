#include "pch.h"
#include "ConsoleColor.h"


ConsoleColor::ConsoleColor()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	reset();
}

ConsoleColor::~ConsoleColor()
{
}

void ConsoleColor::set(Color color)
{
	SetConsoleTextAttribute(hConsole, color + 9);
}

void ConsoleColor::reset()
{
	set(Color::WHITE);
}
