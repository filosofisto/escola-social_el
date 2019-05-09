#include "pch.h"
#include "RaffleManager.h"

RaffleManager::RaffleManager(ConsoleColor& cc, vector<Inscricao>* inscricoes): cc(cc), inscricoes(inscricoes)
{
}

RaffleManager::~RaffleManager()
{
}

void RaffleManager::process()
{
	cc.set(ConsoleColor::Color::LIGHT_GREEN);
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Organizando o sorteio por Categoria e Area de Capacitacao..." << endl;
	cout << "-------------------------------------------------------------------------------" << endl;

	fillMap();
	showQuantitiesPerCategoryAndArea();
	processEachRaffle();

	cout << "Processamento realizado com sucesso" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}

void RaffleManager::fillMap()
{
	cout << "Criando estrutura de dados por Categoria e Area" << endl;

	for (auto inscricao : *inscricoes) {
		MapKey key = MapKey(
			inscricao.getCategoria(), inscricao.getAreaCapacitacaoDesejada()
		);
		vector<Inscricao>* list = mapInscricoes[key.toString()];
		
		if (list == nullptr) {
			list = new vector<Inscricao>();
			mapInscricoes[key.toString()] = list;
		}

		list->push_back(inscricao);
	}
}

void RaffleManager::showQuantitiesPerCategoryAndArea() const
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << " Quantidade de inscritos por Categoria e Area" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;

	for (auto it = mapInscricoes.begin(); it != mapInscricoes.end(); ++it) {
		cout << "Categoria/Area: " << it->first << " - Inscritos: " << it->second->size() << endl;
	}
	
	cout << "-------------------------------------------------------------------------------" << endl;
}

void RaffleManager::processEachRaffle()
{
	srand(unsigned(time(0)));

	for (auto it = mapInscricoes.begin(); it != mapInscricoes.end(); ++it) {
		processCategoryArea(it->first, it->second);
	}
}

void RaffleManager::processCategoryArea(const string& key, vector<Inscricao>* list)
{
	cout << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Processando Catgoria/Area: " << key << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Lista original: " << endl;
	showResult(key, list);

	cout << "Embaralhando lista de inscritos" << endl;
	random_shuffle(list->begin(), list->end());
	
	cout << "Ordenando por 'Morador Estrutural'" << endl;
	sort(list->begin(), list->end());

	cout << "Lista processada: " << endl;
	showResult(key, list);

	cout << "-------------------------------------------------------------------------------" << endl;
}


void RaffleManager::showResult() const
{
	for (auto it = mapInscricoes.begin(); it != mapInscricoes.end(); ++it) {
		showResult(it->first, it->second);
	}
}

void RaffleManager::showResult(const string& key, vector<Inscricao>* list) const
{
	cout << "Categoria/Area: " << key << endl;
	int classificacao = 0;

	for (auto it = list->begin(); it != list->end(); ++it) {
		cout << (++classificacao) << " - " << it->getCPF() << " " << it->getNome() << " ME: " << (it->getMoradorEstrutural() ? "Sim" : "Nao") << endl;
	}
}
