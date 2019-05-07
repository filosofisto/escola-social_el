#include "pch.h"
#include "Logger.h"

Logger::Logger(const char *ident) :
	ident(ident), level(_ERROR)
{

}

Logger::~Logger()
{

}

void Logger::set_level(Level level)
{
	this->level = level;
}

bool Logger::check_level(Level level) const
{
	return level >= this->level;
}

bool Logger::debugable() const
{
	return check_level(DEBUG);
}

string Logger::to_string(Level level)
{
	if (level == Logger::DEBUG) {
		return string("DEBUG");
	}
	else if (level == Logger::INFO) {
		return string("INFO");
	}
	else if (level == Logger::WARN) {
		return string("WARN");
	}
	else {
		return string("ERROR");
	}

	return string();
}

Logger::Level Logger::to_level(const string& str, Level default_level)
{
	if (str == "DEBUG" || str == "debug") {
		return Logger::DEBUG;
	}
	else if (str == "INFO" || str == "info") {
		return Logger::INFO;
	}
	else if (str == "WARN" || str == "warn") {
		return Logger::INFO;
	}
	else if (str == "ERROR" || str == "error") {
		return Logger::_ERROR;
	}

	return default_level;
}

ostream& operator<<(std::ostream& os, enum Logger::Level level)
{
	os << Logger::to_string(level);

	return os;
}
