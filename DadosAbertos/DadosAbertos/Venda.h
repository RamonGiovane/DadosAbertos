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
	
	/*Enumeração que guarda os tipos de título do tesouro direto. Como o tipo do título no objeto Venda 
	é um atributo definido como int na tentativa de economizar a memória utilizada para armazená-lo, a enumeração é
	necessária como´os valores a serem setados no atributo*/
	enum TiposTesouroDireto { PREFIXADO = 1, IGPM = 2, SELIC = 3, IPCA = 4, IPCA_JUROS = 5, PREFIXADO_JUROS = 6 };

	
	/*Constantes que representam os tipos de título em string, usadas para futuras conversões dos valores inteiros*/
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

