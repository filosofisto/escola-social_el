#include "pch.h"
#include "FileNotFoundException.h"

const char* FileNotFoundException::what() const noexcept
{
	return "Arquivo informado nao existe";
}

