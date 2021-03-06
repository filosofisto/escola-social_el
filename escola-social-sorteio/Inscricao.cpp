#include "pch.h"
#include "Inscricao.h"


Inscricao::Inscricao()
{
	setRuffle(0);
}


Inscricao::~Inscricao()
{
}

string Inscricao::getCodigoLigacao() const
{
	return this->codigo_ligacao;
}

string Inscricao::getDataAtendimento() const
{
	return this->data_atendimento;
}

string Inscricao::getCanalInscricao() const
{
	return this->canal_inscricao;
}

string Inscricao::getCadastroUnico() const
{
	return cadastro_unico;
}

string Inscricao::getNomeCidadao() const
{
	return this->nome_cidadao;
}

string Inscricao::getStatusLigacao() const
{
	return this->status_ligacao;
}

string Inscricao::getTelefonePrincipal() const
{
	return this->telefone_principal;
}

string Inscricao::getTelefoneCelular() const
{
	return telefone_celular;
}

string Inscricao::getTelefoneRecado() const
{
	return this->telefone_recado;
}

string Inscricao::getEmailCadastroUnico() const
{
	return this->email_cadastro_unico;
}

string Inscricao::getUF() const
{
	return this->uf;
}

string Inscricao::getCidade() const
{
	return this->cidade;
}

string Inscricao::getCPF() const
{
	return this->cpf;
}

string Inscricao::getNomeInscrito() const
{
	return this->nome_inscrito;
}

string Inscricao::getRG() const
{
	return this->rg;
}

string Inscricao::getTelefoneParaRetorno() const
{
	return this->telefone_para_retorno;
}

string Inscricao::getNomeMae() const
{
	return this->nome_mae;
}

string Inscricao::getDataNascimento() const
{
	return this->data_nascimento;
}

string Inscricao::getIdade() const
{
	return this->idade;
}

string Inscricao::getCategoria() const
{
	return this->categoria;
}

string Inscricao::getCapacitacao() const
{
	return this->capacitacao;
}

string Inscricao::getTelefoneAplicativoMensagensInstantaneas() const
{
	return this->telefone_aplicativo_mensagens_instantaneas;
}

string Inscricao::getCep() const
{
	return this->cep;
}

string Inscricao::getEndereco() const
{
	return this->endereco;
}

string Inscricao::getComplemento() const
{
	return this->complemento;
}

string Inscricao::getEmail() const
{
	return this->email;
}

bool Inscricao::getMoradorEstrutural() const
{
	return this->morador_estrutural;
}

int Inscricao::getMoradorEstruturalAsInt() const
{
	if (getMoradorEstrutural()) {
		return 0;
	}
	else {
		return 1;
	}
}

bool Inscricao::operator<(const Inscricao & i2) const
{
	//return getRuffle() - i2.getRuffle();
	if (getRuffle() < i2.getRuffle()) {
		return true;
	}
	else {
		return false;
	}
}

bool Inscricao::getAlfabetizado() const
{
	return this->alfabetizado;
}

bool Inscricao::getEstudando() const
{
	return this->estudando;
}

string Inscricao::getGrauInstrucao() const
{
	return this->grau_instrucao;
}

string Inscricao::getSituacaoEscolaridade() const
{
	return this->situacao_escolaridade;
}

string Inscricao::getSexo() const
{
	return this->sexo;
}

string Inscricao::getCor() const
{
	return this->cor_raca;
}

bool Inscricao::getRecebeAlgumBeneficioSocial() const
{
	return this->recebe_algum_beneficio_social;
}

string Inscricao::getBeneficioRecebido() const
{
	return this->beneficio_recebido;
}

string Inscricao::getNIS() const
{
	return this->nis;
}

bool Inscricao::getMoradorAreaRuralDF() const
{
	return this->morador_area_rural_df;
}

string Inscricao::getObservacoes() const
{
	return this->observacoes;
}

int Inscricao::getRuffle() const
{
	return this->ruffle;
}

string Inscricao::getRedeSocial() const
{
	return rede_social;
}

