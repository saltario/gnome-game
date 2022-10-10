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
	int level;
	int stars;
	string name;
	Hero hero;

public:

	Player();
	~Player();

	int getLevel();
	void setLevel(int level);

	int getStars();
	void setStars(int stars);

	string getName();
	void setName(string name);

	Hero getPlayerHero();
	void setPlayerHero(int heroId);
	void setPlayerHero(Hero hero);

	void printPlayer();

};