#include "Venda.h"
#include "EntradaESaida.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Venda::Venda() {

	tipoTitulo = 0;
	dataVenda = "NULL";
	vencimentoTitulo = "NULL";
	precoUnitario = 0;
	quantidade = 0;
	valor = 0;
}

Venda::Venda(int tipoTitulo, string dataVenda, string vencimentoTitulo,
	double precoUnitario, double quantidade, double valor) {
	this->tipoTitulo = tipoTitulo;
	this->dataVenda = dataVenda;
	this->vencimentoTitulo = vencimentoTitulo;
	this->precoUnitario = precoUnitario;
	this->quantidade = quantidade;
	this->valor = valor;
}

int Venda::getTipoTitulo(){
	return tipoTitulo;
}

string Venda::getDataVenda(){
	return dataVenda;
}

string Venda::getVencimentoTitulo(){
	return vencimentoTitulo;
}

double Venda::getPrecoUnitario(){
	return precoUnitario;
}

double Venda::getQuantidade(){
	return quantidade;
}

double Venda::getValor(){
	return valor;
}

void Venda::setTipoTitulo(int tipoTitulo){
	this->tipoTitulo = tipoTitulo;
}

void Venda::setDataVenda(string dataVenda){
	this->dataVenda = dataVenda;
}

void Venda::setVencimentoTitulo(string vencimentoTitulo){
	this->vencimentoTitulo = vencimentoTitulo;
}

void Venda::setQuantidade(double quantidade){
	this->quantidade = quantidade;
}

void Venda::setPrecoUnitario(double precoUnitario){
	this->precoUnitario = precoUnitario;
}

void Venda::setValor(double valor){
	this->valor = valor;
}

/*Retorna o tipo de do título do tesouro direto do objeto atual em string*/
string Venda::tipoTituloEmString() {
	switch (tipoTitulo) {
	case PREFIXADO:
		return PREFIXADO_STRING;
	case IGPM:
		return IGPM_STRING;
	case SELIC:
		return SELIC_STRING;
	case IPCA:
		return IPCA_STRING;
	case IPCA_JUROS:
		return IPCA_JUROS_STRING;
	case PREFIXADO_JUROS:
		return PREFIXADO_JUROS_STRING;
	}

	return "Outro";
}

string Venda::obterTipoTituloEmString(int tipoTitulo) {
	Venda v;
	switch (tipoTitulo) {
	case PREFIXADO:
		return v.PREFIXADO_STRING;
	case IGPM:
		return v.IGPM_STRING;
	case SELIC:
		return v.SELIC_STRING;
	case IPCA:
		return v.IPCA_STRING;
	case IPCA_JUROS:
		return v.IPCA_JUROS_STRING;
	case PREFIXADO_JUROS:
		return v.PREFIXADO_JUROS_STRING;
	}

	return "Outro";
}

/*Retorna uma string com dados apenas dados de pesquisa. 
Recebe como parâmtero <tipoTitulo>, variável booleana que define se o tipo do título do tesouro direto será
omitido ou não*/
string Venda::obterDadosPesquisa(bool tipoTitulo) {
	char dados[300];
	sprintf_s(dados, 300, "\nData de Vencimento: %s\nQuantidade: %.2f\nValor total: %.2f\n",
		vencimentoTitulo.c_str(), quantidade, valor);
	return (tipoTitulo) ? "\nTipo de Título: " + tipoTituloEmString() + dados : dados;
}

int Venda::tipoTituloEmInteiro(string tipoTitulo){
	if (tipoTitulo == IGPM_STRING)
		return IGPM;
	if (tipoTitulo == SELIC_STRING)
		return SELIC;
	if (tipoTitulo == PREFIXADO_STRING)
		return PREFIXADO;
	if (tipoTitulo == PREFIXADO_JUROS_STRING)
		return PREFIXADO_JUROS;
	if (tipoTitulo == IPCA_STRING)
		return IPCA;
	if (tipoTitulo == IPCA_JUROS_STRING)
		return IPCA_JUROS;
	return -1;
}

/*Converte os atributos de um objeto Venda em uma string formatada*/
string Venda::toString(){
	string tipoTitulo = tipoTituloEmString();
	char texto[250];
	sprintf_s(texto, 250, "\nTipo Título: %s\nVencimento do Título : %s\nData da Venda: %s"\
		"\nPreço Unitário: %.2f\nQuantidade: %.2f\nValor: %.2f", tipoTitulo.c_str(),
		dataVenda.c_str(), vencimentoTitulo.c_str(), precoUnitario, quantidade, valor);
	return texto;

}

/*Separa os atributos(dados) de uma venda do tesouro direto formatados em uma string e separados por ponto e vírgula (";"), 
salvando-os em novo objeto Venda que será retornado*/
Venda Venda::parseVenda(string atributos){
		size_t posicao = 0, contador = 1;
		char separador = ';';
		string token;

		Venda venda;

		if (atributos.empty())
			return Venda();

		istringstream iss(atributos);

		while (getline(iss, token, separador)) {

			switch (contador) {
			case 1: venda.setTipoTitulo(venda.tipoTituloEmInteiro(token)); break;
			case 2: venda.setVencimentoTitulo(token); break;
			case 3: venda.setDataVenda(token); break;
			case 4: venda.setPrecoUnitario(stod(EntradaESaida::formatarSeparadorNumero(token))); break;
			case 5: venda.setQuantidade(stod(EntradaESaida::formatarSeparadorNumero(token))); break;
			case 6: venda.setValor(stod(EntradaESaida::formatarSeparadorNumero(token))); break;
			default: break;

			}

			contador++;
		}

		return venda;
}

Venda::~Venda() {

}

