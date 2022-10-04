#include "Functions.h"

void printSeparator() {

	SetConsoleTextAttribute(hConsole, blueTextColor);

	cout.setf(ios::left);
	cout.width(separatorTextWidth);
	cout.fill('=');
	cout << "=" << endl;
}

void printMenuSeparator() {

	cout.setf(ios::left);
	cout.width(SeparatorMenuWidth);
	cout.fill('-');
	cout << "-" << endl;
}

void printEmptySeparator()
{
	cout.setf(ios::left);
	cout.width(SeparatorWidth);
	cout.fill(' ');
	cout << " ";
}

void printSeparatorForBattle() {

	SetConsoleTextAttribute(hConsole, blueTextColor);

	cout.setf(ios::left);
	cout.width(separatorTextWidth);
	cout.fill('=');
	cout << "=";

	printEmptySeparator();

	SetConsoleTextAttribute(hConsole, cyanTextColor);

	cout.setf(ios::left);
	cout.width(separatorTextWidth);
	cout.fill('=');
	cout << "=" << endl;
}

void printLogo()
{
	SetConsoleTextAttribute(hConsole, redTextColor);

	cout << R"(
	      ________                                  
	     /  _____/   ____    ____    _____    ____  
	    /   \  ___  /    \  /  _ \  /     \ _/ __ \ 
	    \    \_\  \|   |  \(  <_> )|  Y Y  \\  ___/ 
	     \______  /|___|  / \____/ |__|_|  / \___  >
	            \/      \/               \/      \/ 
)" << '\n';
}

void printBattle()
{
	SetConsoleTextAttribute(hConsole, redTextColor);

	cout << R"(
	      __________         __    __  .__          
	      \______   \_____ _/  |__/  |_|  |   ____  
	       |    |  _/\__  \\   __\   __\  | _/ __ \ 
	       |    |   \ / __ \|  |  |  | |  |_\  ___/ 
	       |______  /(____  /__|  |__| |____/\___  >
	              \/      \/                     \/ 
)" << '\n';
}

void printShop()
{
	SetConsoleTextAttribute(hConsole, redTextColor);

	cout << R"(
		     _________.__                   
		    /   _____/|  |__   ____ ______  
		    \_____  \ |  |  \ /  _ \\____ \ 
		    /        \|   Y  (  <_> )  |_> >
		   /_______  /|___|  /\____/|   __/ 
		           \/      \/       |__|    
)" << '\n';
}

void printSettings()
{
	SetConsoleTextAttribute(hConsole, redTextColor);

	cout << R"(
	  _________       __    __  .__                      
	 /   _____/ _____/  |__/  |_|__| ____    ____  ______
	 \_____  \_/ __ \   __\   __\  |/    \  / ___\/  ___/
	 /        \  ___/|  |  |  | |  |   |  \/ /_/  >___ \ 
	/_______  /\___  >__|  |__| |__|___|  /\___  /____  >
	        \/     \/                   \//_____/     \/   
)" << '\n';
}

void coutCentered(string text) 
{
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO();
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo);
	COORD NewSBSize = lpScreenInfo->dwSize;

	if (NewSBSize.X > text.size()) {
		int newpos = ((NewSBSize.X - text.size()) / 2);
		for (int i = 0; i < newpos; i++) cout << " ";
	}
	cout << text << endl;
}

void showConsoleCursor(bool showFlag)
{
	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void setWindowAttribute() {

	HWND consoleWindow = GetConsoleWindow();
	RECT rect;

	GetWindowRect(consoleWindow, &rect);
	MoveWindow(consoleWindow, rect.left, rect.top, windowHeight, windowWidth, TRUE);
}
