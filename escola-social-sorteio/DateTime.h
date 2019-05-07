#pragma once

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

using namespace std;

class DateTime
{
public:
	static char *format_datetime(const char *format, bool include_millis = true);
};

