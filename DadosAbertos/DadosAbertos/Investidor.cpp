#include "Investidor.h"
#include <sstream>
#include "EntradaESaida.h"
/*Construtor padrão que incializa todos os atributos com valores nulos, caso deseje-se realizar chamadas 
menores (com menos parâmetros)ao construtor. Pode ser útil para representar um objeto nulo ou vazio.
ATENÇÃO: Ao usá-lo, os atributos DEVEM ser setados com valores consistentes posteriormente*/
Investidor::Investidor() {
	codigoInvestidor = "NULL";
	idade = 0;
	
	estadoCivil = "NULL", profissao = "NULL",
		cidadeInvestidor = "NULL", paisInvestidor = "NULL";
	genero = '?';
	

}

/*Construtor sobrecarregado com onde todos os atributos de um Investidor podem ser passados por prâmetro*/
Investidor::Investidor(string codigoInvestidor, int idade, string dataAdesao, string estadoCivil,
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

void Investidor::setEstadoCivil(string estadoCivil){
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

string Investidor::toString(){
	char texto[250];
	string genero, operacaoRecente;
	
	if (this->genero == 'M')
		genero = "Masculino";
	else if (this->genero == 'F')
		genero = "Feminino";
	else
		genero = "Indefinido";

	if (this->operacaoRecente)
		operacaoRecente = "Sim";
	else
		operacaoRecente = "Não";


	sprintf_s(texto, 250, "Código %s\tData de Adesão: %s\nIdade: %d\tEstado Civil: %s\nCidade: %s\tPaís: %s\n\
					Profissão: %s\nGênero: %s, Operou nos Últimos 12 Meses? %s ", 
			codigoInvestidor.c_str(), dataAdesao.c_str(), idade, estadoCivil.c_str(), cidadeInvestidor.c_str(),
		paisInvestidor.c_str(), profissao.c_str(), genero.c_str(), operacaoRecente.c_str());
	return texto;
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
			case 3: investidor.setEstadoCivil(token); break;
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
