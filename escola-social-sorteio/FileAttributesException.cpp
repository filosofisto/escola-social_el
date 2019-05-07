#include "pch.h"
#include "FileAttributesException.h"

const char* FileAttributesException::what() const noexcept
{
	return "Erro ao tentar ler os atributos do arquivo";
}
