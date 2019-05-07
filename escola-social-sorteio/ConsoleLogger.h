#pragma once

#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <string.h>
#include "Logger.h"
#include "DateTime.h"

using namespace std;

const int BUFFER_SIZE = 1024 * 10;

class ConsoleLogger :public Logger
{
public:
	ConsoleLogger(const char *ident);
	ConsoleLogger(const char *ident, const char *date_time_format);
	~ConsoleLogger();

	void error(const char *file, int line, const char *fmt, ...);
	void warn(const char *file, int line, const char *fmt, ...);
	void info(const char *file, int line, const char *fmt, ...);
	void debug(const char *file, int line, const char *fmt, ...);

protected:
	static const char *DEFAULT_LOG_DATETIME_FORMAT;

	char *time() const;

	const char *date_time_format;
};

