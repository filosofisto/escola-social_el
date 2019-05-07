#include "pch.h"
#include "ConsoleLogger.h"

const char *ConsoleLogger::DEFAULT_LOG_DATETIME_FORMAT = "%Y-%m-%d %H:%M:%S";

ConsoleLogger::ConsoleLogger(const char *ident) :
	Logger(ident), date_time_format(DEFAULT_LOG_DATETIME_FORMAT)
{

}

ConsoleLogger::ConsoleLogger(const char *ident, const char *date_time_format) :
	Logger(ident), date_time_format(date_time_format)
{

}

ConsoleLogger::~ConsoleLogger()
{

}

inline char *ConsoleLogger::time() const
{
	return DateTime::format_datetime(date_time_format);
}

void ConsoleLogger::info(const char *file, int line, const char *fmt, ...)
{
	if (!check_level(Level::INFO))
		return;

	char buff[BUFFER_SIZE];

	va_list args;
	va_start(args, fmt);
	vsnprintf(buff, BUFFER_SIZE, fmt, args);
	va_end(args);

	cout << time() << " [INFO ] " << ident << " " << file << "(" << line << ") " << buff << endl;
}

void ConsoleLogger::warn(const char *file, int line, const char *fmt, ...)
{
	if (!check_level(Level::WARN))
		return;

	char buff[BUFFER_SIZE];

	va_list args;
	va_start(args, fmt);
	vsnprintf(buff, BUFFER_SIZE, fmt, args);
	va_end(args);

	cout << "\033[1;33m" << time() << " [WARN ] " << ident << " " << file << "(" << line << ") " << buff << "\033[0m" << endl;
}

void ConsoleLogger::error(const char *file, int line, const char *fmt, ...)
{
	if (!check_level(Level::_ERROR)) 
		return;

	char buff[BUFFER_SIZE];

	va_list args;
	va_start(args, fmt);
	vsnprintf(buff, BUFFER_SIZE, fmt, args);
	va_end(args);

	cout << "\033[1;31m" << time() << " [ERROR] " << ident << " " << file << "(" << line << ") " << buff << "\033[0m" << endl;
}

void ConsoleLogger::debug(const char *file, int line, const char *fmt, ...)
{
	if (!check_level(Level::DEBUG))
		return;

	char buff[BUFFER_SIZE];

	va_list args;
	va_start(args, fmt);
	vsnprintf(buff, BUFFER_SIZE, fmt, args);
	va_end(args);

	cout << "\033[36m" << time() << " [DEBUG] " << ident << " " << file << "(" << line << ") " << buff << "\033[0m" << endl;
}
