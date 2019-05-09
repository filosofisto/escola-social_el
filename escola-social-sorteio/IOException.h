#pragma once

#include <stdexcept>

using namespace std;

class IOException :public exception
{
public:
	IOException(const char* message);
	virtual ~IOException();

	const char* what() const noexcept override;
private:
	const char* message;
};

