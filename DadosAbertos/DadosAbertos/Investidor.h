#pragma once
#include <string>
#ifndef INVESTIDOR_H
#define INVESTIDOR_H

using namespace std;
class Investidor{
public:
	Investidor::Investidor();
	Investidor(string codigoInvestidor, int idade, string dataAdesao, int estadoCivil, string profissao, string cidadeInvestidor, string UFInvestidor, string paisInvestidor, string situacaoConta, char genero, bool operacaoRecente);
	Investidor::Investidor(string codigoInvestidor, int idade, string dataAdesao, string estadoCivil,
		string profissao, string cidadeInvestidor, string UFInvestidor, string paisInvestidor,
		string situacaoConta, char genero, bool operacaoRecente);
	
	enum EstadoCivil{SOLTEIRO = 1, DESQUITADO = 2, VIUVO = 3, DIVORCIADO = 4, CASADO_BRASILEIRO = 5,
		CASADO_NATURALIZADO = 6, CASADO_ESTRANGEIRO = 7, UNIAO_ESTAVEL = 8, SEPARADO = 9, NAO_SE_APLICA = 10};

	enum Regioes { NORTE = 1, NORDESTE = 2, CENTRO_OESTE = 3, SUL = 4, SUDESTE = 5 };

	void setOperacaoRecente(bool operacaoRecente);
	void setGenero(char genero);
	void setSituacaoConta(string situacaoConta);
	void setDataAdesao(string dataAdesao);
	void setEstadoCivil(int estadoCivil);
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
	int getEstadoCivil();

	string obterRegiao();
	
	string toString();
	int estadoCivilEmInteiro(string estadoCivil);

	static Investidor parseInvestidor(string atributos);
	static string obterGenero(char genero);
	static string obterEstadoCivil(int estadoCivil);

private:
	string codigoInvestidor;
	int idade, estadoCivil;
	string profissao, cidadeInvestidor, UFInvestidor, paisInvestidor, dataAdesao;
	string situacaoConta;
	bool operacaoRecente;
	char genero;

	//Strings constantes que guardam os tipos de estado civl 
	const string
		SOLTEIRO_STRING = "Solteiro(a)", DESQUITADO_STRING = "Desquitado(a)", VIUVO_STRING = "Viúvo(a)",
		DIVORCIADO_STRING = "Divorciado(a)", CASADO_BRASILEIRO_STRING = "Casado(a) com brasileiro(a) nato(a)",
		CASADO_NATURALIZADO_STRING = "Casado(a) com brasileiro(a) naturalizado(a)",
		CASADO_ESTRANGEIRO_STRING = "Casado(a) com estrangeiro(a)", UNIAO_ESTAVEL_STRING = "União estável",
		SEPARADO_STRING = "Separado judic.", NAO_SE_APLICA_STRING = "Não se aplica";

	
};



#endif // !INVESTIDOR_H
