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
#include "Banner.h"
#include "Out.h"
#include "Report.h"

using namespace std;

int main(int argc, char **argv)
{
	// Ouput (file and console)
	string logname = IOHelper::curdir();
	logname.append("\\log.txt");
	Out out(logname);

	// Console colors
	ConsoleColor cc;
	cc.set(ConsoleColor::Color::LIGHT_BLUE);

	// Banner
	Banner banner(out);
	banner.show();

	// Parameters
	ParamsValidator paramsValidator;

	try {
		paramsValidator.valid(argc, argv);
	}
	catch (const ParamsValidationException& e) {
		cc.set(ConsoleColor::Color::LIGHT_RED);
		out << "Erro: " << e.what() << endl << "Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		cc.reset();
		return EXIT_FAILURE;
	}
	catch (const FileNotFoundException& e) {
		cc.set(ConsoleColor::Color::LIGHT_RED);
		out << "Erro: " << e.what() << endl << "Arquivo: " << __FILE__ << " - Linha: " << __LINE__ << endl;
		cc.reset();
		return EXIT_FAILURE;
	}
	
	// Parser (data import)
	Parser parser(cc);
	vector<Inscricao>* inscricoes;

	try {
		inscricoes = parser.parseFile(argv[1]);
	}
	catch (const ParserException& e) {
		cc.set(ConsoleColor::Color::LIGHT_RED);
		out << "Erro: " << e.what() << endl << " Arquivo: " << __FILE__ << ", Linha: " << __LINE__ << endl;
		cc.reset();
		return EXIT_FAILURE;
	}

	out << "Total de Inscricoes: " << inscricoes->size() << endl;

	// Manager of ruffle
	RaffleManager raffleManager(out, cc, inscricoes);
	map<string, vector<Inscricao>*>& mapInscricoes = raffleManager.process();

	// Report
	string reportFilename = IOHelper::curdir();
	reportFilename.append("\\report.txt");
	Report report(reportFilename);
	report.build(mapInscricoes);

	cc.reset();

	// Executing Java to generate PDF format report
	cc.set(ConsoleColor::Color::LIGHT_YELLOW);
	out << "Acionando programa para gerar relatorio no formato PDF e Planilha com os dados do resultado" << endl;
	cc.reset();
	system("java -jar escola-social-sorteio-relatorio-1.0-SNAPSHOT.jar");

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