void Inscricao::setCodigoLigacao(const string& codigo_ligacao)
{
	this->codigo_ligacao.assign(codigo_ligacao);
}

void Inscricao::setDataAtendimento(const string & data_atendimento)
{
	this->data_atendimento.assign(data_atendimento);
}

void Inscricao::setCadastroUnico(const string & cadastro_unico)
{
	this->cadastro_unico = cadastro_unico;
}

void Inscricao::setCanalInscricao(const string& canal_inscricao) {
	this->canal_inscricao.assign(canal_inscricao);
}

void Inscricao::setNomeCidadao(const string & nome_cidadao)
{
	this->nome_cidadao.assign(nome_cidadao);
}

void Inscricao::setStatusLigacao(const string & status_ligacao)
{
	this->status_ligacao.assign(status_ligacao);
}

void Inscricao::setTelefonePrincipal(const string & telefone_principal)
{
	this->telefone_principal.assign(telefone_principal);
}

void Inscricao::setTelefoneCelular(const string & telefone_celular)
{
	this->telefone_celular.assign(telefone_celular);
}

void Inscricao::setTelefoneRecado(const string & telefone_recado)
{
	this->telefone_recado.assign(telefone_recado);
}

void Inscricao::setEmailCadastroUnico(const string & email_cadastro_unico)
{
	this->email_cadastro_unico.assign(email_cadastro_unico);
}

void Inscricao::setUF(const string & uf)
{
	this->uf.assign(uf);
}

void Inscricao::setCidade(const string & cidade)
{
	this->cidade.assign(cidade);
}

void Inscricao::setBairro(const string & bairro)
{
	this->bairro.assign(bairro);
}

void Inscricao::setCPF(const string & cpf)
{
	this->cpf.assign(cpf);
}

void Inscricao::setNomeInscrito(const string & nome_inscrito)
{
	this->nome_inscrito.assign(nome_inscrito);
}

void Inscricao::setRG(const string & rg)
{
	this->rg.assign(rg);
}

void Inscricao::setTelefoneParaRetorno(const string & telefone_para_retorno)
{
	this->telefone_para_retorno.assign(telefone_principal);
}

void Inscricao::setNomeMae(const string & nome_mae)
{
	this->nome_mae.assign(nome_mae);
}

void Inscricao::setDataNascimento(const string & data_nascimento)
{
	this->data_nascimento.assign(data_nascimento);
}

void Inscricao::setIdade(const string & idade)
{
	this->idade.assign(idade);
}

void Inscricao::setCategoria(const string & categoria)
{
	this->categoria.assign(categoria);
}

void Inscricao::setCapacitacao(const string & capacitacao)
{
	this->capacitacao.assign(capacitacao);
}

void Inscricao::setTelefoneAplicativoMensagensInstantaneas(const string & telefone_aplicativo_mensagens_instantaneas)
{
	this->telefone_aplicativo_mensagens_instantaneas.assign(telefone_aplicativo_mensagens_instantaneas);
}

void Inscricao::setCep(const string & cep)
{
	this->cep.assign(cep);
}

void Inscricao::setEndereco(const string & endereco)
{
	this->endereco.assign(endereco);
}

void Inscricao::setComplemento(const string & complemento)
{
	this->complemento.assign(complemento);
}

void Inscricao::setEmail(const string & email)
{
	this->email.assign(email);
}

void Inscricao::setMoradorEstrutural(bool morador_estrutural)
{
	this->morador_estrutural = morador_estrutural;
}

void Inscricao::setAlfabetizado(bool alfabetizado)
{
	this->alfabetizado = alfabetizado;
}

void Inscricao::setEstudando(bool estudando)
{
	this->estudando = estudando;
}

void Inscricao::setGrauInstrucao(const string & grau_instrucao)
{
	this->grau_instrucao.assign(grau_instrucao);
}

void Inscricao::setSituacaoEscolaridade(const string & situacao_escolaridade)
{
	this->situacao_escolaridade.assign(situacao_escolaridade);
}

void Inscricao::setSexo(const string & sexo)
{
	this->sexo.assign(sexo);
}

