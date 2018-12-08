#include <iostream>
#include <string>
using namespace std;

void importar() {
	system("clear");//substituir por limparTela
	string menu = "Os dados ser�o importados a partir dos arquivos:\n\
		- VendasTesouroDireito.csv\n\
		- InvestidoresTesourDireto.csv\n";
	system("pause"); //substituir por pausarTela;


}

void menuPesquisar() {
	int operacao;
	string menu = "\n1 - N�mero de Venda\n"\
		"2 - Tipo de T�tulo\n"\
		"\nEscolha: ";
	cout << menu;
	cin >> operacao;
	

}

void menuRelatorio() {
	int operacao;
	string menu = "\n1 - Rela��o de T�tulos\n"\
		"2 - Investidores por Estado Civil\n"\
		"3 - Investidores por G�nero\n"\
		"4 - Investidores por Regi�o\n"\
		"\nEscolha: ";
	cin >> operacao;

}

void exibirMenu() {
	int operacao;
	char menu[] = "\n1 - Importar Arquivos\n"\
		"2 - Pesquisar no Tesouro Direto\n"\
		"3 - Exibir Relat�rios\n"\
		"4 - Sair\n"\
		"\nEscolha: ";
	
	do{
		cout << menu;
		cin >> operacao;

		switch (operacao) {
		case 1: importar(); break;
		case 2: menuPesquisar(); break;
		case 3: menuRelatorio(); break;
		}
	} while (operacao != 4);
}