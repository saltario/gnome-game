#pragma once

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>  

#include "Hero.h"

using namespace std;

Hero getHero(int choice);

void printHero(Hero hero);

void printSeparator();