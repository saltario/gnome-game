#pragma once

#include <iostream>
#include <string>

#include "Hero.h"
#include "Functions.h"
#include "Constants.h"

using namespace std;
using namespace constants;

class Player
{
private:
	int Level;
	int Stars;
	string Name;
	Hero hero;

public:

	Player();
	~Player();

	int getLevel();
	void setLevel(int Level);

	int getStars();
	void setStars(int Stars);

	string getName();
	void setName(string Name);

	Hero getPlayerHero();
	void setPlayerHero(int heroId);
	void setPlayerHero(Hero hero);

	void printPlayer();

};