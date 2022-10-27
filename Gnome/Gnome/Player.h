#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>

#include "Hero.h"

using namespace std;

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

	void savePlayer();
	void loadPlayer();

	void setEnemy();

};