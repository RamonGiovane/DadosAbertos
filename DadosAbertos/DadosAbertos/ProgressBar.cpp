#include "ProgressBar.h"

ProgressBar::ProgressBar(int x, int y, unsigned int comprimento){
	this->x = x;
	this->y = y;
	this->comprimento = comprimento;
	porcentagemAtual = 0;
	desenhado = false;
}

void ProgressBar::setTamanhoX(int tamanhoX){
	this->x = tamanhoX;
}

void ProgressBar::setTamanhoY(int tamanhoY){
	this->y = tamanhoY;
}

int ProgressBar::getTamanhoX(){
	return x;
}

int ProgressBar::getTamanhoY(){
	return y;
}

ProgressBar::~ProgressBar(){
}

bool ProgressBar::draw(){
	unsigned int i;
	
	Console::gotoxy(x, y);
	cout << CSE;
	//cout << comprimento;
	for (i = x-8; i <= comprimento-1; i++)
		cout << LIN;
	cout << CSD;
	
	Console::gotoxy(x, y+1);
	cout << COL;
	Console::gotoxy(x, y + 2);
	cout << CIE;
	for (i = x-8; i <= comprimento -1; i++)
		cout << LIN;
	cout << CID;
	
	Console::gotoxy(comprimento+9, y + 1);
	cout << COL;
	desenhado = true;
	return true;
}

void ProgressBar::show(int porcentagem) {
	//Console::setCodePage(850);
	setlocale(LC_ALL, ".850");
	int pos =  porcentagem * comprimento / 100;
	if(desenhado == false)
		draw();

	/*if (pos == 100) {
		Console::gotoxy(comprimento / 2 + 10, y + 1);
		cout << porcentagem << "%"; return;
	}*/

	if (porcentagem <= porcentagemAtual) {
		Console::setCodePage(1252);
		return;
	}

	Console::setCodePage(850);
	Console::gotoxy(x+pos, y+1);
	cout <<	BLOCO;

	Console::gotoxy(comprimento/2 + 10, y+1);
	cout << porcentagem + 2 << "%";
	porcentagemAtual = pos;

	
}

Console ProgressBar::obterConsole(){
	return console;
}
