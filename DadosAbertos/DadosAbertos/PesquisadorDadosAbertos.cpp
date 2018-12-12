#include <iostream>
#include <clocale>
#include <ctime>
#include <vector>
#include <clocale>
#include "DadosAbertos.h"
#include "Venda.h"
#include "Investidor.h"
#include "ProgressBar.h"

void localizacao() {
	setlocale(LC_ALL, "pt-BR");
}

void iniciar() {
	importarDados();

}

int main() {
	localizacao();

	iniciar();


}

/*Abre um arquivo com o tipo especificado por <tipoDeDado> e importa os dados contidos nele*/
bool DadosAbertos::importarDados(int tipoDeDado) {

	string caminhoArquivo = tipoDeDado == VENDAS ? VENDAS_PATH : INVESTIDORES_PATH;
	ArquivoTexto arquivo;
	unsigned int tamanhoArquivo;
	string leitura, linhas;
	if (!abrirArquivo(arquivo, (caminhoArquivo))) {
		EntradaESaida::exibirFalhaDeImportacao(caminhoArquivo.c_str());
		return false;
	}

	time_t inicio, fim;
	time(&inicio);
	//L� e descarta a linha com os cabe�alhos
	leitura = arquivo.lerLinha(1, false);

	leitura = arquivo.lerLinha(20000, false);
	tamanhoArquivo = leitura.size();

	if (tipoDeDado == VENDAS)
		cout << "\nImportando Dados de Vendas";
	else
		cout << "\nImportando Dados de Investidores";
	separarLinhas(leitura, tipoDeDado);

	cout << endl;
	EntradaESaida::limparTela();
	setlocale(LC_ALL, "pt-BR");

	time(&fim);

	return true;
}



/*Exibe o prompt para ler uma data e a retorna para o usu�rio caso seja �ntegra ou string vazia caso contr�rio*/
string lerData(string texto) {
	int resultado;
	string data;
	do {
		cout << texto;
		resultado = EntradaESaida::lerData(data);
		if (!resultado)
			cout << "\nData inv�lida. Tente novamente ou insira 0 para voltar.\n";
	} while (!resultado && data != "0");
	if (data == "0") {
		cout << "\nOpera��o cancelada.\n";
		return "";
	}
	return data;
}

/*Exibe o prompt para ler uma data e a retorna para o usu�rio caso seja �ntegra ou string vazia caso contr�rio*/
int lerTipoTitulo() {
	int opcao;
	string data;
	Venda venda;
	do {
		cout << "\nTipo do T�tulo:\n";
		cout << "\n1 - " << venda.PREFIXADO_STRING;
		cout << "\n2 - " << venda.IGPM_STRING;
		cout << "\n3 - " << venda.SELIC_STRING;
		cout << "\n4 - " << venda.IPCA_STRING;
		cout << "\n5 - " << venda.IPCA_JUROS_STRING;
		cout << "\n6 - " << venda.PREFIXADO_JUROS_STRING;
		cout << "\n\nEscolha: ";
		cin >> opcao;
		if (opcao == 0) {
			cout << "\nOpera��o cancelada.\n";
			return 0;
		}
		if (opcao < 0 || opcao > 6)
			cout << "\nOp��o inv�lida. Tente novamente ou insira 0 para voltar.\n";
	} while (opcao < 0 || opcao > 6);
	return opcao;

}

void pesquisarNumeroDeVendas(DadosAbertos & dados) {
	string data;
	data = lerData("\nData da Venda (DD/MM/AAAA):");
	if (data == "") return;

	if (!dados.pesquisarNumeroVendas(data))
		cout << "\nNenhum tipo de t�tulo do Tesouro Direto foi vendido em " + data << endl;
}

void pesquisarTipoTitulo(DadosAbertos & dados) {
	string data;
	int tipoTitulo;

	//L� o tipo do t�tulo
	tipoTitulo = lerTipoTitulo();
	if (tipoTitulo == 0) return;

	//L� a data da venda
	data = lerData("\nData da Venda (DD/MM/AAAA):");
	if (data == "") return;

	dados.pesquisarTiposTitulo(tipoTitulo, data);

}

void menuImportacao(DadosAbertos & dados) {
	EntradaESaida::exibirImportacao();
	EntradaESaida::pausarLimparTela();
	dados.importarDados(DadosAbertos::VENDAS);
	dados.importarDados(DadosAbertos::INVESTIDORES);


}

bool lerDatas(string & data1, string & data2) {
	cout << "\nDefina um intervalo de datas:";
	data1 = lerData("\nData incial (DD/MM/AAAA):");
	if (data1 == "") return false;

	data2 = lerData("\nData final (DD/MM/AAAA):");
	if (data2 == "") return false;
	cout << endl;
	return true;
}

void relacaoTiposDeTitulo(DadosAbertos & dados) {
	EntradaESaida::limparTela();
	string data1, data2;
	if (!lerDatas(data1, data2)) {
		cout << "\nOpera��o cancelada";
		return;
	}
	dados.relacaoTiposDeTitulo(data1, data2);

}


void menuRelatorio(DadosAbertos & dados) {
	int opcao;
	do {
		EntradaESaida::exibirMenuRelatorio();
		cin >> opcao;
		EntradaESaida::limparTela();
		switch (opcao) {
		case 1: relacaoTiposDeTitulo(dados); break;
		case 2: dados.relacaoTiposEstadoCivil(); break;
		case 3: dados.relacaoGeneros(); break;
		case 4: dados.relacaoRegioesBrasileiras(); break;
		}
		cout << endl << endl;

	} while (opcao != 5);

}

void menuPesquisar(DadosAbertos & dados) {
	int opcao;
	do {
		EntradaESaida::exibirMenuPesquisar();
		cin >> opcao;
		EntradaESaida::limparTela();
		switch (opcao) {
		case 1: pesquisarNumeroDeVendas(dados); break;
		case 2: pesquisarTipoTitulo(dados); break;
		}
		EntradaESaida::pausarLimparTela();
	} while (opcao != 3);
}

void menu(DadosAbertos & dados) {

	int opcao;

	do {
		EntradaESaida::exibirMenu();
		cin >> opcao;
		EntradaESaida::limparTela();
		switch (opcao) {
		case 1: menuImportacao(dados); break;
		case 2: menuPesquisar(dados); break;
		case 3: menuRelatorio(dados); break;
		}
		EntradaESaida::limparTela();
	} while (opcao != 4);

}


bool importarDados() {

	DadosAbertos dados;
	menu(dados);

	return true;
}


