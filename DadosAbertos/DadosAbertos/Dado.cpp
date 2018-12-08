#include <iostream>
#include <sstream>
#include <vector>
#include "Venda.h"
#include "Dado.h"
#include "ArquivoTexto.h"
/*int verificarTipoDeDado(string atributos) {
	std::istringstream iss(atributos);
	std::string token;
	while (std::getline(iss, token, ';'))
	{
		std::cout << token << std::endl;
	}
	return 1;
}*/

bool importarDados(vector<Venda>& vetorVendas) {
	ArquivoTexto arquivo;
	string leitura;
	
	if (!arquivo.abrir("../../VendasTesouroDireto.csv", LEITURA))
		return false;

	
	
	//Lê e descarta a linha com os cabeçalhos
	leitura = arquivo.lerLinha(1, false);

	do {
		leitura = arquivo.lerLinha(2, false);
		if (leitura != "NULL")
			separarAtributos(leitura, vetorVendas); //melhorar! overhead desnecessario. pode retornar um obj e dai fazer pushback
		else break;
		pause();
	} while (leitura != "NULL");
	
	return true;
}

bool importarDados(vector<Investidor>& vetorInvestidores) {
	ArquivoTexto arquivo;
	arquivo.abrir("../../InvestidoresTesouroDireto - Cópia.csv", LEITURA);
	return true;
}

bool importarDados() {
	vector<Venda> vetorVendas;
	vector<Investidor> vetorInvestidores;
	
	importarDados(vetorVendas);
	
	return true;
}


bool separarAtributos(string linha, vector<Venda>& vetorVenda){
	size_t posicao = 0, contador = 1;
	string separador = ";";
	string token;

	Venda venda;

	if (linha.empty())
		return false;
	
	cout << "\nContador " << contador;
	cout << "\nLinha " << linha;

	/*while ((posicao = linha.find(separador)) != string::npos) {
		
		token = linha.substr(0, posicao);
		
		cout << endl << token;
		pause();

		switch (contador) {
		case 1: venda.setTipoTitulo(token); break;
		case 2: venda.setVencimentoTitulo(token); break;
		case 3: venda.setDataVenda(token); break;
		case 4: venda.setPrecoUnitario(stof(token)); break;
		case 5: venda.setQuantidade(stof(token)); break;
		case 6: venda.setValor(stof(token)); break;
		default: break;
		
		}
		linha.erase(0, posicao + separador.length());
		contador++;
	}*/
	//Tentando separar a string de outra forma
	std::istringstream iss(linha);
	
	while (std::getline(iss, token, ';')){
		//std::cout << token << std::endl;
		//cout << endl << token;
		//pause();

		switch (contador) {
		case 1: venda.setTipoTitulo(token); break;
		case 2: venda.setVencimentoTitulo(token); break;
		case 3: venda.setDataVenda(token); break;
		case 4: venda.setPrecoUnitario(stof(token)); break;
		case 5: venda.setQuantidade(stof(token)); break;
		case 6: venda.setValor(stof(token)); break;
		default: break;

		}
		linha.erase(0, posicao + separador.length());
		contador++;
	}


	cout << venda.toString() << endl;
	vetorVenda.push_back(venda);

	return true;
}

