// escola-social-sorteio.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "ParamsValidator.h"
#include "ParamsValidationException.h"
#include "Parser.h"
#include "ParserException.h"
#include "Logger.h"
#include "ConsoleLogger.h"
#include "Inscricao.h"
#include "RaffleManager.h"

using namespace std;

int main(int argc, char **argv)
{
	Logger* log = new ConsoleLogger("SORTEIO");
	log->set_level(Logger::Level::INFO);
	//log->info(__FILE__, __LINE__, "Fabrica Social - Sorteio de Inscricoes");

	ParamsValidator paramsValidator;

	try {
		paramsValidator.valid(argc, argv);
	}
	catch (const ParamsValidationException& e) {
		cerr << "Erro: " << e.what() << " - Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		delete log;
		return EXIT_FAILURE;
	}
	catch (const FileNotFoundException& e) {
		cerr << "Erro: " << e.what() << " - Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		delete log;
		return EXIT_FAILURE;
	}
	
	Parser parser;
	vector<Inscricao>* inscricoes;

	try {
		inscricoes = parser.parseFile(argv[1]);
	}
	catch (const ParserException& e) {
		cerr << "Erro: " << e.what() << " - Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		delete log;
		return EXIT_FAILURE;
	}

	cout << "Total de Inscricoes: " << inscricoes->size() << endl;
	cout << "1. Organizando o sorteio por Categoria e Area de Capacitacao" << endl;

	RaffleManager raffleManager(inscricoes);
	raffleManager.process();

	delete log;

	cout << "Processamento realizado cmo sucesso" << endl;

	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
