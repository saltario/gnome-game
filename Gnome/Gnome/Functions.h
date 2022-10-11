#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include "Constants.h"

using namespace std;
using namespace constants;

void printSeparator();
void printMenuSeparator();
void printEmptySeparator();
void printSeparatorForBattle();
void printSeparatorForShop();

void coutCentered(string text);
void showConsoleCursor(bool showFlag);
void setWindowAttribute();
void setConsoleColor(int textColor);
void setConsoleCursorPosition(int column, int line);
