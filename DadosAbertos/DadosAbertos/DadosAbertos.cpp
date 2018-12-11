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

bool DadosAbertos::relacaoDeTitulos(string data1, string data2) {
	
	int i = 0;
	if (vetorVendas.empty())
		return false;

	//Percorre o vector até encontrar registros com as posições com o limite inferior da pesquisa (data1)
	while (EntradaESaida::compararDatas(vetorVendas[i].getDataVenda(), data1) < 0)
		i++;
	//Vetores de 6 posições que conterão o somátorio dos dados de cada um dos 6 tipos de título
	float quantidade[6], valorTotal[6];
	
	//Percorre o vector enquanto as datas sendo processandas não ultrapassem o limite superior da pesquisa (data2)
	for (; EntradaESaida::compararDatas(vetorVendas[i].getDataVenda(), data2) <= 0 &&
		i < (static_cast<int>(vetorVendas.size())); i++) {
		
		/*Armazena o somatório de quantidades dentro vetor. Cada título é representado
		por um número de 1 a 6, e as posições do vetor de 0 a 5, subtrai-se 1 
		para armazenar o somatório de um tipo de título em sua devida posição*/
		quantidade[vetorVendas[i].getTipoTitulo() - 1] += vetorVendas[i].getQuantidade();
		valorTotal[vetorVendas[i].getTipoTitulo() - 1] += vetorVendas[i].getValor();

	}

	//Agora exibe ao usuário os somatórios dos dados de cada título
	for (int i = 0; i < 6; i++) {
		cout << i+1 << " - " << Venda::obterTipoTituloEmString(i + 1);
		cout << "\n\tQuantidade total: " << quantidade[i];
		cout << "\n\tValor total: " << valorTotal[i] << endl;
	}

	return true;
	
}

/*Pesquisa informações no conjunto de dados importado quanto aos tipos de titulo,
e exibe as datas de vencimento, quantidade e valor total vendido.
Retorna true se houver algum dado a ser exibido com <data> e com <tipoTitulo> especificados.
Caso contrário, retorna false.*/
bool DadosAbertos::pesquisarTiposTitulo(int tipoTitulo, string data) {
	EntradaESaida::limparTela();
	cout << "\n\t--- Pesquisa por Tipos de Título ---\n";
	bool encontrou = false;
	if (vetorVendas.empty()) {
		cout << "\nTeste: vector vendas vazio";
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
	cout << "\n\t--- Pesquisa sobre Número de Vendas ---\n";
	bool encontrou = false;
	if (vetorVendas.empty()) {
		cout << "\nTeste: vector vendas vazio";
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


/*Exibe o prompt para ler uma data e a retorna para o usuário caso seja íntegra ou string vazia caso contrário*/
string lerData(string texto) {
	int resultado;
	string data;
	do {
		cout << texto;
		resultado = EntradaESaida::lerData(data);
		if (!resultado)
			cout << "\nData inválida. Tente novamente ou insira 0 para voltar.\n";
	} while (!resultado && data != "0");
	if (data == "0") {
		cout << "\nOperação cancelada.\n";
		return "";
	}
	return data;
}

/*Exibe o prompt para ler uma data e a retorna para o usuário caso seja íntegra ou string vazia caso contrário*/
int lerTipoTitulo() {
	int opcao;
	string data;
	Venda venda;
	do {
		cout << "\nTipo do Título:\n";
		cout << "\n1 - " << venda.PREFIXADO_STRING;
		cout << "\n2 - " << venda.IGPM_STRING;
		cout << "\n3 - " << venda.SELIC_STRING;
		cout << "\n4 - " << venda.IPCA_STRING;
		cout << "\n5 - " << venda.IPCA_JUROS_STRING;
		cout << "\n6 - " << venda.PREFIXADO_JUROS_STRING;
		cout << "\n\nEscolha: ";
		cin >> opcao;
		if (opcao == 0) {
			cout << "\nOperação cancelada.\n";
			return 0;
		}
		if (opcao < 0 || opcao > 6)
			cout << "\nOpção inválida. Tente novamente ou insira 0 para voltar.\n";
	} while (opcao < 0 || opcao > 6);
	return opcao;

}

void pesquisarNumeroDeVendas(DadosAbertos & dados) {
	string data;
	data = lerData("\nData da Venda (DD/MM/AAAA):");
	if (data == "") return;
	
	if (!dados.pesquisarNumeroVendas(data))
		cout << "\nNenhum tipo de título do Tesouro Direto foi vendido em " + data << endl;

	
}

void pesquisarTipoTitulo(DadosAbertos & dados) {
	string data;
	int tipoTitulo;

	//Lê o tipo do título
	tipoTitulo = lerTipoTitulo();
	if (tipoTitulo == 0) return;
	
	//Lê a data da venda
	data = lerData("\nData da Venda (DD/MM/AAAA):");
	if (data == "") return;

	dados.pesquisarTiposTitulo(tipoTitulo, data);

}

void menuImportacao(DadosAbertos & dados) {
	EntradaESaida::exibirImportacao();
	getchar();
	dados.importarDados(DadosAbertos::VENDAS);
	//dados.importarDados(DadosAbertos::INVESTIDORES);


}

void relacaoDeTitulos(DadosAbertos & dados) {
	string data1, data2;
	
	cout << "\nDefina um intervalo de datas:";
	data1 = lerData("\nData incial (DD/MM/AAAA):");
	if (data1 == "") return;

	data2 = lerData("\nData final (DD/MM/AAAA):");
	if (data2 == "") return;

	dados.relacaoDeTitulos(data1, data2);
}

void menuRelatorio(DadosAbertos & dados) {
	int opcao;
	do {
		EntradaESaida::exibirMenuRelatorio();
		cin >> opcao;
		switch (opcao) {
		case 1: relacaoDeTitulos(dados); break;
		}
	} while (opcao != 5);
	
}

void menuPesquisar(DadosAbertos & dados) {
	int opcao;
	do {
		EntradaESaida::exibirMenuPesquisar();
		cin >> opcao;
		switch (opcao) {
		case 1: pesquisarNumeroDeVendas(dados); break;
		case 2: pesquisarTipoTitulo(dados); break;
		}
	} while (opcao != 3);
}

void menu(DadosAbertos & dados) {

	int opcao;

	do {
		EntradaESaida::exibirMenu();
		cin >> opcao;
		switch (opcao) {
		case 1: menuImportacao(dados); break;
		case 2: menuPesquisar(dados); break;
		case 3: menuRelatorio(dados); break;
		}
	} while (opcao != 4);

}


bool importarDados() {
	
	DadosAbertos dados;
	menu(dados);

	return true;
}

