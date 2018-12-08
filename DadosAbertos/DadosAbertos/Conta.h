#pragma once
#ifndef CONTA_H
#define CONTA_H
#include <string>

using namespace std;
class Conta{
public:
	Conta();
	Conta::Conta(bool operacaoRecente, string situacaoConta, string dataAdesao);
	~Conta();

	bool isOperacaoRecente();
	string getSituacaoConta();
	string getDataAdesao();
	void setOperacaoRecente(bool operacaoRecente);
	void setSituacaoConta(string situacaoConta);
	void setDataAdesao(string dataAdesao);
	//void setInvestidor(Investidor investidor);

private:
	string dataAdesao, situacaoConta;
	bool operacaoRecente;
	//Investidor investidor;
	//Investidor getInvestidor();
};

Conta::Conta(){
	dataAdesao = "NULL", situacaoConta = "NULL", operacaoRecente = false;
	//investidor = Investidor();
}
Conta::Conta(bool operacaoRecente, string situacaoConta, string dataAdesao) {
	this->dataAdesao = dataAdesao;
	this->situacaoConta = situacaoConta;
	this->operacaoRecente = operacaoRecente;
	//this->investidor = investidor;
}
Conta::~Conta(){
}
#endif // !CONTA_H
