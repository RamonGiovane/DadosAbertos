#pragma once
#ifndef DADOS_ABERTO_H
#define DADOS_ABERTO_H
#include <vector>
#include <cstdlib>
#include <string>
#include "Investidor.h"
#include "Venda.h"

using namespace std;
bool importarDados(vector<Venda>& vetorVendas);
bool importarDados();
Venda parseVenda(string linha);
Investidor parseInvestidor(string linha);



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

