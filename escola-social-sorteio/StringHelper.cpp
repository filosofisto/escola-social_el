#include "pch.h"
#include "StringHelper.h"

TCHAR* StringHelper::toTCHAR(const char* text)
{
	TCHAR ret[512];
	swprintf(ret, 512, L"%hs", text);

	return ret;
}
