#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Venda.h"
#include "DadosAbertos.h"
#include "ArquivoTexto.h"

/*Abre um arquivo de texto especificado por <nomeArquivo> e o retorna sua referêcia pelo parâmtetro <arquivo>
Retorna: true se a abertura foi realizada com sucesso; do contrário false.*/
bool DadosAbertos::abrirArquivo(ArquivoTexto & arquivo, const string nomeArquivo) {
	string leitura;
	if (arquivo.abrir(nomeArquivo, LEITURA))
		return true;
	return false;
}

/*Método utilizado na ordenação de datas de venda*/
/*bool DadosAbertos::comparadorVendas(const Venda& vendaA, const Venda& vendaB) {
	Venda vendaCopia1 = vendaA, vendaCopia2 = vendaB;
	string dataA = vendaCopia1.getDataVenda();
	string dataB = vendaCopia2.getDataVenda();

	//Se uma data for maior ou igual a outra, retorna falso, do contráio retorna true
	return EntradaESaida::compararDatas(dataA, dataB) < 0 ? false : true;
}*/


/*Ordena os dados  de Venda importados em ordem crescente*/
/*bool DadosAbertos::organizarVendasPorData() {
	sort(vetorVendas.begin(), vetorVendas.end(), DadosAbertos::comparadorVendas);
}*/

/*Converte uma linha(string) e a adiciona como objeto em um dos vector de Dados Abertos de acordo
com com o seu tipo do objeto especificado em <tipoDeDado>.*/
bool DadosAbertos::adicionar(string atributos, int tipoDeDado) {
	if (atributos.empty())
		return false;
	if(tipoDeDado == INVESTIDORES)
		vetorInvestidores.push_back(Investidor::parseInvestidor(atributos));
	else
		vetorVendas.push_back(Venda::parseVenda(atributos));
	return true;
}

/*Retorna o número de objetos importados de acordo com o <tipoDeDado> informado por parâmetro*/
int  DadosAbertos::numeroDeImportacoes(int tipoDeDado) {
	return tipoDeDado == VENDAS ? vetorVendas.size() : vetorInvestidores.size();
}

/*Separa as linhas do arquivo formatadas em um objeto string e as adiciona no vector de Dados Abertos
de acordo com o tipo especificado em <tipoDeDado> */
bool DadosAbertos::separarLinhas(string leitura, int tipoDeDado ) {
	if (leitura.empty())
		return false;

	string token;
	
	istringstream iss(leitura);
	
	while (getline(iss, token, '\n'))
		adicionar(token, tipoDeDado);
	
	return true;

}

/*Abre um arquivo com o tipo especificado por <tipoDeDado> e importa os dados contidos nele*/
bool DadosAbertos::importarDados(int tipoDeDado) {
	
	string caminhoArquivo = tipoDeDado == VENDAS ? VENDAS_PATH : INVESTIDORES_PATH;
	ArquivoTexto arquivo;
	
	string leitura, linhas;
	if (!abrirArquivo(arquivo, (caminhoArquivo))) {
		EntradaESaida::exibirFalhaDeImportacao(caminhoArquivo.c_str());
		return false;
	}
	
	time_t inicio, fim;
	time(&inicio);
	//Lê e descarta a linha com os cabeçalhos
	leitura = arquivo.lerLinha(1, false);

	leitura = arquivo.lerLinha(250000, false);
	
	
	separarLinhas(leitura, tipoDeDado);

	cout << endl << numeroDeImportacoes(tipoDeDado) << endl;

	time(&fim);
	cout << difftime(fim, inicio) << " segundos\n";
	return true;
}

/*bool importarDados(vector<Investidor>& vetorInvestidores) {
	return false;
	ArquivoTexto arquivo;
	string leitura;
	if(!arquivo.abrir("../../../InvestidoresTesouroDireto - Cópia.csv", LEITURA))
		return  false;

	time_t inicio, fim;
	time(&inicio);
	//Lê e descarta a linha com os cabeçalhos
	leitura = arquivo.lerLinha(1, false);

	do {
		leitura = arquivo.lerLinha(2, false);
		if (leitura != "NULL")
			vetorInvestidores.push_back(parseInvestidor(leitura));
		else break;

	} while (leitura != "NULL");
	time(&fim);
	cout << difftime(fim, inicio) << " segundos" << endl;
	return true;
}*/

bool comparadorVendas(const Venda& vendaA, const Venda& vendaB) {
	Venda vendaCopia1 = vendaA, vendaCopia2 = vendaB;
	string dataA = vendaCopia1.getDataVenda();
	string dataB = vendaCopia2.getDataVenda();

	//Se uma data for maior ou igual a outra, retorna falso, do contráio retorna true
	return EntradaESaida::compararDatas(dataA, dataB) < 0 ? false : true;

}

/*Ordena os dados  de Venda importados em ordem crescente*/
bool organizarVendasPorData(vector<Venda> vetorVendas) {
	sort(vetorVendas.begin(), vetorVendas.end(), DadosAbertos::comparadorVendas);
}

void menuImportacao() {
	EntradaESaida::exibirImportacao();

}

void menuRelatorio() {
	int opcao;
	do {
		EntradaESaida::exibirMenuRelatorio();
		cin >> opcao;
	} while (opcao != 5);
	
}

void menuPesquisar() {
	int opcao;
	do {
		EntradaESaida::exibirMenuPesquisar();
		cin >> opcao;
	} while (opcao != 3);
}

void menu() {

	int opcao;

	do {
		EntradaESaida::exibirMenu();
		cin >> opcao;
		switch (opcao) {
		case 1: menuImportacao(); break;
		case 2: menuPesquisar(); break;
		case 3: menuRelatorio(); break;
		}
	} while (opcao != 4);

}


bool importarDados() {
	
	menu();
	DadosAbertos dados;
	dados.importarDados(DadosAbertos::VENDAS);
	//dados.importarDados(DadosAbertos::INVESTIDORES);
	//cout << "We're not ready yet!";
	return true;
}




