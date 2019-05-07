#pragma once

#include <stdexcept>

using namespace std;

class ParserException :public exception
{
public:
	const char* what() const noexcept override;
};

