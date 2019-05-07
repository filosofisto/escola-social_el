#include "pch.h"
#include "Parser.h"


Parser::Parser()
{
}


Parser::~Parser()
{
}

vector<Inscricao>* Parser::parseFile(const char * filename)
{
	ifstream fin(filename);
	if (!fin) {
		throw ParserException();
	}

	string line, word;
	const char delim = ',';
	while (getline(fin, line)) {
		stringstream ss(line);
		int col = 0;
		Inscricao i;
		while (getline(ss, word, ',')) {
			col++;
			if (col == 22) {
				// Endereco esta vindo com virgulas e ferra o parser
				// Este break ignora o endereco e demais colunas
				break;
			}
			fill(i, col, word);
		}

		inscricoes.push_back(i);
		cout << i.toStringMainFields() << endl;
	}

	fin.close();

	return &inscricoes;
}

void Parser::fill(Inscricao& i, int col, const string& word)
{

	switch (col) {
	case 1:
		i.setCodigoLigacao(word);
		break;
	case 2:
		i.setDataAtendimento(word);
		break;
	case 3:
		i.setCanalInscricao(word);
		break;
	case 4:
		i.setNomeCadastroUnico(word);
		break;
	case 5:
		i.setStatusLigacao(word);
		break;
	case 6:
		i.setTelefonePrincipal(word);
		break;
	case 7:
		i.setTelefoneRecado(word);
		break;
	case 8:
		i.setEmailCadastroUnico(word);
		break;
	case 9:
		i.setUF(word);
		break;
	case 10:
		i.setCidadeRegiaoAdministrativa(word);
		break;
	case 11:
		i.setCPF(word);
		break;
	case 12:
		i.setNome(word);
		break;
	case 13:
		i.setRG(word);
		break;
	case 14:
		i.setTelefoneParaRetorno(word);
		break;
	case 15:
		i.setNomeMae(word);
		break;
	case 16:
		i.setDataNascimento(word);
		break;
	case 17:
		i.setIdade(word);
		break;
	case 18:
		i.setCategoria(word);
		break;
	case 19:
		i.setAreaCapacitacaoDesejada(word);
		break;
	case 20:
		i.setTelefoneAplicativoMensagensInstantaneas(word);
		break;
	case 21:
		i.setCep(word);
		break;
	case 22:
		i.setEndereco(word);
		break;
	case 23:
		i.setMoradorEstrutural(word == "SIM");
		break;
	case 24:
		i.setAlfabetizado(word == "SIM");
		break;
	case 25:
		i.setEstudando(word == "SIM");
		break;
	case 26:
		i.setGrauInstrucao(word);
		break;
	case 27:
		i.setSituacaoEscolaridade(word);
		break;
	case 28:
		i.setSexo(word);
		break;
	case 29:
		i.setCor(word);
		break;
	case 30:
		i.setRecebeAlgumBeneficioSocial(word == "SIM");
		break;
	case 31:
		i.setBeneficioRecebido(word);
		break;
	case 32:
		i.setNIS(word);
		break;
	case 33:
		i.setMoradorAreaRuralDF(word == "SIM");
		break;
	case 34:
		i.setObservacoes(word);
		break;
	}
}





