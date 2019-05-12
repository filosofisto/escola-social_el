#include "pch.h"
#include "Report.h"

Report::Report(const string & filename)
{
	out.open(filename);
}

Report::~Report()
{
	out.close();
}

void Report::build(const map<string, vector<Inscricao>*>& mapInscricoes) 
{
	string capacitacao, categoria;
	size_t pos;

	for (auto e : mapInscricoes) {
		pos = e.first.find("/");
		capacitacao = e.first.substr(0, pos);
		if (capacitacao.substr(0, 1) == "\"") {
			capacitacao = e.first.substr(1, pos);
		}
		categoria = e.first.substr(pos + 1);

		for (auto i : *(e.second)) {
			out << capacitacao << "," << categoria << "," << i.getRuffle() << "," << i.getNomeInscrito() << "," << i.getCPF() << endl;
		}
	}
}
