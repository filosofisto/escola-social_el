#pragma once

#include <tchar.h>
#include <string>
#include <algorithm>
#include <functional> 

using namespace std;

class StringHelper
{
public:
	//static TCHAR* toTCHAR(const char* text);

	static string& ltrim(string& text);

	static string& rtrim(string& text);

	static string& trim(string& text);
};

