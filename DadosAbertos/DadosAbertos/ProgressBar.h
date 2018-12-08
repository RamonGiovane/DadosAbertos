#pragma once
#ifndef PROGRESS_BAR_H
#define PROGRESS_BAR_H
#include "Console.h"

#include <iostream>
using namespace std;
class ProgressBar{
public:
	ProgressBar(int tamanhoX, int tamanhoY, unsigned int fragmentos);
	void setTamanhoX(int tamanhoX);
	void setTamanhoY(int tamanhoY);
	int getTamanhoX();
	int getTamanhoY();
	~ProgressBar();

	void show(int x, int y, unsigned int porcentagem);

	//void show(unsigned int porcentagem);

private:
	int tamanhoX, tamanhoY;
	unsigned int fragmentos;
	Console console;
	Console obterConsole();
};


#endif // !PROGRESS_BAR_H

