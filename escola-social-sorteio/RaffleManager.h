#pragma once

#include <map>
#include <vector>
#include <string>
#include "Inscricao.h"
#include "MapKey.h"

using namespace std;

class RaffleManager
{
public:
	RaffleManager(vector<Inscricao>* inscricoes);
	~RaffleManager();

	void process();
private:
	void fillMap();

	vector<Inscricao>* inscricoes;
	map<string, vector<Inscricao>*> mapInscricoes;
};

