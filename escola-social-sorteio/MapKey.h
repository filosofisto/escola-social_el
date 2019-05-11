#pragma once

#include <string>
#include <sstream>

using namespace std;

class MapKey
{
public:
	MapKey(const string& capacitacao, const string& categoria);
	~MapKey();

	string toString() const;
	string getCapacitacao() const;
	string getCategoria() const;
private:
	string capacitacao;
	string categoria;
};

