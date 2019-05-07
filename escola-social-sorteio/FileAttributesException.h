#pragma once

#include <stdexcept>

using namespace std;

class FileAttributesException :public exception
{
public:
	const char* what() const noexcept override;
};

