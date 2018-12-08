#pragma once
#ifndef  ENTRADA_E_SAIDA_H
#define ENTRADA_E_SAIDA_H

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class EntradaESaida
{
public:
	static string formatarSeparadorNumero(string numero);
	static float stringParaFloat(string str);
	static int stringParaInt(string str);
	static void exibirFalhaDeImportacao(const char * tipoDeArquivo);
	static void exibirImportacao();
	static void exibirMenu();
	static void exibirMenuPesquisar();
	static void exibirMenuRelatorio();

private:
};


#endif // ! ENTRADA_E_SAIDA_H



