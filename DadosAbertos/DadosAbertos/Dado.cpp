#include <iostream>
#include <sstream>
#include <vector>
#include <ctime>
#include <algorithm>
#include "Venda.h"
#include "Dado.h"
#include "ArquivoTexto.h"

/*
Remove o uso de pontos (.) para representar números na casa de milhar em números de
ponto flutuante dentro de uma string.
Exemplo de entrada: 1.000,00 -> exemplo de saída: 1000,00
*/
string converterNumero(string numero) {
	numero.erase(remove(numero.begin(), numero.end(), '.'));

	return numero;
}

void msgFalhaDeImportacao(string tipoDeArquivo) {
	cout << "\nNão foi possível importar os dados de " << tipoDeArquivo << "!\nArquivo corrompido ou inexistente.\n";
}

/*Abre um arquivo de texto especificado por <nomeArquivo> e o retorna sua referêcia pelo parâmtetro <arquivo>
Retorna: true se a abertura foi realizada com sucesso; do contrário false.*/
bool abrirArquivo(ArquivoTexto& arquivo, string nomeArquivo) {
	string leitura;
	//cout << "Damn " << nomeArquivo << " " << arquivo.abrir(nomeArquivo, LEITURA);
	if (arquivo.abrir(nomeArquivo, LEITURA))
		return true;
	return false;

}

bool importarDados(vector<Venda>& vetorVendas) {
	ArquivoTexto arquivo;
	string leitura;
	if (!abrirArquivo(arquivo, "../../VendasTesouroDireto.csv"))
		return false;
	
	time_t inicio, fim;
	time(&inicio);
	//Lê e descarta a linha com os cabeçalhos
	leitura = arquivo.lerLinha(1, false);

	do {
		leitura = arquivo.lerLinha(2, false);
		if (leitura != "NULL")
			vetorVendas.push_back(parseVenda(leitura));
		else break;
		
	} while (leitura != "NULL");
	time(&fim);
	cout << difftime(fim, inicio) << " segundos";
	return true;
}

bool importarDados(vector<Investidor>& vetorInvestidores) {
	ArquivoTexto arquivo;
	string leitura;
	if(!arquivo.abrir("../../InvestidoresTesouroDireto.csv", LEITURA))
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
	cout << difftime(fim, inicio) << " segundos";
	return true;
}



bool importarDados() {
	vector<Venda> vetorVendas;
	vector<Investidor> vetorInvestidores;
	ArquivoTexto arquivo;
	cout << arquivo.abrir("../../VendasTesouroDireto.csv", LEITURA);
	
	if (!importarDados(vetorVendas))
		msgFalhaDeImportacao("vendas");

	cout << "Tamanho do vecotr vendas: " << vetorVendas.size();
	cout << vetorVendas[vetorVendas.size()-1].toString();

	if (!importarDados(vetorInvestidores))
		msgFalhaDeImportacao("investidores");
	
	cout << "Tamanho do vecotr investidores: " << vetorInvestidores.size();
	vetorInvestidores[vetorInvestidores.size()-1].toString();

	return true;
}



Venda parseVenda(string linha){
	size_t posicao = 0, contador = 1;
	string separador = ";";
	string token;

	Venda venda;

	if (linha.empty())
		return false;

	istringstream iss(linha);
	
	while (getline(iss, token, ';')){
		
		switch (contador) {
		case 1: venda.setTipoTitulo(token); break;
		case 2: venda.setVencimentoTitulo(token); break;
		case 3: venda.setDataVenda(token); break;
		case 4: venda.setPrecoUnitario(stof(converterNumero(token))); break;
		case 5: venda.setQuantidade(stof(converterNumero(token))); break;
		case 6: venda.setValor(stof(converterNumero(token))); break;
		default: break;

		}
		
		contador++;
	}

	return venda;
}

Investidor parseInvestidor(string linha) {
	size_t posicao = 0, contador = 1;
	string separador = ";";
	string token;

	Investidor investidor;

	if (linha.empty())
		return Investidor();

	istringstream iss(linha);

	while (getline(iss, token, ';')) {

		switch (contador) {
		case 1: investidor.setCodigoInvestidor(token); break;
		case 2: investidor.setDataAdesao(token); break;
		case 3: investidor.setEstadoCivil(token); break;
		case 4: investidor.setGenero(token.c_str()[0]); break;
		case 5: investidor.setProfissao(token); break;
		case 6: investidor.setIdade(stoi(token)); break;
		case 7: investidor.setUFInvestidor(token); break;
		case 8: investidor.setCidadeInvestidor(token); break;
		case 9: investidor.setPaisInvestidor(token); break;
		case 10: investidor.setSituacaoConta(token); break;
		case 11: investidor.setOperacaoRecente(token == "S" ? true : false); break;
		
		default: break;

		}

		contador++;
	}

	return investidor;
}

