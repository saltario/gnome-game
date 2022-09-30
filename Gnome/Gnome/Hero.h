#pragma once

#include <string>
#include <iostream>

using namespace std;

class Hero
{
private:
	int Health;
	int Damage;
	string Name;
	int Price;

public:

	Hero();
	Hero(int Health, int Damage, string Name, int Price);
	~Hero();

	int getHealth();
	void setHealth(int Health);

	int getDamage();
	void setDamage(int Damage);

	string getName();
	void setName(string Name);

	int getPrice();
	void setPrice(int Price);
};