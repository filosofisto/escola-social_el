#pragma once

#include <Windows.h>
#include <iostream>
#include <string>
#include "FileAttributesException.h"
#include "IOException.h"

using namespace std;

class IOHelper
{
public:
	static bool exist(const char* filename);

	static string curdir();
};

