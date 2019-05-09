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

using namespace std;

class RaffleManager
{
public:
	RaffleManager(ConsoleColor& cc, vector<Inscricao>* inscricoes);
	~RaffleManager();

	void process();
private:
	void fillMap();
	void processEachRaffle();
	void processCategoryArea(const string& key, vector<Inscricao>* list);
	void showQuantitiesPerCategoryAndArea() const;
	void showResult() const;
	void showResult(const string& key, vector<Inscricao>* list) const;

	vector<Inscricao>* inscricoes;
	map<string, vector<Inscricao>*> mapInscricoes;
	ConsoleColor& cc;
};

