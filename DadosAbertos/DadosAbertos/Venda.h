#ifndef VENDA_H
#define VENDA_H
#include <string>
using namespace std;
class Venda{
	
public:
	string getTipoTitulo();
	string getDataVenda();
	string getVencimentoTitulo();
	float getPrecoUnitario();
	float getQuantidade();
	float getValor();

	void setTipoTitulo(string tipoTitulo);
	void setDataVenda(string dataVenda);
	void setVencimentoTitulo(string vencimentoTitulo);
	void setQuantidade(float quantidade);
	void setPrecoUnitario(float precoUnitario);
	void setValor(float valor);
	
	string toString();

	Venda();
	Venda(string atributos);
	Venda(string tipoTitulo, string dataVenda, string vencimentoTitulo, 
		float precoUnitario, float quantidade, float valor);
	~Venda();

private:
	string tipoTitulo, dataVenda, vencimentoTitulo;
	float precoUnitario, quantidade, valor;

};


#endif // !VENDA_H

