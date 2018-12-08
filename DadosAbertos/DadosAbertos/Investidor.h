#pragma once
#include <string>
#ifndef INVESTIDOR_H
#define INVESTIDOR_H
//Codigo do Investidor;Data de Adesao;Estado Civil;Genero;Profissao;Idade;UF do Investidor;Cidade do Investidor;Pais do Investidor;Situacao da Conta;Operou 12 Meses
using namespace std;
class Investidor{
public:
	Investidor::Investidor();
	Investidor::Investidor(string codigoInvestidor, int idade, string dataAdesao, string estadoCivil,
		string profissao, string cidadeInvestidor, string paisInvestidor,
		string situacaoConta, char genero, bool operacaoRecente);

	void setOperacaoRecente(bool operacaoRecente);
	void setGenero(char genero);
	void setSituacaoConta(string situacaoConta);
	void setDataAdesao(string dataAdesao);
	void setEstadoCivil(string estadoCivil);
	void setProfissao(string profissao);
	void setCidadeInvestidor(string cidadeInvestidor);
	void setPaisInvestidor(string paisInvestidor);
			
	char getGenero();
	bool isOperacaoRecente();
	string getSituacaoConta();
	string getDataAdesao();
	string getProfissao();
	string getCidadeInvestidor();
	string getPaisInvestidor();
	
	string toString();

private:
	string codigoInvestidor;
	int idade;
	string estadoCivil, profissao, cidadeInvestidor, paisInvestidor, dataAdesao;
	string situacaoConta;
	bool operacaoRecente;
	char genero;
	

};



#endif // !INVESTIDOR_H
