#pragma once
#ifndef DADOS_ABERTO_H
#define DADOS_ABERTO_H
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
	enum TipoDeDado { VENDAS, INVESTIDOR};
	

private:
	vector<Venda> vetorVendas;
	vector<Investidor> vetorInvestidores;
	const string VENDAS_PATH = "../../../VendasTesouroDireto.csv";
	const string INVESTIDORES_PATH = "../../../VendasTesouroDireto.csv";
	bool abrirArquivo(ArquivoTexto & arquivo, const string nomeArquivo);
	bool adicionar(string atributos, int tipoDeDado);
	bool separarLinhas(string leitura, int tipoDeDado);
	bool importarDados(int tipoDeDado);

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


#endif // !DADOS_ABERTO_H

