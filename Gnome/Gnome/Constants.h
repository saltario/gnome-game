#pragma once

#include <windows.h>

namespace constants {

	////////////////// COLORS //////////////////
	const int deepBlueTextColor = 1;
	const int greenTextColor = 2;
	const int redTextColor = 4;
	const int purpleTextColor = 5;
	const int deppYellowTextColor = 6;
	const int whiteTextColor = 7;
	const int greyTextColor = 8;
	const int blueTextColor = 9;
	const int lightGreenTextColor = 10;
	const int cyanTextColor = 11;
	const int lightRedTextColor = 12;
	const int pinkTextColor = 13;
	const int yellowTextColor = 14;
	const int lightWhiteTextColor = 10;

	const int playerColor = yellowTextColor;
	const int heroColor = yellowTextColor;

	const int playerFrameColor = pinkTextColor;
	const int enemyFrameColor = deppYellowTextColor;

	////////////////// END COLORS //////////////////

	////////////////// SEPARATOR //////////////////

	const int separatorTextWidth = 24;
	const int SeparatorWidth = 21;
	const int SeparatorMenuWidth = 10;

	////////////////// END SEPARATOR //////////////////

	////////////////// WINDOW //////////////////

	const int windowWidth = 600;
	const int windowHeight = 800;

	const int consoleWidth = 69;
	const int consoleHeight = 46;

	////////////////// END WINDOW //////////////////

	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	const int heroTextWidth = 12;
	const int heroValueWidth = 5;
	const int playerTextWidth = 8;
}
