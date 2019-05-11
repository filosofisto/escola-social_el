#pragma once

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <ctime>
#include "Inscricao.h"
#include "MapKey.h"
#include "ConsoleColor.h"
#include "Out.h"

using namespace std;

class RaffleManager
{
public:
	RaffleManager(Out& out, ConsoleColor& cc, vector<Inscricao>* inscricoes);
	~RaffleManager();

	map<string, vector<Inscricao>*>& process();
private:
	void fillMap();
	void processEachRaffle();
	void processAreaCategory(const string& key, vector<Inscricao>* list);
	void showQuantitiesPerCategoryAndArea() const;
	void showResult() const;
	void showResult(const string& key, vector<Inscricao>* list, const ConsoleColor::Color color) const;

	vector<Inscricao>* inscricoes;
	map<string, vector<Inscricao>*> mapInscricoes;
	ConsoleColor& cc;
	Out& out;
};

