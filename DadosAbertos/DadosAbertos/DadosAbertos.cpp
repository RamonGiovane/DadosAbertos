#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include "Venda.h"
#include "DadosAbertos.h"
#include "ProgressBar.h"
#include "ArquivoTexto.h"

/*Abre um arquivo de texto especificado por <nomeArquivo> e o retorna sua referêcia pelo parâmtetro <arquivo>
Retorna: true se a abertura foi realizada com sucesso; do contrário false.*/
bool DadosAbertos::abrirArquivo(ArquivoTexto & arquivo, const string nomeArquivo) {
	string leitura;
	if (arquivo.abrir(nomeArquivo, LEITURA))
		return true;
	return false;
}

/*Procura a relação de títulos do tesouro direto nos dados importados, entre o período <data1>  e <data2>, 
exibindo a quantidade e o valor total de cada tipo.
Retorna true caso alguma data seja encontrada, false do contrário*/
bool DadosAbertos::relacaoTiposDeTitulo(string data1, string data2) {
	bool achou = false;
	unsigned int i = 0;
	if (vetorVendas.empty())
		return false;

	//Percorre o vector até encontrar registros com as posições com o limite inferior da pesquisa (data1)
	while (i < vetorVendas.size()-1 &&
		EntradaESaida::compararDatas(data1, vetorVendas[i].getDataVenda()) > 0) {
		i++;
	}

	
	//Se i equivaler ao tamanho do vector, significa que não achou a data inicial
	if (i == vetorVendas.size()-1)
		return false;


	//Vetores de 6 posições que conterão o somátorio dos dados de cada um dos 6 tipos de título
	double quantidade[6] = { 0, 0, 0, 0, 0 ,0 },
		valorTotal[6] = { 0, 0, 0, 0, 0 ,0 };

	//Percorre o vector enquanto as datas sendo processandas não ultrapassem o limite superior da pesquisa (data2)
	for (; i < vetorVendas.size() && EntradaESaida::compararDatas(vetorVendas[i].getDataVenda(), data2) <= 0; i++) {

		/*Armazena o somatório de quantidades dentro vetor. Cada título é representado
		por um número de 1 a 6, e as posições do vetor de 0 a 5, subtrai-se 1 
		para armazenar o somatório de um tipo de título em sua devidapc posição*/
		quantidade[vetorVendas[i].getTipoTitulo() - 1] += vetorVendas[i].getQuantidade();
		valorTotal[vetorVendas[i].getTipoTitulo() - 1] += vetorVendas[i].getValor();

		achou = true;

	}

	if (!achou) return false;

	//Agora exibe ao usuário os somatórios dos dados de cada título
	char saida[200];
	for (int i = 0; i < 6; i++) {
		cout << i+1 << " - " << Venda::obterTipoTituloEmString(i + 1);	
		sprintf_s(saida, 200, "\n\tQuantidade total: %.2f", quantidade[i]);
		cout << saida;
		sprintf_s(saida, 200, "\n\tValor total: R$ %.2f\n", valorTotal[i]);
		cout << saida << endl;
	}
	EntradaESaida::pausarTela();
	return true;
	
}
/*Procura a relação de estados civis de investidores do tesouro direto nos dados importados,
exibindo o número de investidores e a média de idade em cada tipo.
Retorna true caso alguma data seja encontrada, false do contrário*/
bool DadosAbertos::relacaoTiposEstadoCivil() {
	//Este método segue a mesma logica do relacaoTiposDeTitulo
	int mediaIdade[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
		quantidade[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	char saida[200];

	for (unsigned int i = 0; i < vetorInvestidores.size(); i++) {
		quantidade[vetorInvestidores[i].getEstadoCivil() - 1]++;
		mediaIdade[vetorInvestidores[i].getEstadoCivil() - 1] += vetorInvestidores[i].getIdade();
	}
	
	EntradaESaida::exibirTitulo("Investidores por Estado Civil");
	for (int i = 0; i < 10; i++) {
		cout << endl << endl << i + 1 << " - " << Investidor::obterEstadoCivil(i + 1);
		sprintf_s(saida, 200, "\n\tNúmero de investidores: %d", quantidade[i]);
		cout << saida;

		if (quantidade[i] != 0) {
			sprintf_s(saida, 200, "\n\tMédia de idade: %d ano(s)", mediaIdade[i] / quantidade[i]);
			cout << saida;
		}
		else
			cout << endl;
		cout << endl;
	}
	return true;

}

/*Procura a relação de regiões brasileiras com os investidores do tesouro direto nos dados importados,
exibindo o número de investidores e a média de idade de cada região.
Retorna true caso alguma dado seja exibido, false do contrário*/
bool DadosAbertos::relacaoRegioesBrasileiras() {
	const string NORTE = "Norte", SUL = "Sul", SUDESTE = "Sudeste",
		CENTRO = "Centro-Oeste", NORDESTE = "Nordeste";

	//Este método segue a mesma logica do relacaoTiposDeTitulo
	int mediaIdade[5] = { 0, 0, 0, 0, 0 },
		quantidade[5] = { 0, 0, 0, 0, 0 };
	char saida[200];

	int indice;
	for (unsigned int i = 0; i < vetorInvestidores.size(); i++) {

		if (vetorInvestidores[i].obterRegiao() == NORTE) indice = 0;
		else if (vetorInvestidores[i].obterRegiao() == NORDESTE) indice = 1;
		else if (vetorInvestidores[i].obterRegiao() == CENTRO)   indice = 2;
		else if (vetorInvestidores[i].obterRegiao() == SUDESTE)  indice = 3;
		else if (vetorInvestidores[i].obterRegiao() == SUL)		 indice = 4;

		mediaIdade[indice] += vetorInvestidores[i].getIdade();
		quantidade[indice]++;
	}

	EntradaESaida::exibirTitulo("Investidores por Região");
	string regiao;
		for (indice = 0; indice < 5; indice++){
			switch (indice) {
			case 0: regiao = NORTE; break;
			case 1: regiao = NORDESTE; break;
			case 2: regiao = CENTRO; break;
			case 3: regiao = SUDESTE; break;
			case 4: regiao = SUL; break;

			}

			cout << endl << indice + 1 << " - " << regiao;
			sprintf_s(saida, 100, "\n\tNúmero de investidores: %d", quantidade[indice]);
			cout << saida;

			if (quantidade[indice] != 0) {
				sprintf_s(saida, 100, "\n\tMédia de idade : %d ano(s)", mediaIdade[indice] / quantidade[indice]);
				cout << saida;
			}
			else
				cout << endl;
			cout << endl;
				
	}
	
	return true;

}

/*Procura a relação de regiões brasileiras com os investidores do tesouro direto nos dados importados,
exibindo o número de investidores e a média de idade de cada região.
Retorna true caso alguma dado seja exibido, false do contrário*/
bool DadosAbertos::relacaoGeneros() {
	const string NORTE = "Norte", SUL = "Sul", SUDESTE = "Sudeste",
		CENTRO = "Centro-Oeste", NORDESTE = "Nordeste";

	//Este método segue a mesma logica do relacaoTiposDeTitulo
	int mediaIdade[3] = { 0, 0, 0 },
		quantidade[3] = { 0, 0, 0 };
	char saida[150];

	int indice;
	for (unsigned int i = 0; i < vetorInvestidores.size(); i++) {

		if (vetorInvestidores[i].getGenero() == 'M') indice = 0;
		else if (vetorInvestidores[i].getGenero() == 'F') indice = 1;
		else indice = 2;

		mediaIdade[indice] += vetorInvestidores[i].getIdade();
		quantidade[indice]++;
	}

	EntradaESaida::exibirTitulo("Investidores por Região");
	string genero;
	for (indice = 0; indice < 3; indice++) {
		switch (indice) {
		case 0:  genero = "Masculino"; break;
		case 1:  genero = "Feminino"; break;
		default: genero = "Indefinido"; break;
		}

		cout << endl << indice + 1 << " - " << genero;
		sprintf_s(saida, 100, "\n\tNúmero de investidores: %d", quantidade[indice]);
		cout << saida;

		if (quantidade[indice] != 0) {
			sprintf_s(saida, 100, "\n\tMédia de idade : %d ano(s)", (mediaIdade[indice] / quantidade[indice]));
			cout << saida;
		}
		
		else
			cout << endl;
		cout << endl;
	}

	return true;

}

/*Pesquisa informações no conjunto de dados importado quanto aos tipos de titulo,
e exibe as datas de vencimento, quantidade e valor total vendido.
Retorna true se houver algum dado a ser exibido com <data> e com <tipoTitulo> especificados.
Caso contrário, retorna false.*/
bool DadosAbertos::pesquisarTiposTitulo(int tipoTitulo, string data) {
	EntradaESaida::limparTela();
	EntradaESaida::exibirTitulo("Pesquisa por Tipos de Título");
	bool encontrou = false;
	if (vetorVendas.empty()) {
		return false;
	}
	for (unsigned int i = 0; i < vetorVendas.size(); i++) {
		//Verifica o tipo do titulo
		if(vetorVendas[i].getTipoTitulo() == tipoTitulo)
			//Verifca a data da venda
			if (EntradaESaida::compararDatas(vetorVendas[i].getDataVenda(), data) == 0) {
				cout << i;
				cout << vetorVendas[i].obterDadosPesquisa(false);
				EntradaESaida::exibirSeparador();
				encontrou = true;
			}
	}
	return encontrou;
}

/*Pesquisa e exibe informações do conjunto de dados importados quanto aos tipos de titulo,
as datas de vencimento, quantidade e valor total vendido. Retorna true se algum dado tiver sido exibido,
false caso nenhum registro tenha sido obtido nesta data*/
bool DadosAbertos::pesquisarNumeroVendas(string data) {
	EntradaESaida::limparTela();
	EntradaESaida::exibirTitulo("Pesquisa sobre Número de Vendas");
	bool encontrou = false;
	if (vetorVendas.empty()) {
		return false;
	}
	for (unsigned int i = 0; i < vetorVendas.size(); i++) {
		if (EntradaESaida::compararDatas(vetorVendas[i].getDataVenda(), data) == 0) {
			cout << vetorVendas[i].obterDadosPesquisa();
			EntradaESaida::exibirSeparador();
			encontrou = true;
		}
	}
	return encontrou;
}

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
	return static_cast<int>(tipoDeDado == VENDAS ? vetorVendas.size() : vetorInvestidores.size());
}

/*Separa as linhas do arquivo formatadas em um objeto string e as adiciona no vector de Dados Abertos
de acordo com o tipo especificado em <tipoDeDado> */
bool DadosAbertos::separarLinhas(string leitura, int tipoDeDado ) {
	unsigned int contador = 0;
	ProgressBar p(10, 10, 100);
	
	if (leitura.empty())
		return false;

	string token;
	
	istringstream iss(leitura);
	int tam = leitura.size();
	while (getline(iss, token, '\n')) {
		adicionar(token, tipoDeDado);
		contador += token.size();
		p.show(contador * 100 / tam);
	}
	return true;

}

