#pragma once

#include <string>
#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
	int Level;
	int Stars;
	string Name;

public:

	Player();
	~Player();

	int getLevel();
	void setLevel(int Level);

	int getStars();
	void setStars(int Stars);

	string getName();
	void setName(string Name);
};