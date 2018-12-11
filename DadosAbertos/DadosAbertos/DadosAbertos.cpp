#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <ctime>
#include "Venda.h"
#include "DadosAbertos.h"
#include "ArquivoTexto.h"

/*Abre um arquivo de texto especificado por <nomeArquivo> e o retorna sua refer�cia pelo par�mtetro <arquivo>
Retorna: true se a abertura foi realizada com sucesso; do contr�rio false.*/
bool DadosAbertos::abrirArquivo(ArquivoTexto & arquivo, const string nomeArquivo) {
	string leitura;
	if (arquivo.abrir(nomeArquivo, LEITURA))
		return true;
	return false;
}

/*Procura a rela��o de t�tulos do tesouro direto nos dados importados, entre o per�odo <data1>  e <data2>, 
exibindo a quantidade e o valor total de cada tipo.
Retorna true caso alguma data seja encontrada, false do contr�rio*/
bool DadosAbertos::relacaoTiposDeTitulo(string data1, string data2) {
	bool achou = false;
	unsigned int i = 0;
	if (vetorVendas.empty())
		return false;

	//Percorre o vector at� encontrar registros com as posi��es com o limite inferior da pesquisa (data1)
	while (i < vetorVendas.size()-1 &&
		EntradaESaida::compararDatas(data1, vetorVendas[i].getDataVenda()) > 0) {
		i++;
	}

	
	//Se i equivaler ao tamanho do vector, significa que n�o achou a data inicial
	if (i == vetorVendas.size()-1)
		return false;


	//Vetores de 6 posi��es que conter�o o som�torio dos dados de cada um dos 6 tipos de t�tulo
	double quantidade[6] = { 0, 0, 0, 0, 0 ,0 },
		valorTotal[6] = { 0, 0, 0, 0, 0 ,0 };

	//Percorre o vector enquanto as datas sendo processandas n�o ultrapassem o limite superior da pesquisa (data2)
	for (; i < vetorVendas.size() && EntradaESaida::compararDatas(vetorVendas[i].getDataVenda(), data2) <= 0; i++) {

		/*Armazena o somat�rio de quantidades dentro vetor. Cada t�tulo � representado
		por um n�mero de 1 a 6, e as posi��es do vetor de 0 a 5, subtrai-se 1 
		para armazenar o somat�rio de um tipo de t�tulo em sua devidapc posi��o*/
		quantidade[vetorVendas[i].getTipoTitulo() - 1] += vetorVendas[i].getQuantidade();
		valorTotal[vetorVendas[i].getTipoTitulo() - 1] += vetorVendas[i].getValor();

		achou = true;

	}

	if (!achou) return false;

	//Agora exibe ao usu�rio os somat�rios dos dados de cada t�tulo
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
/*Procura a rela��o de estados civis de investidores do tesouro direto nos dados importados,
exibindo o n�mero de investidores e a m�dia de idade em cada tipo.
Retorna true caso alguma data seja encontrada, false do contr�rio*/
bool DadosAbertos::relacaoTiposEstadoCivil() {
	//Este m�todo segue a mesma logica do relacaoTiposDeTitulo
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
		sprintf_s(saida, 200, "\n\tN�mero de investidores: %d", quantidade[i]);
		cout << saida;

		if (quantidade[i] != 0) {
			sprintf_s(saida, 200, "\n\tM�dia de idade: %d ano(s)", mediaIdade[i] / quantidade[i]);
			cout << saida;
		}
		else
			cout << endl;
		cout << endl;
	}
	return true;

}

/*Procura a rela��o de regi�es brasileiras com os investidores do tesouro direto nos dados importados,
exibindo o n�mero de investidores e a m�dia de idade de cada regi�o.
Retorna true caso alguma dado seja exibido, false do contr�rio*/
bool DadosAbertos::relacaoRegioesBrasileiras() {
	const string NORTE = "Norte", SUL = "Sul", SUDESTE = "Sudeste",
		CENTRO = "Centro-Oeste", NORDESTE = "Nordeste";

	//Este m�todo segue a mesma logica do relacaoTiposDeTitulo
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

	EntradaESaida::exibirTitulo("Investidores por Regi�o");
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
			sprintf_s(saida, 100, "\n\tN�mero de investidores: %d", quantidade[indice]);
			cout << saida;

			if (quantidade[indice] != 0) {
				sprintf_s(saida, 100, "\n\tM�dia de idade : %d ano(s)", mediaIdade[indice] / quantidade[indice]);
				cout << saida;
			}
			else
				cout << endl;
			cout << endl;
				
	}
	
	return true;

}

/*Procura a rela��o de regi�es brasileiras com os investidores do tesouro direto nos dados importados,
exibindo o n�mero de investidores e a m�dia de idade de cada regi�o.
Retorna true caso alguma dado seja exibido, false do contr�rio*/
bool DadosAbertos::relacaoGeneros() {
	const string NORTE = "Norte", SUL = "Sul", SUDESTE = "Sudeste",
		CENTRO = "Centro-Oeste", NORDESTE = "Nordeste";

	//Este m�todo segue a mesma logica do relacaoTiposDeTitulo
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

	EntradaESaida::exibirTitulo("Investidores por Regi�o");
	string genero;
	for (indice = 0; indice < 3; indice++) {
		switch (indice) {
		case 0:  genero = "Masculino"; break;
		case 1:  genero = "Feminino"; break;
		default: genero = "Indefinido"; break;
		}

		cout << endl << indice + 1 << " - " << genero;
		sprintf_s(saida, 100, "\n\tN�mero de investidores: %d", quantidade[indice]);
		cout << saida;

		if (quantidade != 0) {
			sprintf_s(saida, 100, "\n\tM�dia de idade : %d ano(s)", (mediaIdade[indice] / quantidade[indice]));
			cout << saida;
		}
		
		else
			cout << endl;
		cout << endl;
	}

	return true;

}

/*Pesquisa informa��es no conjunto de dados importado quanto aos tipos de titulo,
e exibe as datas de vencimento, quantidade e valor total vendido.
Retorna true se houver algum dado a ser exibido com <data> e com <tipoTitulo> especificados.
Caso contr�rio, retorna false.*/
bool DadosAbertos::pesquisarTiposTitulo(int tipoTitulo, string data) {
	EntradaESaida::limparTela();
	EntradaESaida::exibirTitulo("Pesquisa por Tipos de T�tulo");
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

/*Pesquisa e exibe informa��es do conjunto de dados importados quanto aos tipos de titulo,
as datas de vencimento, quantidade e valor total vendido. Retorna true se algum dado tiver sido exibido,
false caso nenhum registro tenha sido obtido nesta data*/
bool DadosAbertos::pesquisarNumeroVendas(string data) {
	EntradaESaida::limparTela();
	EntradaESaida::exibirTitulo("Pesquisa sobre N�mero de Vendas");
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

/*Retorna o n�mero de objetos importados de acordo com o <tipoDeDado> informado por par�metro*/
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
	//L� e descarta a linha com os cabe�alhos
	leitura = arquivo.lerLinha(1, false);

	leitura = arquivo.lerLinha(70000, false);
	
	
	separarLinhas(leitura, tipoDeDado);

	cout << endl << numeroDeImportacoes(tipoDeDado) << endl;

	time(&fim);
	cout << difftime(fim, inicio) << " segundos\n";
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
	//dados.importarDados(DadosAbertos::VENDAS);
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

