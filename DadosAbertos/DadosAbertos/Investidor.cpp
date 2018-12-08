#include "Investidor.h"
/*Construtor padr�o que incializa todos os atributos com valores nulos, caso deseje-se realizar chamadas menores (com menos par�metros)
ao construtor. Pode ser �til para representar um objeto nulo ou vazio.
ATEN��O: Ao us�-lo, os atributos DEVEM ser setados com valores consistentes posteriormente*/
Investidor::Investidor() {
	codigoInvestidor = "NULL";
	idade = 0;
	
	estadoCivil = "NULL", profissao = "NULL",
		cidadeInvestidor = "NULL", paisInvestidor = "NULL";
	genero = '?';
	

}

/*Construtor sobrecarregado com onde todos os atributos de um Investidor podem ser passados por pr�metro*/
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
		operacaoRecente = "N�o";


	sprintf_s(texto, 250, "C�digo %s\tData de Ades�o: %s\nIdade: %d\tEstado Civil: %s\nCidade: %s\tPa�s: %s\n\
					Profiss�o: %s\nG�nero: %s, Operou nos �ltimos 12 Meses? %s ", 
			codigoInvestidor.c_str(), dataAdesao.c_str(), idade, estadoCivil.c_str(), cidadeInvestidor.c_str(),
		paisInvestidor.c_str(), profissao.c_str(), genero.c_str(), operacaoRecente.c_str());
	return texto;
}