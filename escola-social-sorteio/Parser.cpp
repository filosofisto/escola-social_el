#include "pch.h"
#include "Parser.h"


Parser::Parser(ConsoleColor& cc): cc(cc)
{
}


Parser::~Parser()
{
}

vector<Inscricao>* Parser::parseFile(const char * filename)
{
	cc.set(ConsoleColor::Color::LIGHT_YELLOW);
	cout << "Realizando parse do arquivo CVS..." << endl;

	ifstream fin(filename);
	if (!fin) {
		throw ParserException();
	}

	bool firstline = true;
	string line, word;

	while (getline(fin, line)) {
		if (firstline) {
			firstline = false;
			continue;
		}

		stringstream ss(line);
		int col = 0;
		Inscricao i;
		while (getline(ss, word, ',')) {
			col++;
			fill(i, col, word);
		}

		inscricoes.push_back(i);
		//cout << i.toStringMainFields() << endl;
	}

	fin.close();

	cout << "Parse realizado com sucesso" << endl;

	return &inscricoes;
}

void Parser::fill(Inscricao& i, int col, string& word)
{
	string trim_word = StringHelper::trim(word);

	switch (col) {
	case 1:
		i.setCodigoLigacao(trim_word);
		break;
	case 2:
		i.setDataAtendimento(trim_word);
		break;
	case 3:
		i.setCadastroUnico(trim_word);
		break;
	case 4:
		i.setStatusLigacao(trim_word);
		break;
	case 5:
		i.setNomeCidadao(trim_word);
		break;
	case 6:
		i.setTelefonePrincipal(trim_word);
		break;
	case 7:
		i.setTelefoneCelular(trim_word);
		break; 
	case 8:
		i.setTelefoneRecado(trim_word);
		break;
	case 9:
		i.setEmail(trim_word);
		break;
	case 10:
		i.setUF(trim_word);
		break;
	case 11:
		i.setCidade(trim_word);
		break;
	case 12:
		i.setBairro(trim_word);
		break;
	case 13:
		// ignore fs Date time
		break;
	case 14:
		i.setDataNascimento(trim_word);
		break;
	case 15:
		i.setCPF(trim_word);
		break;
	case 16:
		i.setNIS(trim_word);
		break;
	case 17:
		i.setNomeInscrito(trim_word);
		break;
	case 18:
		i.setTelefoneParaRetorno(trim_word);
		break;
	case 19:
		i.setNomeMae(trim_word);
		break;
	case 20:
		i.setIdade(trim_word);
		break;
	case 21:
		i.setCategoria(trim_word);
		break;
	case 22:
		i.setCapacitacao(trim_word);
		break;
	case 23:
		i.setMoradorEstrutural(trim_word == "SIM");
		break;
	case 24:
		i.setTelefoneAplicativoMensagensInstantaneas(trim_word);
		break;
	case 25:
		i.setCep(trim_word);
		break;
	case 26:
		i.setRedeSocial(trim_word);
		break;
	case 27:
		i.setAlfabetizado(trim_word == "SIM");
		break;
	case 28:
		i.setEstudando(trim_word == "SIM");
		break;
	case 29:
		i.setGrauInstrucao(trim_word);
		break;
	case 30:
		i.setSituacaoEscolaridade(trim_word);
		break;
	case 31:
		i.setSexo(trim_word);
		break;
	case 32:
		i.setCor(trim_word);
		break;
	case 33:
		i.setRecebeAlgumBeneficioSocial(trim_word == "SIM");
		break;
	case 34:
		i.setBeneficioRecebido(trim_word);
		break;
	case 35:
		// ignore fs email
		break;
	case 36:
		// ignore fs participou
		break;
	case 37:
		// ignore fs primary inscricao
		break;
	case 38:
		// ignore fs rg
		break;
	case 39:
		// ignore fs internet
		break;
	case 40:
		i.setObservacoes(trim_word);
		break;
	}
}