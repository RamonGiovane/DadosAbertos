#pragma once
#ifndef DADOS_ABERTOS_H
#define DADOS_ABERTOS_H
#include <vector>
#include <cstdlib>
#include <string>
#include "Investidor.h"
#include "Venda.h"
#include "EntradaESaida.h"
#include "ArquivoTexto.h"

using namespace std;

bool importarDados();

class DadosAbertos {
public:
	enum TipoDeDado { VENDAS, INVESTIDORES};
	
	
	bool adicionar(string atributos, int tipoDeDado);
	int numeroDeImportacoes(int tipoDeDado);
	bool importarDados(int tipoDeDado);
	static bool organizarVendasPorData(vector<Venda> vetorVendas);
	static bool comparadorVendas(const Venda & vendaA, const Venda & vendaB);

	//bool organizarVendasPorData(vector<Venda> vetorVendas);

private:
	vector<Venda> vetorVendas;
	vector<Investidor> vetorInvestidores;
	const string VENDAS_PATH = "../../../VendasTesouroDireto.csv";
	const string INVESTIDORES_PATH = "../../../InvestidoresTesouroDireto - Cópia.csv";
	bool separarLinhas(string leitura, int tipoDeDado);
	bool abrirArquivo(ArquivoTexto & arquivo, const string nomeArquivo);
	
	

};

inline void pause() {
	system("pause");
}

inline void clear() {
	system("clear || cls");
}

inline void pauseAndClear() {
	pause();
	clear();
}


#endif // !DADOS_ABERTOS_H

