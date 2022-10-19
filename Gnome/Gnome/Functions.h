#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "Constants.h"

using namespace std;
using namespace constants;

void printSeparator();
void printMenuSeparator();
void printEmptySeparator();
void printSeparatorForBattle();
void printSeparatorForShop();

void coutCentered(string text, bool isNewLine = true);
void showConsoleCursor(bool showFlag);
void setWindowAttribute();
void setConsoleColor(int textColor);
void setCursorPosition(int line, int column);

int cursorX();
int cursorY();

void showHelp(string helpText);
