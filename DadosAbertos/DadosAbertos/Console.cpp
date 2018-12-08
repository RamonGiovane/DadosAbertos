#include <cstdlib>
#include <Windows.h>
#include "console.h"

Background Console::currentBackground = Background::BLACK;
Foreground Console::currentForeground = Foreground::LIGHT_GRAY;

/* Posiciona o cursor em uma coordenada de tela definida por x (coluna) e y (linha).
    A coordenada de tela inicial é 0,0. */
void Console::gotoxy(int x, int y) {
	// Estrutura que define as coordenadas de tela.
	COORD posicaoCursor;

	// Define as coordenadas de tela.
	posicaoCursor.X = x;
	posicaoCursor.Y = y;

	// Obtém o handle do dispositivo padrão de saída de dados.
	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	// Posiciona o cursor na coordenada de tela. 
	SetConsoleCursorPosition(standardOutput, posicaoCursor);
}

void Console::setCodePage(long int codePage) {
	SetConsoleOutputCP(codePage);
	SetConsoleCP(codePage);
}

// Define a cores do texto (foreground) e de fundo (background).
void Console::textColor(Background background, Foreground foreground) {
	// // Obtém o handle do dispositivo padrão de saída de dados.
	HANDLE standardOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	// Define a cores do texto e de fundo.
	SetConsoleTextAttribute(standardOutput, static_cast<int>(background) + static_cast<int>(foreground));


	// Salva as cores atuais.
	currentBackground = background;
	currentForeground = foreground;
}

// Limpa a tela do console.
void Console::clrscr() {
	system("cls");
}
Background Console::getCurrentBackground() {
	return currentBackground;
}

Foreground Console::getCurrentForeground() {
	return currentForeground;
}