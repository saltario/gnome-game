#include "conio.h"
#include "Game.h"

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
