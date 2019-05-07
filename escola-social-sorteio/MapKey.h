#pragma once

#include <string>
#include <sstream>

using namespace std;

class MapKey
{
public:
	MapKey(const string& categoria, const string& areaCapacitacao);
	~MapKey();

	string toString() const;
private:
	string categoria;
	string areaCapacitacao;
};

