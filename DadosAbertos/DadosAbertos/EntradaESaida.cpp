#include "EntradaESaida.h"
#include <iostream>
/*
Remove o uso de pontos (.) para representar números na casa de milhar em números de
ponto flutuante dentro de uma string.
Exemplo de entrada: 1.000,00 -> exemplo de saída: 1000,00
Retorna uma string com o novo número formatado
*/
string EntradaESaida::formatarSeparadorNumero(string numero) {
	numero.erase(remove(numero.begin(), numero.end(), '.'));

	return numero;
}

/*Retorna um número do tipo float convertido de string a partir do parâmetro <str>*/
float EntradaESaida::stringParaFloat(string str) {
	return stof(EntradaESaida::formatarSeparadorNumero(str));
}

/*Retorna um número do tipo float convertido de string a partir do parâmetro <str>*/
int EntradaESaida::stringParaInt(string str) {
	return stoi(EntradaESaida::formatarSeparadorNumero(str));
}


/*Exibe uma mensagem de erro quando é impossível abrir um arquivo*/
void EntradaESaida::exibirFalhaDeImportacao(const char* tipoDeArquivo) {
	cout << "\nNão foi possível importar os dados de " << tipoDeArquivo << "!\nArquivo corrompido ou inexistente.\n";
}


/*Exibe a mensagem de importação quando esta operação é solicitada*/
void EntradaESaida::exibirImportacao() {
	cout << "Os dados serão importados a partir dos arquivos:\n\
		- VendasTesouroDireito.csv\n\
		- InvestidoresTesourDireto.csv\n";

}


/*Exibe as opções do menu de pesquisa*/
void EntradaESaida::exibirMenuPesquisar() {
	cout << "\n1 - Número de Venda\n"\
		"2 - Tipo de Título\n"\
		"\nEscolha: ";
	

}

/*Exibe as opções do menu de pesquisa*/
void EntradaESaida::exibirMenuRelatorio() {
	cout << "\n1 - Relação de Títulos\n"\
		"2 - Investidores por Estado Civil\n"\
		"3 - Investidores por Gênero\n"\
		"4 - Investidores por Região\n"\
		"\nEscolha: ";

}

/*Exibe um menu com as possíveis operações do programa*/
void EntradaESaida::exibirMenu() {
	cout << "\n1 - Importar Arquivos\n"\
		"2 - Pesquisar no Tesouro Direto\n"\
		"3 - Exibir Relatórios\n"\
		"4 - Sair\n"\
		"\nEscolha: ";
}

/*Lê e retorna um número inteiro fornecido pelo teclado*/
int lerInteiro() {
	int numero;
	cin >> numero;
	return numero;
}

