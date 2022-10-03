#pragma once

#include <iostream>
#include <string>

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

public:

	Player();
	Player(string Name);
	~Player();

	int getLevel();
	void setLevel(int Level);

	int getStars();
	void setStars(int Stars);

	string getName();
	void setName(string Name);

	void printPlayer();

};