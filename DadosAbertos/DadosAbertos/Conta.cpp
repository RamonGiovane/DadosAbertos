#include "Conta.h"
bool Conta::isOperacaoRecente() {
	return operacaoRecente;
}

string Conta::getSituacaoConta(){
	return situacaoConta;
}

void Conta::setOperacaoRecente(bool operacaoRecente){
	this->operacaoRecente = operacaoRecente;
}

void Conta::setSituacaoConta(string situacaoConta){
	this->situacaoConta = situacaoConta;
}
/*
void Conta::setInvestidor(Investidor investidor){
	this->investidor = investidor;
}

Investidor Conta::getInvestidor(){
	return investidor;
}*/

void Conta::setDataAdesao(string dataAdesao){
	this->dataAdesao = dataAdesao;
}

string Conta::getDataAdesao(){
	return dataAdesao;
}
