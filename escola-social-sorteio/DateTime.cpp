#include "pch.h"
#include "DateTime.h"


char *DateTime::format_datetime(const char *format, bool include_millis)
{
	SYSTEMTIME t;
	int result;
	char buffer[1024];

	GetLocalTime(&t);

	result = GetTimeFormat(LOCALE_USER_DEFAULT, 0, &t, (LPTSTR)"hh:mm:ss", (LPTSTR)buffer, sizeof(buffer));
	if (result > 0) {

	}

	return buffer;
}

