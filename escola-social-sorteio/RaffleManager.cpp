#include "pch.h"
#include "RaffleManager.h"

RaffleManager::RaffleManager(vector<Inscricao>* inscricoes): inscricoes(inscricoes)
{
}

RaffleManager::~RaffleManager()
{
}

void RaffleManager::process()
{
	fillMap();
}

void RaffleManager::fillMap()
{
	for (auto inscricao : *inscricoes) {
		MapKey key = MapKey(inscricao.getCategoria(), inscricao.getAreaCapacitacaoDesejada());
		vector<Inscricao>* list = mapInscricoes[key.toString()];
		
		if (list == nullptr) {
			list = new vector<Inscricao>();
			mapInscricoes[key.toString()] = list;
		}

		list->push_back(inscricao);
	}
}
