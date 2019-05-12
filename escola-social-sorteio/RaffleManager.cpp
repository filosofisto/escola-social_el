#include "pch.h"
#include "RaffleManager.h"

RaffleManager::RaffleManager(Out& out, ConsoleColor& cc, vector<Inscricao>* inscricoes): 
	out(out), cc(cc), inscricoes(inscricoes)
{
}

RaffleManager::~RaffleManager()
{
}

map<string, vector<Inscricao>*>& RaffleManager::process()
{
	cc.set(ConsoleColor::Color::LIGHT_GREEN);
	out << "-------------------------------------------------------------------------------" << endl;
	out << "Organizando o sorteio por Area de Capacitacao e Categoria..." << endl;
	out << "-------------------------------------------------------------------------------" << endl;

	fillMap();
	showQuantitiesPerCategoryAndArea();
	processEachRaffle();

	out << "Processamento realizado com sucesso" << endl;
	out << "-------------------------------------------------------------------------------" << endl;

	return mapInscricoes;
}

void RaffleManager::fillMap()
{
	out << "Criando estrutura de dados por Area e Categoria" << endl;
	string keyAsString;

	for (auto inscricao : *inscricoes) {
		MapKey key = MapKey(
			inscricao.getCapacitacao(), inscricao.getCategoria()
		);
		
		keyAsString = key.toString();

		vector<Inscricao>* list = mapInscricoes[keyAsString];
		
		if (list == nullptr) {
			list = new vector<Inscricao>();
			mapInscricoes[keyAsString] = list;
		}

		list->push_back(inscricao);
	}
}

void RaffleManager::showQuantitiesPerCategoryAndArea() const
{
	for (auto e : mapInscricoes) {
		out << "Area/Categoria: " << e.first << " - Inscritos: " << e.second->size() << endl;
	}
}

void RaffleManager::processEachRaffle()
{
	for (auto e : mapInscricoes) {
		processAreaCategory(e.first, e.second);
	}
}

void RaffleManager::processAreaCategory(const string& key, vector<Inscricao>* list)
{
	srand(unsigned(time(0)));

	out << "Processando Area/Categoria: " << key << endl;
	
	random_shuffle(list->begin(), list->end());

	int ruffle = 0;
	for (int i = 0; i < list->size(); i++) {
		if (list->at(i).getMoradorEstrutural()) {
			list->at(i).setRuffle(++ruffle);
		}
	}
	for (int i = 0; i < list->size(); i++) {
		if (!list->at(i).getMoradorEstrutural()) {
			list->at(i).setRuffle(++ruffle);
		}
	}

	sort(list->begin(), list->end());
}

void RaffleManager::showResult() const
{
	for (auto e: mapInscricoes) {
		showResult(e.first, e.second, ConsoleColor::Color::LIGHT_BLUE);
	}
}

void RaffleManager::showResult(const string& key, vector<Inscricao>* list, const ConsoleColor::Color color) const
{
	cc.set(color);
	out << "Area/Categoria: " << key << endl;

	for (auto i: *list) {
		out << i.getRuffle() << " - " << i.getCPF() << " " << i.getNomeInscrito() << " ME: " << (i.getMoradorEstrutural() ? "Sim" : "Nao") << endl;
	}
	cc.reset();
}
