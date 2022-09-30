#include "Hero.h"

Hero::Hero() {

	this->Health = 0;
	this->Damage = 0;
	this->Name = "Name";
	this->Price = 0;

}
Hero::Hero(int Health, int Damage, string Name, int Price)
{
	this->Health = Health;
	this->Damage = Damage;
	this->Name = Name;
	this->Price = Price;
}
Hero::~Hero()
{
}


int Hero::getHealth()
{
	return Health;
}

void Hero::setHealth(int Health)
{
	if (Health != 0) this->Health = Health;
	else cout << "Health is NULL";
}

int Hero::getDamage()
{
	return Damage;
}

void Hero::setDamage(int Damage)
{
	if (Damage != 0) this->Damage = Damage;
	else cout << "Damage is NULL";
}

string Hero::getName()
{
	return Name;
}

void Hero::setName(string Name)
{
	this->Name = Name;
}

int Hero::getPrice()
{
	return Price;
}

void Hero::setPrice(int Price)
{
	if (Price != 0) this->Price = Price;
	else cout << "Price is NULL";
}