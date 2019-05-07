#pragma once

#include <Windows.h>
#include <iostream>
#include "FileAttributesException.h"

class IOHelper
{
public:
	static bool exist(const char* filename);
};

