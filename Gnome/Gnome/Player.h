#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

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
	int heroId;
	string Name;
	Hero hero;

public:

	Player();
	~Player();

	int getLevel();
	void setLevel(int Level);

	int getHeroId();
	void setHeroId(int heroId);

	int getStars();
	void setStars(int Stars);

	string getName();
	void setName(string Name);

	Hero getPlayerHero();
	void setPlayerHero(int heroId);
	void setPlayerHero(Hero hero);

	void printPlayer();
	void printProfile();

	void savePlayer();
	void loadPlayer();

};