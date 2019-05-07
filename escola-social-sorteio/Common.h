#pragma once

#include <string>

using namespace std;

typedef struct {
	string data;
	char codigo_ligacao[10];
	string data_atendimento;
	string canal_inscricao;
	string nome_cadastro_unico;
	string status_ligacao;
	string telefone_principal;
	string telefone_recado;
	string email_cadastro_unico;
	string uf;
	string cidade_regiao_administrativa;
	string cpf;
	string nome;
	string rg;
	string telefone_para_retorno;
	string nome_mae;
	string data_nascimento;
	string idade;
	string categoria;
	string area_capacitacao_desejada;
	string telefone_aplicativo_mensagens_instantaneas;
	string cep;
	string endereco;
	string complemento;
	string email;
	bool morador_estrutural;
	bool alfabetizado;
	bool estudando;
	string grau_instrucao;
	string situacao_escolaridade;
	string sexo;
	string cor_raca;
	bool recebe_algum_beneficio_social;
	string beneficio_recebido;
	string nis;
	bool morador_area_rural_df;
	string observacoes;
} INSCRICAO;

