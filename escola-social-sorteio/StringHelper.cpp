#include "pch.h"
#include "StringHelper.h"

/*TCHAR* StringHelper::toTCHAR(const char* text)
{
	TCHAR ret[512];
	swprintf(ret, 512, L"%hs", text);

	return ret;
}*/

string& StringHelper::ltrim(string& text)
{
	text.erase(text.begin(), find_if(text.begin(), text.end(), not1(ptr_fun<int, int>(isspace))));

	return text;
}

string& StringHelper::rtrim(string& text)
{
	text.erase(find_if(text.rbegin(), text.rend(), not1(ptr_fun<int, int>(isspace))).base(), text.end());

	return text;
}

string& StringHelper::trim(string& text)
{
	return ltrim(rtrim(text));
}

