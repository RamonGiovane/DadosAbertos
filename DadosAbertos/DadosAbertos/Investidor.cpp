#include "Investidor.h"
#include <sstream>
#include "EntradaESaida.h"
/*Construtor padrão que incializa todos os atributos com valores nulos, caso deseje-se realizar chamadas 
menores (com menos parâmetros)ao construtor. Pode ser útil para representar um objeto nulo ou vazio.
ATENÇÃO: Ao usá-lo, os atributos DEVEM ser setados com valores consistentes posteriormente*/
Investidor::Investidor() {
	codigoInvestidor = "NULL";
	idade = 0;
	
	estadoCivil = 0, profissao = "NULL",
		cidadeInvestidor = "NULL", paisInvestidor = "NULL";
	genero = '?';
	

}

/*Construtor sobrecarregado com onde todos os atributos de um Investidor podem ser passados por prâmetro*/
Investidor::Investidor(string codigoInvestidor, int idade, string dataAdesao, int estadoCivil,
		string profissao, string cidadeInvestidor, string UFInvestidor, string paisInvestidor,
		string situacaoConta, char genero, bool operacaoRecente) {
	
	this->UFInvestidor = UFInvestidor;
	this->codigoInvestidor = codigoInvestidor;
	this->idade = idade;
	this->dataAdesao = dataAdesao;
	this->estadoCivil = estadoCivil;
	this->profissao = profissao;
	this->cidadeInvestidor = cidadeInvestidor;
	this->paisInvestidor = paisInvestidor;
	this->situacaoConta = situacaoConta;
	this->genero = genero;
	this->operacaoRecente = operacaoRecente;

}


string Investidor::getUFInvestidor(){
	return UFInvestidor;
}

char Investidor::getGenero(){
	return this->genero;
}

bool Investidor::isOperacaoRecente() {
	return operacaoRecente;
}

int Investidor::getIdade(){
	return idade;
}

string Investidor::getCodigoInvestidor(){
	return codigoInvestidor;
}

string Investidor::getSituacaoConta() {
	return situacaoConta;
}

string Investidor::obterGenero(char genero) {
	if (genero == 'M')
		return "Masculino";
	if (genero == 'F')
		return "Feminino";
	return "Indefinido";
}

string Investidor::obterEstadoCivil(int estadoCivil){
	Investidor investidor;
	switch (estadoCivil) {
	case SOLTEIRO:
		return investidor.SOLTEIRO_STRING;
	case DESQUITADO:
		return investidor.DESQUITADO_STRING;
	case VIUVO:
		return investidor.VIUVO_STRING;
	case DIVORCIADO:
		return investidor.DIVORCIADO_STRING;
	case CASADO_BRASILEIRO:
		return investidor.CASADO_BRASILEIRO_STRING;
	case CASADO_NATURALIZADO:
		return investidor.CASADO_NATURALIZADO_STRING;
	case CASADO_ESTRANGEIRO:
		return investidor.CASADO_ESTRANGEIRO_STRING;
	case UNIAO_ESTAVEL:
		return investidor.UNIAO_ESTAVEL_STRING;
	case SEPARADO:
		return investidor.SEPARADO_STRING;
	case NAO_SE_APLICA:
		return investidor.NAO_SE_APLICA_STRING;
	}
	return "";
		
}

void Investidor::setOperacaoRecente(bool operacaoRecente) {
	this->operacaoRecente = operacaoRecente;
}

void Investidor::setGenero(char genero){
	this->genero = genero;
}

void Investidor::setSituacaoConta(string situacaoConta) {
	this->situacaoConta = situacaoConta;
}


void Investidor::setDataAdesao(string dataAdesao) {
	this->dataAdesao = dataAdesao;
}

void Investidor::setEstadoCivil(int estadoCivil){
	this->estadoCivil = estadoCivil;
}

void Investidor::setProfissao(string profissao){
	this->profissao = profissao;
}

void Investidor::setCidadeInvestidor(string cidadeInvestidor){
	this->cidadeInvestidor = cidadeInvestidor;
}

void Investidor::setPaisInvestidor(string paisInvestidor){
	this->paisInvestidor = paisInvestidor;
}

void Investidor::setCodigoInvestidor(string codigoInvestidor){
	this->codigoInvestidor = codigoInvestidor;
}

void Investidor::setIdade(int idade){
	this->idade = idade;
}

void Investidor::setUFInvestidor(string UFInvestidor){
	this->UFInvestidor = UFInvestidor;
}

string Investidor::getDataAdesao() {
	return dataAdesao;
}

string Investidor::getProfissao(){
	return profissao;
}

