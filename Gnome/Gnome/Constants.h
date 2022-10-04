#pragma once

#include <windows.h>

namespace constants {

	// Получаем окно консоли
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	// Цвета текста для стандартизации
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

	const int separatorTextWidth = 24;
	const int SeparatorWidth = 21;
	const int SeparatorMenuWidth = 10;
	const int heroTextWidth = 12;
	const int heroValueWidth = 5;
	const int playerTextWidth = 8;

	const int windowWidth = 800;
	const int windowHeight = 600;

}
