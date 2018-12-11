#include "EntradaESaida.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Venda.h"
using namespace std;
/*Remove o uso de pontos (.) para representar n�meros na casa de milhar em n�meros de
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

/*Retorna um n�mero do tipo double convertido de string a partir do par�metro <str>*/
double EntradaESaida::stringParaDouble(string str) {
	return stod(EntradaESaida::formatarSeparadorNumero(str));
}

/*Exibe uma mensagem de erro quando � imposs�vel abrir um arquivo*/
void EntradaESaida::exibirFalhaDeImportacao(const char* caminhoDoArquivo) {
	cout << "\nN�o foi poss�vel importar os dados de " << caminhoDoArquivo << ".\n"\
	"Arquivo corrompido ou inexistente.\n\n";
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
		"3 - Voltar\n"\
		"\nEscolha: ";
	

}

/*Exibe as op��es do menu de pesquisa*/
void EntradaESaida::exibirMenuRelatorio() {
	cout << "\n1 - Rela��o de T�tulos\n"\
		"2 - Investidores por Estado Civil\n"\
		"3 - Investidores por G�nero\n"\
		"4 - Investidores por Regi�o\n"\
		"5 - Voltar\n"\
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

/*Exibe uma divis�ria como  um conjunto de tra�os na tela*/
void EntradaESaida::exibirSeparador() {
	cout << "\n-----------------------------\n";
}

/*L� e retorna um n�mero inteiro fornecido pelo teclado*/
int EntradaESaida::lerInteiro() {
	int numero;
	cin >> numero;
	return numero;
}
/*L� e retorna uma string fornecida pelo teclado*/
string EntradaESaida::lerString() {
	string str;
	while (str == "")
		getline(cin, str);
	return str;
}

/*L� uma string e retorna true se ela corresponde a uma data v�lida ou n�o. Recebe como par�metro
uma refer�ncia para string que conter� a data a ser lida*/
bool EntradaESaida::lerData(string &data) {
	data = lerString();

	return(validarData(data));

}

/*Compara duas datas. Recebe como par�mtetros:
- Duas datas, dataA e dataB como strings
Retorna um valor positivo se a primeira data for maior que a segunda, um valor negativo se a
segunda for maior que a primeira e 0 se forem iguais*/
int EntradaESaida::compararDatas(string dataA, string dataB) {
	return compararDatas(dataA.c_str(), dataB.c_str());
}

/*Compara duas datas. Recebe como par�mtetros:
	- Duas datas, dataA e dataB como ponteiros constantes para char.
Retorna um valor positivo se a primeira data for maior que a segunda, um valor negativo se a
segunda for maior que a primeira e 0 se forem iguais*/
int EntradaESaida::compararDatas(const char *dataA, const char *dataB){
	
	/*Este m�todo utiliza aritm�tica de ponteiros para caminhar pelas
	posi�es da string representa em ponteiro para char*/
	int resultado;
	// Compara os anos
	resultado = strncmp(dataA + 6, dataB + 6, 4);
	if (resultado != 0) // Se n�o forem iguais, retorna qual deles � o maior
		return resultado;

	// Compara os anos
	resultado = strncmp(dataA + 3, dataB + 3, 2);
	if (resultado != 0) // Se n�o forem iguais, retorna qual deles � o maior
		return resultado;

	// Compara os dias
	return strncmp(dataA, dataB, 2); 
}


/*Converte um data de string para valores inteiros. Recebe como par�metros:
	1. uma string contendo uma data
	2. uma refer�ncia para inteiro onde se armazenar� o dia
	3. uma refer�ncia para inteiro onde se armazenar� o m�s
	4. uma refer�ncia para inteiro onde se armazenar� o ano

ATEN��O: este m�todo n�o valida nenhum campo da string, apenas o coverte de texto para inteiro. Para
isso, use o m�todo validarData

Retorna true se for poss�vel converter e falso caso contr�rio*/
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


/*Verifca a integridade de uma data. Recebe uma string como par�metro. Se corresponde a
uma data v�lida, retorna true, do contr�rio, false*/
bool EntradaESaida::validarData(string data) {
	int dia, mes, ano;
	
	if(!dataEmInteiros(data, dia, mes, ano))
		return false;
		
	return validarData(dia, mes, ano);
}


/*Verifca a integridade de uma data. Recebe tr�s par�metros, dia, m�s e ano. Se corresponde a 
valores v�lidos, retorna true, do contr�rio, false*/
bool EntradaESaida::validarData(int dia, int mes, int ano){
	
	//Verifica inicalmente se os valores inteiros, dia, mes e ano s�o v�lidos
	if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2200)) {
		//Verifica se o ano � bissexto
		if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) {
			return true;
		}
		//Verifica se o mes corresponde a feveireiro
		if (dia <= 28 && mes == 2) {
			return true;
		}
		//Verifica se corresponde a um m�s de 30 dias
		if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) {
			return true;
		}
		//Verifica se corresponde a um m�s de 31 dias
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


