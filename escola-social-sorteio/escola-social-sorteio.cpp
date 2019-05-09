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
#include "ConsoleColor.h"

using namespace std;

int main(int argc, char **argv)
{
	ConsoleColor cc;
	cc.set(ConsoleColor::Color::LIGHT_BLUE);

	ParamsValidator paramsValidator;

	try {
		paramsValidator.valid(argc, argv);
	}
	catch (const ParamsValidationException& e) {
		cc.set(ConsoleColor::Color::LIGHT_RED);
		cerr << "Erro: " << e.what() << endl << "Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		cc.reset();
		return EXIT_FAILURE;
	}
	catch (const FileNotFoundException& e) {
		cc.set(ConsoleColor::Color::LIGHT_RED);
		cerr << "Erro: " << e.what() << endl << "Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		cc.reset();
		return EXIT_FAILURE;
	}
	
	Parser parser(cc);
	vector<Inscricao>* inscricoes;

	try {
		inscricoes = parser.parseFile(argv[1]);
	}
	catch (const ParserException& e) {
		cc.set(ConsoleColor::Color::LIGHT_RED);
		cerr << "Erro: " << e.what() << endl << " Arquivo: " << __FILE__ << ", Linha: " << __LINE__ << endl;
		cc.reset();
		return EXIT_FAILURE;
	}

	cout << "Total de Inscricoes: " << inscricoes->size() << endl;

	RaffleManager raffleManager(cc, inscricoes);
	raffleManager.process();

	cc.reset();

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
