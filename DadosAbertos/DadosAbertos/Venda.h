#ifndef VENDA_H
#define VENDA_H
#include <string>
using namespace std;
class Venda{
	
public:
	int getTipoTitulo();
	string getDataVenda();
	string getVencimentoTitulo();
	float getPrecoUnitario();
	float getQuantidade();
	float getValor();

	void setTipoTitulo(int tipoTitulo);
	void setDataVenda(string dataVenda);
	void setVencimentoTitulo(string vencimentoTitulo);
	void setQuantidade(float quantidade);
	void setPrecoUnitario(float precoUnitario);
	void setValor(float valor);

	string tipoTituloEmString();
	int tipoTituloEmInteiro(string tipoTitulo);
	string toString();
	static Venda parseVenda(string atributos);
	
	/*Enumeração que guarda os tipos de título do tesouro direto. Como o tipo do título no objeto Venda 
	é um atributo definido como int na tentativa de economizar a memória utilizada para armazená-lo, a enumeração é
	necessária como´os valores a serem setados no atributo*/
	enum TiposTesouroDireto { PREFIXADO, IGPM, SELIC, IPCA, IPCA_JUROS, PREFIXADO_JUROS };

	
	/*Constantes que representam os tipos de título em string, usadas para futuras conversões dos valores inteiros*/
	const string PREFIXADO_STRING = "Tesouro Prefixado", 
		IGPM_STRING = "Tesouro IGPM+ com Juros Semestrais", SELIC_STRING = "Tesouro Selic",
		IPCA_STRING = "Tesouro IPCA+", IPCA_JUROS_STRING = "Tesouro IPCA+ com Juros Semestrais", 
		PREFIXADO_JUROS_STRING = "Tesouro Prefixado com Juros Semestrais" ;
	
	Venda();
	Venda(int tipoTitulo, string dataVenda, string vencimentoTitulo, 
		float precoUnitario, float quantidade, float valor);
	~Venda();

private:
	int tipoTitulo;
	string dataVenda, vencimentoTitulo;
	float precoUnitario, quantidade, valor;

};


#endif // !VENDA_H

