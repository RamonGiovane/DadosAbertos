#ifndef CONSOLE_H
#define CONSOLE_H

// Cores de texto (foreground)
enum class Foreground {
	BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHT_GRAY, DARK_GRAY, LIGTH_BLUE, LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED, LIGHT_MAGENTA, YELLOW, WHITE
};

// Cores de fundo (background)
enum class Background {
	BLACK, BLUE = 16, GREEN = 32, CYAN = 48, RED = 64, MAGENTA = 80, BROWN = 96, LIGHT_GRAY = 112, DARK_GRAY = 128, LIGHT_BLUE = 144, LIGHT_GREEN = 160, LIGHT_CYAN = 176,
	LIGHT_RED = 192, LIGHT_MAGENTA = 208, YELLOW = 224, WHITE = 240
};

class Console {
public:
	/* Posiciona o cursor em uma coordenada de tela definida por x (coluna) e y (linha).
		A coordenada de tela inicial é 0,0. */
	static void gotoxy(int x, int y);

	static void setCodePage(long int codePage);

	// Define a cores do texto (foreground) e de fundo (background).
	static void textColor(Background background, Foreground foreground);

	// Limpa a tela do console.
	static void clrscr();

	static Background getCurrentBackground();
	static Foreground getCurrentForeground();

private:
	static Background currentBackground;
	static Foreground currentForeground;
};
#endif