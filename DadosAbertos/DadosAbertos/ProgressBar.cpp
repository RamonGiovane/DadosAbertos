#include "ProgressBar.h"

ProgressBar::ProgressBar(int tamanhoX, int tamanhoY, unsigned int fragmentos){
	this->tamanhoX = tamanhoX;
	this->tamanhoY = tamanhoY;
	this->fragmentos = fragmentos;
}

void ProgressBar::setTamanhoX(int tamanhoX){
	this->tamanhoX = tamanhoX;
}

void ProgressBar::setTamanhoY(int tamanhoY){
	this->tamanhoY = tamanhoY;
}

int ProgressBar::getTamanhoX(){
	return tamanhoX;
}

int ProgressBar::getTamanhoY(){
	return tamanhoY;
}

ProgressBar::~ProgressBar(){
}

void ProgressBar::show(int x, int y, unsigned int porcentagem){
	Console console = obterConsole();
	char bordaSuperiorEsquerda = char(0xDA), bordaSuperiorDireita = char(0xBF);
	char bordaInferiorEsquerda = char(0xC0), bordaInferiorDireita = char(0xD9);
	char coluna = char(0XB3), linha = char(0xC4);
	console.setCodePage(850);
	
	//Desenhando o medidor da barra
	console.gotoxy(x, y);
	cout << bordaSuperiorEsquerda;
	for (int j = 1; j <= tamanhoX-1; j++)
			cout << linha;
	cout << bordaSuperiorDireita;
	console.gotoxy(x, y+1); 
	for (int j = 0; j < tamanhoY; j++) {
		cout << coluna;

		//Posicionando à direita da tela
		console.gotoxy(tamanhoX + x, y + j + 1);
		cout << coluna;
		
		//Posicionando à esquerda da tela de novo
		console.gotoxy(x, y + j + 1);
	}
	cout << bordaInferiorEsquerda;
	for (int j = 1; j <= tamanhoX-1; j++)
		cout << linha;
	cout << bordaInferiorDireita << endl;

	//console.setCodePage(1252);

	console.gotoxy(tamanhoX/2, tamanhoY);
	console.textColor(Background::CYAN, Foreground::WHITE);
	cout << "100%";
	char progresso = char(0xDB);
	console.textColor(Background::CYAN,Foreground::RED);
	console.gotoxy(x+1, y+1);
	for (int j = 1; j < tamanhoX; j++)
		cout << "";
	cout << endl << endl << endl;
}

Console ProgressBar::obterConsole(){
	return console;
}
