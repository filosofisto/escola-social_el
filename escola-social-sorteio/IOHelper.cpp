#include "pch.h"
#include "IOHelper.h"

bool IOHelper::exist(const char* filename)
{
	DWORD fileAttr = GetFileAttributesA(filename);

	if (fileAttr == INVALID_FILE_ATTRIBUTES) {
		throw FileAttributesException();
	}

	return (fileAttr & FILE_ATTRIBUTE_DIRECTORY) == 0;
}

string IOHelper::curdir()
{
	TCHAR buffer[MAX_PATH];
	DWORD ret = GetCurrentDirectory(MAX_PATH, buffer);
	if (ret == 0) {
		throw IOException("Nao foi possivel obter o diretorio corrente");
	}
	if (ret > MAX_PATH) {
		throw IOException("Buffer muito pequeno para obter o diretorio corrente");
	}

	string result = buffer;

	return result;
}
