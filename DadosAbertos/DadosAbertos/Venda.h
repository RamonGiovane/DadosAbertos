#ifndef VENDA_H
#define VENDA_H
#include <string>
using namespace std;
class Venda{
	
public:
	int getTipoTitulo();
	string getDataVenda();
	string getVencimentoTitulo();
	double getPrecoUnitario();
	double getQuantidade();
	double getValor();

	void setTipoTitulo(int tipoTitulo);
	void setDataVenda(string dataVenda);
	void setVencimentoTitulo(string vencimentoTitulo);
	void setQuantidade(double quantidade);
	void setPrecoUnitario(double precoUnitario);
	void setValor(double valor);

	string tipoTituloEmString();
	static string obterTipoTituloEmString(int tipoTitulo);
	string obterDadosPesquisa(bool tipoTitulo = true);
	int tipoTituloEmInteiro(string tipoTitulo);
	string toString();
	static Venda parseVenda(string atributos);
	
	/*Enumera��o que guarda os tipos de t�tulo do tesouro direto. Como o tipo do t�tulo no objeto Venda 
	� um atributo definido como int na tentativa de economizar a mem�ria utilizada para armazen�-lo, a enumera��o �
	necess�ria como�os valores a serem setados no atributo*/
	enum TiposTesouroDireto { PREFIXADO = 1, IGPM = 2, SELIC = 3, IPCA = 4, IPCA_JUROS = 5, PREFIXADO_JUROS = 6 };

	
	/*Constantes que representam os tipos de t�tulo em string, usadas para futuras convers�es dos valores inteiros*/
	 const string PREFIXADO_STRING = "Tesouro Prefixado",
		IGPM_STRING = "Tesouro IGPM+ com Juros Semestrais", SELIC_STRING = "Tesouro Selic",
		IPCA_STRING = "Tesouro IPCA+", IPCA_JUROS_STRING = "Tesouro IPCA+ com Juros Semestrais", 
		PREFIXADO_JUROS_STRING = "Tesouro Prefixado com Juros Semestrais" ;
	
	Venda();
	Venda(int tipoTitulo, string dataVenda, string vencimentoTitulo, 
		double precoUnitario, double quantidade, double valor);
	~Venda();

private:
	int tipoTitulo;
	string dataVenda, vencimentoTitulo;
	double precoUnitario, quantidade, valor;

};


#endif // !VENDA_H

