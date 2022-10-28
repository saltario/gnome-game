#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <ctime>

#include "Hero.h"
#include "Colors.h"

using namespace std;
using namespace colors;

class Player
{
private:
	int Level;
	int Stars;
	int heroId;
	string Name;
	Hero hero;
	int frameColor;

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

	int getFrameColor();
	void setFrameColor(int frameColor);

	Hero getPlayerHero();
	void setPlayerHero(int heroId);
	void setPlayerHero(Hero hero);

	void savePlayer();
	void loadPlayer();

	void setEnemy();
};