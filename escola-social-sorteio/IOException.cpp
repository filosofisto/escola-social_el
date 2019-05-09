#include "pch.h"
#include "IOException.h"


IOException::IOException(const char* message): message(message)
{
}

IOException::~IOException()
{
}

const char* IOException::what() const noexcept
{
	if (message == nullptr) {
		return "Erro de IO";
	}
	
	return message;
}
