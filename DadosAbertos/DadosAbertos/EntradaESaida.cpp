#include "EntradaESaida.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Venda.h"
using namespace std;
/*Remove o uso de pontos (.) para representar números na casa de milhar em números de
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

/*Retorna um número do tipo double convertido de string a partir do parâmetro <str>*/
double EntradaESaida::stringParaDouble(string str) {
	return stod(EntradaESaida::formatarSeparadorNumero(str));
}

/*Exibe uma mensagem de erro quando é impossível abrir um arquivo*/
void EntradaESaida::exibirFalhaDeImportacao(const char* caminhoDoArquivo) {
	cout << "\nNão foi possível importar os dados de " << caminhoDoArquivo << ".\n"\
	"Arquivo corrompido ou inexistente.\n\n";
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
		"3 - Voltar\n"\
		"\nEscolha: ";
	

}

/*Exibe as opções do menu de pesquisa*/
void EntradaESaida::exibirMenuRelatorio() {
	cout << "\n1 - Relação de Títulos\n"\
		"2 - Investidores por Estado Civil\n"\
		"3 - Investidores por Gênero\n"\
		"4 - Investidores por Região\n"\
		"5 - Voltar\n"\
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
/*Limpa a tela do console*/
void EntradaESaida::limparTela() {
	system("cls");
}

/*Limpa a tela do console*/
void EntradaESaida::pausarTela() {
	int dummy;
	cout << "\nPressione ENTER para continuar...";
	cin >> dummy;
}

void EntradaESaida::pausarLimparTela() {
	pausarTela();
	limparTela();
}

/*Exibe uma divisória como  um conjunto de traços na tela*/
void EntradaESaida::exibirSeparador() {
	cout << "\n-----------------------------\n";
}

/*Lê e retorna um número inteiro fornecido pelo teclado*/
int EntradaESaida::lerInteiro() {
	int numero;
	cin >> numero;
	return numero;
}
/*Lê e retorna uma string fornecida pelo teclado*/
string EntradaESaida::lerString() {
	string str;
	while (str == "")
		getline(cin, str);
	return str;
}

/*Lê uma string e retorna true se ela corresponde a uma data válida ou não. Recebe como parâmetro
uma referência para string que conterá a data a ser lida*/
bool EntradaESaida::lerData(string &data) {
	data = lerString();

	return(validarData(data));

}

/*Compara duas datas. Recebe como parâmtetros:
- Duas datas, dataA e dataB como strings
Retorna um valor positivo se a primeira data for maior que a segunda, um valor negativo se a
segunda for maior que a primeira e 0 se forem iguais*/
int EntradaESaida::compararDatas(string dataA, string dataB) {
	return compararDatas(dataA.c_str(), dataB.c_str());
}

/*Compara duas datas. Recebe como parâmtetros:
	- Duas datas, dataA e dataB como ponteiros constantes para char.
Retorna um valor positivo se a primeira data for maior que a segunda, um valor negativo se a
segunda for maior que a primeira e 0 se forem iguais*/
int EntradaESaida::compararDatas(const char *dataA, const char *dataB){
	
	/*Este método utiliza aritmética de ponteiros para caminhar pelas
	posiões da string representa em ponteiro para char*/
	int resultado;
	// Compara os anos
	resultado = strncmp(dataA + 6, dataB + 6, 4);
	if (resultado != 0) // Se não forem iguais, retorna qual deles é o maior
		return resultado;

	// Compara os anos
	resultado = strncmp(dataA + 3, dataB + 3, 2);
	if (resultado != 0) // Se não forem iguais, retorna qual deles é o maior
		return resultado;

	// Compara os dias
	return strncmp(dataA, dataB, 2); 
}


/*Converte um data de string para valores inteiros. Recebe como parâmetros:
	1. uma string contendo uma data
	2. uma referência para inteiro onde se armazenará o dia
	3. uma referência para inteiro onde se armazenará o mês
	4. uma referência para inteiro onde se armazenará o ano

ATENÇÃO: este método não valida nenhum campo da string, apenas o coverte de texto para inteiro. Para
isso, use o método validarData

Retorna true se for possível converter e falso caso contrário*/
bool EntradaESaida::dataEmInteiros(string data, int & dia, int & mes, int & ano) {
	int contador = 1;
	string token;
	istringstream iss(data);
	while (getline(iss, token, '/')) {
		switch (contador) {
		case 1: dia = atoi(token.c_str()); break;
		case 2: mes = atoi(token.c_str()); break;
		case 3: ano = atoi(token.c_str()); break;
		default: return false;
		}
		contador++;
	}
	return true;
}


/*Verifca a integridade de uma data. Recebe uma string como parâmetro. Se corresponde a
uma data válida, retorna true, do contrário, false*/
bool EntradaESaida::validarData(string data) {
	int dia, mes, ano;
	
	if(!dataEmInteiros(data, dia, mes, ano))
		return false;
		
	return validarData(dia, mes, ano);
}


/*Verifca a integridade de uma data. Recebe três parâmetros, dia, mês e ano. Se corresponde a 
valores válidos, retorna true, do contrário, false*/
bool EntradaESaida::validarData(int dia, int mes, int ano){
	
	//Verifica inicalmente se os valores inteiros, dia, mes e ano são válidos
	if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2200)) {
		//Verifica se o ano é bissexto
		if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) {
			return true;
		}
		//Verifica se o mes corresponde a feveireiro
		if (dia <= 28 && mes == 2) {
			return true;
		}
		//Verifica se corresponde a um mês de 30 dias
		if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
			return true;
		}
		//Verifica se corresponde a um mês de 31 dias
		if ((dia <= 31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 ||
			mes == 8 || mes == 10 || mes == 12)) {
			return true;
		}
		else
			return false;
		
	}
	else
		return false;
}


