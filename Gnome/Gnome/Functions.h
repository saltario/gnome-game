#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "Constants.h"

using namespace std;
using namespace constants;

void prepareWindow();
void setWindowAttribute();
void setConsoleAttribute();
void setTitle();

void coutCentered(string text, bool isNewLine = true);
void showConsoleCursor(bool showFlag);
void setConsoleColor(int textColor);
void setCursorPosition(int line = 0, int column = 0);

int getCursorPositionX();
int getCursorPositionY();
