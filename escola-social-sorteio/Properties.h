#pragma once

#include <string>
#include <cstring>
#include <fstream>
#include <map>
#include "IOHelper.h"
#include "IOException.h"

class Properties
{
public:
	Properties(const string& filename);
	Properties(const Properties& orig);
	virtual ~Properties();

	void load();

	string get(const string& key) const;

	bool has(const string& key) const;
protected:
	string filename;
	map<string, string> values;
};


