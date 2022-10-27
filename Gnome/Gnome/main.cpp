#include "conio.h"
#include "Game.h"
#include "Resources.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");

	prepareWindow();

	Game game = Game();

	game.startMenu();
	game.menu();

	_getch();

	return EXIT_SUCCESS;
}
