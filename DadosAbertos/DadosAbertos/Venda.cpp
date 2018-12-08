#include "Venda.h"
#include "EntradaESaida.h"
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

/*Retorna o tipo de do t�tulo do tesouro direto do objeto atual em string*/
string tipoTituloEmString() {
	return "";
}

/*Converte os atributos de um objeto Venda em uma string formatada*/
string Venda::toString(){
	string tipoTitulo = tipoTituloEmString();
	char texto[250];
	sprintf_s(texto, 250, "\nTipo T�tulo: %s\nVencimento do T�tulo : %s\nData da Venda: %s"\
		"\nPre�o Unit�rio: %.2f\nQuantidade: %.2f\nValor: %.2f", tipoTitulo.c_str(),
		dataVenda.c_str(), vencimentoTitulo.c_str(), precoUnitario, quantidade, valor);
	return texto;

}

/*Separa os atributos(dados) de uma venda do tesouro direto formatados em uma string e separados por ponto e v�rgula (";"), 
salvando-os em novo objeto Venda que ser� retornado*/
Venda Venda::parseVenda(string atributos){
		size_t posicao = 0, contador = 1;
		char separador = ';';
		string token;

		Venda venda;

		if (atributos.empty())
			return false;

		istringstream iss(atributos);

		while (getline(iss, token, separador)) {

			switch (contador) {
			case 1: venda.setTipoTitulo(token); break;
			case 2: venda.setVencimentoTitulo(token); break;
			case 3: venda.setDataVenda(token); break;
			case 4: venda.setPrecoUnitario(stof(EntradaESaida::formatarSeparadorNumero(token))); break;
			case 5: venda.setQuantidade(stof(EntradaESaida::formatarSeparadorNumero(token))); break;
			case 6: venda.setValor(stof(EntradaESaida::formatarSeparadorNumero(token))); break;
			default: break;

			}

			contador++;
		}

		return venda;
}
	


Venda::Venda(){
	
	tipoTitulo = "NULL";
	dataVenda = "NULL";
	vencimentoTitulo = "NULL";
	precoUnitario = 0;
	quantidade = 0;
	valor = 0;
}


/*Construtor sobrecarregado que instancia um objeto venda com os par�mteros contidos dentro de uma string no formato do arquivo de vendas*/
Venda::Venda(string atributos){
	int contador = 1;
	string token;
	istringstream iss(atributos);
	
	while (getline(iss, token, ';')) {

		switch (contador) {
		case 1: setTipoTitulo(token); break;
		case 2: setVencimentoTitulo(token); break;
		case 3: setDataVenda(token); break;
		case 4: setPrecoUnitario(EntradaESaida::stringParaFloat(token)); break;
		case 5: setQuantidade(EntradaESaida::stringParaFloat(token)); break;
		case 6: setValor(EntradaESaida::stringParaFloat(token)); break;
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

