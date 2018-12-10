#ifndef TESTAR_ARQUIVO_TEXTO
#define TESTAR_ARQUIVO_TEXTO

#include "ArquivoTexto.h"
#include <vector>
#include "DadosAbertos.h"
/* Cria um arquivo texto no diret�rio atual. Os par�metros s�o:

	1. nomeArquivo: nome do arquivo texto;
	2. arquivoTexto: objeto ArquivoTexto;
	3. texto: vetor de objetos string com o conte�do a ser escrito no arquivo;
	4: tamanho: tamanho do vetor de objetos string que ser� escrito no arquivo.
*/
void escrever(string nomeArquivo, ArquivoTexto &arquivoTexto, string texto[], size_t tamanho);

/* Adiciona novas linhas de texto no arquivo do diret�rio atual. Os par�metros s�o:

	1. nomeArquivo: nome do arquivo texto;
	2. arquivoTexto: objeto ArquivoTexto;
	3. texto: vetor de objetos string com o conte�do a ser escrito no arquivo;
	4: tamanho: tamanho do vetor de objetos string que ser� escrito no arquivo.
*/
void adicionar(string nomeArquivo, ArquivoTexto &arquivoTexto, string texto[], size_t tamanho);

/* Abre e exibe o arquivo texto no console. Os par�metros s�o:

	1. msg: mensagem de texto referente ao conte�do a ser exibido;
	2. nomeArquivo: nome do arquivo texto;
	3. arquivoTexto: objeto ArquivoTexto.
*/
void exibir(string msg, string nomeArquivo, ArquivoTexto &arquivoTexto);

/* Exemplifica como realizar um acesso aleat�rio (relativo) com arquivo texto em que todas as
 * linhas possuem o mesmo comprimento (n�mero de caracteres).
 */
void arquivoTextoComTamanhoFixo();

// Testa o funcionamento dos m�todos da classe ArquivoTexto.
//int testarArquivoTexto(vector <Dado>& vetor);
#endif