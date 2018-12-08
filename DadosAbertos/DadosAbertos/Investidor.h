#pragma once
#include <string>
#ifndef INVESTIDOR_H
#define INVESTIDOR_H

using namespace std;
class Investidor{
public:
	Investidor::Investidor();
	Investidor::Investidor(string codigoInvestidor, int idade, string dataAdesao, string estadoCivil,
		string profissao, string cidadeInvestidor, string UFInvestidor, string paisInvestidor,
		string situacaoConta, char genero, bool operacaoRecente);
	
	void setOperacaoRecente(bool operacaoRecente);
	void setGenero(char genero);
	void setSituacaoConta(string situacaoConta);
	void setDataAdesao(string dataAdesao);
	void setEstadoCivil(string estadoCivil);
	void setProfissao(string profissao);
	void setCidadeInvestidor(string cidadeInvestidor);
	void setPaisInvestidor(string paisInvestidor);
	void setCodigoInvestidor(string codigoInvestidor);
	void setIdade(int idade);
	void setUFInvestidor(string UFInvestidor);
			
	string getUFInvestidor();
	char getGenero();
	bool isOperacaoRecente();
	int getIdade();
	string getCodigoInvestidor();
	string getSituacaoConta();
	string getDataAdesao();
	string getProfissao();
	string getCidadeInvestidor();
	string getPaisInvestidor();
	
	string toString();
	static Investidor parseInvestidor(string atributos);

private:
	string codigoInvestidor;
	int idade;
	string estadoCivil, profissao, cidadeInvestidor, UFInvestidor, paisInvestidor, dataAdesao;
	string situacaoConta;
	bool operacaoRecente;
	char genero;
	

};



#endif // !INVESTIDOR_H
