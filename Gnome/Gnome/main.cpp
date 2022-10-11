#include "conio.h"
#include "Game.h"

#include <windows.h>



int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}

using namespace std;

Game game = Game();

int main()
{
	setlocale(LC_ALL, "Rus");
	
	setWindowAttribute();
	game.initGame();

	_getch();
	return 0;
}
