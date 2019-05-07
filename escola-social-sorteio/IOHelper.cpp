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
