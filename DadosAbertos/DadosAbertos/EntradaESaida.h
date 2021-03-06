#pragma once
#ifndef  ENTRADA_E_SAIDA_H
#define ENTRADA_E_SAIDA_H

#include <iostream>
#include <string>
#include <algorithm>
#include "Venda.h"

using namespace std;
class EntradaESaida
{
public:
	static string formatarSeparadorNumero(string numero);
	static int stringParaInt(string str);
	static double stringParaDouble(string str);
	static void exibirFalhaDeImportacao(const char * tipoDeArquivo);
	static void exibirImportacao();
	static void exibirMenu();
	static void limparTela();
	static void pausarTela();
	static void pausarLimparTela();
	static void exibirSeparador();
	static int lerInteiro();
	static string lerString();
	static int compararDatas(const char * dataA, const char * dataB);
	static int compararDatas(string dataA, string dataB);
	static bool dataEmInteiros(string data, int & dia, int & mes, int & ano);
	static bool validarData(string data);
	static bool validarData(int dia, int mes, int ano);
	static bool lerData(string & data);
	static void exibirMenuPesquisar();
	static void exibirMenuRelatorio();
	static void exibirTitulo(string titulo);
private:
};


#endif // ! ENTRADA_E_SAIDA_H


