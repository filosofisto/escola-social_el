#pragma once

#include <iostream>
#include <string>

using namespace std;

class Logger {
public:
	enum Level { DEBUG, INFO, WARN, _ERROR };

	Logger(const char *ident);
	virtual ~Logger();

	virtual void error(const char *file, int line, const char *fmt, ...) = 0;
	virtual void warn(const char *file, int line, const char *fmt, ...) = 0;
	virtual void info(const char *file, int line, const char *fmt, ...) = 0;
	virtual void debug(const char *file, int line, const char *fmt, ...) = 0;

	void set_level(Level level);

	bool debugable() const;

	static string to_string(Level level);

	static Level to_level(const string& str, Level default_level = INFO);
protected:
	bool check_level(Level level) const;

	const char *ident;
	Level level;
};




