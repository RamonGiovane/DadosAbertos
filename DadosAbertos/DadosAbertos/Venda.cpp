#include "Venda.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
string Venda::getTipoTitulo(){
	return tipoTitulo;
}

string Venda::getDataVenda(){
	return dataVenda;
}

string Venda::getVencimentoTitulo(){
	return vencimentoTitulo;
}

float Venda::getPrecoUnitario(){
	return precoUnitario;
}

float Venda::getQuantidade(){
	return quantidade;
}

float Venda::getValor(){
	return valor;
}

void Venda::setTipoTitulo(string tipoTitulo){
	this->tipoTitulo = tipoTitulo;
}

void Venda::setDataVenda(string dataVenda){
	this->dataVenda = dataVenda;
}

void Venda::setVencimentoTitulo(string vencimentoTitulo){
	this->vencimentoTitulo = vencimentoTitulo;
}

void Venda::setQuantidade(float quantidade){
	this->quantidade = quantidade;
}

void Venda::setPrecoUnitario(float precoUnitario){
	this->precoUnitario = precoUnitario;
}

void Venda::setValor(float valor){
	this->valor = valor;
}

string Venda::toString(){
	char texto[250];
	sprintf_s(texto, 250, "\nTipo Título: %s\nVencimento do Título : %s\nData da Venda: %s"\
		"\nPreço Unitário: %.2f\nQuantidade: %.2f\nValor: %.2f", tipoTitulo.c_str(),
		dataVenda.c_str(), vencimentoTitulo.c_str(), precoUnitario, quantidade, valor);
	return texto;

}

Venda::Venda(){
	
	tipoTitulo = "NULL";
	dataVenda = "NULL";
	vencimentoTitulo = "NULL";
	precoUnitario = 0;
	quantidade = 0;
	valor = 0;
}


/*Construtor sobrecarregado que instancia um objeto venda com os parâmteros contidos dentro de uma string no formato do arquivo de vendas*/
Venda::Venda(string atributos){
	int contador = 1;
	string token;
	istringstream iss(atributos);
	cout << token << endl;
	cout << endl << token;	
	while (getline(iss, token, ';')) {

		switch (contador) {
		case 1: setTipoTitulo(token); break;
		case 2: setVencimentoTitulo(token); break;
		case 3: setDataVenda(token); break;
		case 4: setPrecoUnitario(stof((token))); break;
		case 5: setQuantidade(stof(token)); break;
		case 6: setValor(stof(token)); break;
		default: break;

		}

		contador++;
	}
}

Venda::Venda(string tipoTitulo, string dataVenda, string vencimentoTitulo,
	float precoUnitario, float quantidade, float valor){
	this->tipoTitulo = tipoTitulo;
	this->dataVenda = dataVenda;
	this->vencimentoTitulo = vencimentoTitulo;
	this->precoUnitario = precoUnitario;
	this->quantidade = quantidade;
	this->valor = valor;
}

Venda::~Venda() {

}

