#include "Functions.h"

void prepareWindow()
{
	setWindowAttribute();
	setConsoleAttribute();
	setTitle();
}

void setWindowAttribute()
{
	HWND consoleWindow = GetConsoleWindow();
	RECT rect;

	GetWindowRect(consoleWindow, &rect);
	MoveWindow(consoleWindow, rect.left, rect.top, windowWidth, windowHeight, TRUE);
}

void setConsoleAttribute()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT rect = { 0, 0, consoleWidth, consoleHeight };
	SetConsoleWindowInfo(hConsole, TRUE, &rect);
}

void setTitle()
{
	SetConsoleTitleW(L"√ном: Ѕитва двух королевств");
}

void coutCentered(string text, bool isNewLine)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);
	COORD NewSBSize = lpScreenInfo->dwSize;

	if (NewSBSize.X > text.size()) {
		int newpos = ((NewSBSize.X - text.size()) / 2);
		for (int i = 0; i < newpos; i++) cout << " ";
	}

	if (isNewLine) { cout << text << endl; }
	else { cout << text; }
}

void showConsoleCursor(bool showFlag)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void setConsoleColor(int textColor) 
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, textColor);
}

void setCursorPosition(int line, int column)
{
	COORD coord;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	coord.X = column;
	coord.Y = line;

	SetConsoleCursorPosition(hConsole, coord);
}

int getCursorPositionX()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return -1;

	return csbi.dwCursorPosition.X;
}

int getCursorPositionY()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return -1;

	return csbi.dwCursorPosition.Y;
}


