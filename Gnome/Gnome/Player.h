#pragma once

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