#include "pch.h"
#include "ParamsValidationException.h"

const char* ParamsValidationException::what() const noexcept
{
	return "Parametro invalido, favor informar o endereco do arquivo da planilha a ser processada";
}
