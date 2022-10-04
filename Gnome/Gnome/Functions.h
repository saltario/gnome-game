#pragma once

#include <iostream>
#include <iomanip>
#include "Hero.h"
#include "Player.h"
#include "Constants.h"

using namespace std;
using namespace constants;

void printSeparator();
void printMenuSeparator();
void printEmptySeparator();
void printSeparatorForBattle();

void printLogo();
void printBattle();
void printShop();
void printSettings();

void coutCentered(string text);
void showConsoleCursor(bool showFlag);
void setWindowAttribute();
