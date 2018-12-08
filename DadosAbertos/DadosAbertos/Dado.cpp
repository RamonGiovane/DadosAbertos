#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include "Venda.h"
#include "Dado.h"
#include "ArquivoTexto.h"

/*Abre um arquivo de texto especificado por <nomeArquivo> e o retorna sua referêcia pelo parâmtetro <arquivo>
Retorna: true se a abertura foi realizada com sucesso; do contrário false.*/
bool DadosAbertos::abrirArquivo(ArquivoTexto & arquivo, const string nomeArquivo) {
	string leitura;
	if (arquivo.abrir(nomeArquivo, LEITURA))
		return true;
	return false;
}

/*Converte uma linha(string) e a adiciona como objeto em um dos vector de Dados Abertos de acordo
com com o seu tipo do objeto especificado em <tipoDeDado>.*/
bool DadosAbertos::adicionar(string atributos, int tipoDeDado) {
	if (atributos.empty())
		return false;
	if(tipoDeDado == INVESTIDOR)
		vetorInvestidores.push_back(Investidor::parseInvestidor(atributos));
	else
		vetorVendas.push_back(Venda::parseVenda(atributos));
	return true;
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

/*Abre um arquivo do tipo Vendas do Tesouro Direto e importa os dados contidos nele*/
bool DadosAbertos::importarDados(int tipoDeDado) {
	ArquivoTexto arquivo;
	
	string leitura, linhas;
	if (!abrirArquivo(arquivo, (tipoDeDado == VENDAS ? VENDAS_PATH : INVESTIDORES_PATH)))
		return false;
	
	time_t inicio, fim;
	time(&inicio);
	//Lê e descarta a linha com os cabeçalhos
	leitura = arquivo.lerLinha(1, false);

	leitura = arquivo.lerLinha(60000, false);
	cout << endl << leitura.size();
	do {
		linhas = separarLinhas(leitura, tipoDeDado);

	} while (true);
		
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



bool importarDados() {
	cout << "We're not ready yet!";
	return true;
}