string Investidor::getCidadeInvestidor(){
	return cidadeInvestidor;
}

string Investidor::getPaisInvestidor(){
	return paisInvestidor;
}

int Investidor::getEstadoCivil(){
	return estadoCivil;
}

/*Retorna o nome da região do Brasil na qual o estado do investidor pertence*/
string Investidor::obterRegiao() {
	if (UFInvestidor == "MG" || UFInvestidor == "RJ" || UFInvestidor == "SP" || UFInvestidor == "ES")
		return "Sudeste";

	if (UFInvestidor == "RS" || UFInvestidor == "PR" || UFInvestidor == "SC")
		return "Sul";

	if (UFInvestidor == "DF" || UFInvestidor == "GO" || UFInvestidor == "MT" || UFInvestidor == "MS")
		return "Centro-Oeste";

	if (UFInvestidor == "AM" || UFInvestidor == "AP" || UFInvestidor == "AC" || UFInvestidor == "RO" ||
		UFInvestidor == "RR" || UFInvestidor == "PA" || UFInvestidor == "TO")
		return "Norte";

	if (UFInvestidor == "MA" || UFInvestidor == "PI" || UFInvestidor == "BA" || UFInvestidor == "CE" ||
		UFInvestidor == "PE" || UFInvestidor == "RN" || UFInvestidor == "PB" || UFInvestidor == "SE" ||
		UFInvestidor == "AL")
		return "Nordeste";

	return "";
}


string Investidor::toString(){
	char texto[250];
	string operacaoRecente;

	if (this->operacaoRecente)
		operacaoRecente = "Sim";
	else
		operacaoRecente = "Não";


	sprintf_s(texto, 250, "Código %s\tData de Adesão: %s\nIdade: %d\tEstado Civil: %s\nCidade: %s\tPaís: %s\n\
					Profissão: %s\nGênero: %s, Operou nos Últimos 12 Meses? %s ", 
			codigoInvestidor.c_str(), dataAdesao.c_str(), idade, obterEstadoCivil(estadoCivil).c_str(),
		cidadeInvestidor.c_str(), paisInvestidor.c_str(), profissao.c_str(), obterGenero(genero).c_str(), operacaoRecente.c_str());
	return texto;
}

int Investidor::estadoCivilEmInteiro(string estadoCivil) {
	if(estadoCivil == SOLTEIRO_STRING)
		return SOLTEIRO;
	if (estadoCivil == DESQUITADO_STRING)
		return DESQUITADO;
	if (estadoCivil == DIVORCIADO_STRING)
		return DIVORCIADO;
	if (estadoCivil == VIUVO_STRING)
		return VIUVO;
	if (estadoCivil == CASADO_BRASILEIRO_STRING)
		return CASADO_BRASILEIRO;
	if (estadoCivil == CASADO_NATURALIZADO_STRING)
		return CASADO_NATURALIZADO;
	if (estadoCivil == CASADO_ESTRANGEIRO_STRING)
		return CASADO_ESTRANGEIRO;
	if (estadoCivil == UNIAO_ESTAVEL_STRING)
		return UNIAO_ESTAVEL;
	if (estadoCivil == SEPARADO_STRING)
		return SEPARADO;
	else
		return NAO_SE_APLICA;

}

/*Separa os atributos(dados) de um investidor do tesouro direto formatados em uma string e separados por ponto e vírgula (";"),
salvando-os em novo objeto Investidor que será retornado*/
Investidor Investidor::parseInvestidor(string atributos){
		size_t posicao = 0, contador = 1;
		char separador = ';';
		string token;

		Investidor investidor;

		if (atributos.empty())
			return Investidor();

		istringstream iss(atributos);

		while (getline(iss, token, separador)) {

			switch (contador) {
			case 1: investidor.setCodigoInvestidor(token); break;
			case 2: investidor.setDataAdesao(token); break;
			case 3: investidor.setEstadoCivil(investidor.estadoCivilEmInteiro(token)); break;
			case 4: investidor.setGenero(token.c_str()[0]); break;
			case 5: investidor.setProfissao(token); break;
			case 6: investidor.setIdade(EntradaESaida::stringParaInt(token)); break;
			case 7: investidor.setUFInvestidor(token); break;
			case 8: investidor.setCidadeInvestidor(token); break;
			case 9: investidor.setPaisInvestidor(token); break;
			case 10: investidor.setSituacaoConta(token); break;
			case 11: investidor.setOperacaoRecente(token == "S" ? true : false); break;

			default: break;

			}

			contador++;
		}

		return investidor;
	}
