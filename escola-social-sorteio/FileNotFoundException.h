#pragma once

#include <stdexcept>

using namespace std;

class FileNotFoundException :public exception
{
public:
	const char* what() const noexcept override;
};

