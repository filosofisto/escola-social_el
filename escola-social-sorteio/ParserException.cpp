#include "pch.h"
#include "ParserException.h"

const char* ParserException::what() const noexcept
{
	return "Erro ao processar o arquivo";
}
