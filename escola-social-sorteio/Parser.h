#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "Common.h"
#include "ParserException.h"
#include "Inscricao.h"
#include "ConsoleColor.h"
#include "StringHelper.h"

using namespace std;

class Parser
{
public:
	Parser(ConsoleColor& cc);
	virtual ~Parser();

	vector<Inscricao>* parseFile(const char* filename);
private:
	void fill(Inscricao& i, int col, string& word);

	vector<Inscricao> inscricoes;
	ConsoleColor& cc;
};