void Inscricao::setCor(const string & cor_raca)
{
	this->cor_raca.assign(cor_raca);
}

void Inscricao::setRecebeAlgumBeneficioSocial(bool recebe_algum_beneficio_social)
{
	this->recebe_algum_beneficio_social = recebe_algum_beneficio_social;
}

void Inscricao::setBeneficioRecebido(const string& beneficio_recebido)
{
	this->beneficio_recebido = beneficio_recebido;
}

void Inscricao::setNIS(const string & nis)
{
	this->nis.assign(nis);
}

void Inscricao::setMoradorAreaRuralDF(bool morador_area_rural_df)
{
	this->morador_area_rural_df = morador_area_rural_df;
}

void Inscricao::setObservacoes(const string & observacoes)
{
	this->observacoes.assign(observacoes);
}

void Inscricao::setRuffle(int ruffle)
{
	this->ruffle = ruffle;
}

void Inscricao::setRedeSocial(const string & rede_social)
{
	this->rede_social.assign(rede_social);
}

string Inscricao::toString() const
{
	stringstream ss;
	ss << "Codigo Ligacao: " << getCodigoLigacao()
		<< ", Data Atendimento: " << getDataAtendimento()
		<< ", Canal de Inscricao: " << getCanalInscricao()
		<< ", Nome Cadastro Unico: " << getNomeCidadao()
		<< ", Status Ligacao: " << getStatusLigacao()
		<< ", Telefone Principal: " << getTelefonePrincipal()
		<< ", Telefone Recado: " << getTelefoneRecado()
		<< ", Email Cadastro Unico: " << getEmailCadastroUnico()
		<< ", UF: " << getUF()
		<< ", Cidade/Regiao Admin: " << getCidade()
		<< ", CPF: " << getCPF()
		<< ", Nome Inscrito: " << getNomeInscrito()
		<< ", RG: " << getRG()
		<< ", Telefone para Retorno: " << getTelefoneParaRetorno()
		<< ", Nome da Mae: " << getNomeMae()
		<< ", Data Nascimento: " << getDataNascimento()
		<< ", Idade: " << getIdade()
		<< ", Categoria: " << getCategoria()
		<< ", Area Capacitacao: " << getCapacitacao()
		<< ", Telefone Aplicativo Msg Instantanea: " << getTelefoneAplicativoMensagensInstantaneas()
		<< ", CEP: " << getCep()
		<< ", Endereco: " << getEndereco()
		<< ", Morador Estrutural: " << (getMoradorEstrutural() ? "SIM" : "NAO")
		<< ", Alfabetizado: " << (getAlfabetizado() ? "SIM" : "NAO")
		<< ", Estudante: " << (getEstudando() ? "SIM" : "NAO")
		<< ", Grau de Instrucao: " << getGrauInstrucao()
		<< ", Situacao Escolaridade: " << getSituacaoEscolaridade()
		<< ", Sexo: " << getSexo()
		<< ", Cor/Raca: " << getCor()
		<< ", Recebe algum beneficio: " << getRecebeAlgumBeneficioSocial()
		<< ", Beneficio Recebido: " << getBeneficioRecebido()
		<< ", NIS: " << getNIS()
		<< ", Morador Area Rural DF: " << (getMoradorAreaRuralDF() ? "SIM" : "NAO")
		<< ", Observacoes: " << getObservacoes()
		;

		return ss.str();
}

string Inscricao::toStringMainFields() const
{
	stringstream ss;
	ss	<< "CPF: [" << getCPF() << "]"
		<< ", Nome Inscrito: [" << getNomeInscrito() << "]"
		<< ", Categoria: [" << getCategoria() + "]"
		<< ", Area Capacitacao: [" << getCapacitacao() + "]"
		<< ", Morador Estrutural: [" << (getMoradorEstrutural() ? "SIM" : "NAO") << "]"
		;

	return ss.str();
}

ostream& operator<<(std::ostream& os, const Inscricao& i)
{
	os << i.getCodigoLigacao()
		<< endl;

	return os;
}