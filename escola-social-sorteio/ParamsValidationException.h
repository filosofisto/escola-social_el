#pragma once

#include <stdexcept>

using namespace std;

class ParamsValidationException : public exception
{
public:
	const char* what() const noexcept override;
};

