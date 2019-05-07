#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Common.h"
#include "ParserException.h"
#include "Inscricao.h"

using namespace std;

class Parser
{
public:
	Parser();
	virtual ~Parser();

	vector<Inscricao>* parseFile(const char* filename);
	string toString() const;
private:
	void fill(Inscricao& i, int col, const string& word);

	vector<Inscricao> inscricoes;
};

