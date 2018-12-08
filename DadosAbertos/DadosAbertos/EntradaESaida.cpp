#include "EntradaESaida.h"
#include <iostream>
/*
Remove o uso de pontos (.) para representar n�meros na casa de milhar em n�meros de
ponto flutuante dentro de uma string.
Exemplo de entrada: 1.000,00 -> exemplo de sa�da: 1000,00
Retorna uma string com o novo n�mero formatado
*/
string EntradaESaida::formatarSeparadorNumero(string numero) {
	numero.erase(remove(numero.begin(), numero.end(), '.'));

	return numero;
}

/*Retorna um n�mero do tipo float convertido de string a partir do par�metro <str>*/
float EntradaESaida::stringParaFloat(string str) {
	return stof(EntradaESaida::formatarSeparadorNumero(str));
}

/*Retorna um n�mero do tipo float convertido de string a partir do par�metro <str>*/
int EntradaESaida::stringParaInt(string str) {
	return stoi(EntradaESaida::formatarSeparadorNumero(str));
}


/*Exibe uma mensagem de erro quando � imposs�vel abrir um arquivo*/
void EntradaESaida::exibirFalhaDeImportacao(const char* tipoDeArquivo) {
	cout << "\nN�o foi poss�vel importar os dados de " << tipoDeArquivo << "!\nArquivo corrompido ou inexistente.\n";
}


/*Exibe a mensagem de importa��o quando esta opera��o � solicitada*/
void EntradaESaida::exibirImportacao() {
	cout << "Os dados ser�o importados a partir dos arquivos:\n\
		- VendasTesouroDireito.csv\n\
		- InvestidoresTesourDireto.csv\n";

}


/*Exibe as op��es do menu de pesquisa*/
void EntradaESaida::exibirMenuPesquisar() {
	cout << "\n1 - N�mero de Venda\n"\
		"2 - Tipo de T�tulo\n"\
		"\nEscolha: ";
	

}

/*Exibe as op��es do menu de pesquisa*/
void EntradaESaida::exibirMenuRelatorio() {
	cout << "\n1 - Rela��o de T�tulos\n"\
		"2 - Investidores por Estado Civil\n"\
		"3 - Investidores por G�nero\n"\
		"4 - Investidores por Regi�o\n"\
		"\nEscolha: ";

}

/*Exibe um menu com as poss�veis opera��es do programa*/
void EntradaESaida::exibirMenu() {
	cout << "\n1 - Importar Arquivos\n"\
		"2 - Pesquisar no Tesouro Direto\n"\
		"3 - Exibir Relat�rios\n"\
		"4 - Sair\n"\
		"\nEscolha: ";
}

/*L� e retorna um n�mero inteiro fornecido pelo teclado*/
int lerInteiro() {
	int numero;
	cin >> numero;
	return numero;
}

