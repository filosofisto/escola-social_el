#pragma once

#include <string>
#include <iostream>
#include <sstream>

using namespace std;

class Inscricao
{
public:
	Inscricao();
	~Inscricao();

	string getCodigoLigacao() const;
	string getDataAtendimento() const;
	string getCanalInscricao() const;
	string getNomeCadastroUnico() const;
	string getStatusLigacao() const;
	string getTelefonePrincipal() const;
	string getTelefoneRecado() const;
	string getEmailCadastroUnico() const;
	string getUF() const;
	string getCidadeRegiaoAdministrativa() const;
	string getCPF() const;
	string getNome() const;
	string getRG() const;
	string getTelefoneParaRetorno() const;
	string getNomeMae() const;
	string getDataNascimento() const;
	string getIdade() const;
	string getCategoria() const;
	string getAreaCapacitacaoDesejada() const;
	string getTelefoneAplicativoMensagensInstantaneas() const;
	string getCep() const;
	string getEndereco() const;
	string getComplemento() const;
	string getEmail() const;
	bool getMoradorEstrutural() const;
	bool getAlfabetizado() const;
	bool getEstudando() const;
	string getGrauInstrucao() const;
	string getSituacaoEscolaridade() const;
	string getSexo() const;
	string getCor() const;
	bool getRecebeAlgumBeneficioSocial() const;
	string getBeneficioRecebido() const;
	string getNIS() const;
	bool getMoradorAreaRuralDF() const;
	string getObservacoes() const;

	void setCodigoLigacao(const string& codigo_ligacao);
	void setDataAtendimento(const string& data_atendimento);
	void setCanalInscricao(const string& canal_inscricao);
	void setNomeCadastroUnico(const string& nome_cadastro_unico);
	void setStatusLigacao(const string& status_ligacao);
	void setTelefonePrincipal(const string& telefone_principal);
	void setTelefoneRecado(const string& telefone_recado);
	void setEmailCadastroUnico(const string& email_cadastro_unico);
	void setUF(const string& uf);
	void setCidadeRegiaoAdministrativa(const string& cidade_regiao_administrativa);
	void setCPF(const string& cpf);
	void setNome(const string& nome);
	void setRG(const string& rg);
	void setTelefoneParaRetorno(const string& telefone_para_retorno);
	void setNomeMae(const string& nome_mae);
	void setDataNascimento(const string& data_nascimento);
	void setIdade(const string& idade);
	void setCategoria(const string& categoria);
	void setAreaCapacitacaoDesejada(const string& area_capacitacao_desejada);
	void setTelefoneAplicativoMensagensInstantaneas(const string& telefone_aplicativo_mensagens_instantaneas);
	void setCep(const string& cep);
	void setEndereco(const string& endereco);
	void setComplemento(const string& complemento);
	void setEmail(const string& email);
	void setMoradorEstrutural(bool morador_estrutural);
	void setAlfabetizado(bool alfabetizado);
	void setEstudando(bool estudando);
	void setGrauInstrucao(const string& grau_instrucao);
	void setSituacaoEscolaridade(const string& situacao_escolaridade);
	void setSexo(const string& sexo);
	void setCor(const string& cor_raca);
	void setRecebeAlgumBeneficioSocial(bool recebe_algum_beneficio_social);
	void setBeneficioRecebido(const string& beneficio_recebido);
	void setNIS(const string& nis);
	void setMoradorAreaRuralDF(bool morador_area_rural_df);
	void setObservacoes(const string& observacoes);

	string toString() const;
	string toStringMainFields() const;
private:
	string codigo_ligacao;
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
};
