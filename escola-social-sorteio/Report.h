#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "Inscricao.h"

using namespace std;

class Report
{
public:
	explicit Report(const string& filename);
	virtual ~Report();

	void build(const map<string, vector<Inscricao>*>& mapInscricao);

private:
	ofstream out;
};

