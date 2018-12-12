#pragma once
#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H
#include "Console.h"

#include <iostream>
using namespace std;
class ProgressBar{
public:
	//ProgressBar(int tamanhoX, int tamanhoY, unsigned int fragmentos);
	ProgressBar(int x, int y, unsigned int comprimento);
	void setTamanhoX(int tamanhoX);
	void setTamanhoY(int tamanhoY);
	int getTamanhoX();
	int getTamanhoY();
	~ProgressBar();

	bool draw();
	void show(int porcentagem);

	//void show(unsigned int porcentagem);

private:
	//Bordas superiores para desenhar a barra
	const char CSE = char(0xDA), CSD = char(0xBF);
	//const char CSE = '196', CSD = '196';
	//Bordas inferiores para desenhar a barra
	const char CIE = char(0xC0), CID = char(0xD9);
	
	//Coluna e linha para desenhar a barra
	const char COL = char(0XB3), LIN = char(0xC4);

	const char BLOCO = char(0xDB);

	unsigned int comprimento;
	int x, y, porcentagemAtual;
	bool desenhado;
	Console console;
	Console obterConsole();
	//void draw(int x, int y);
};


#endif // !PROGRESS_BAR_H

