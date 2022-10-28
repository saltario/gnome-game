#include "Hero.h"

Hero::Hero() {

	this->Health = 0;
	this->Damage = 0;
	this->Name = "Name";
	this->Price = 0;
	this->Class = 1;

}
Hero::Hero(int Health, int Damage, string Name, int Price, int Class)
{
	this->Health = Health;
	this->Damage = Damage;
	this->Name = Name;
	this->Price = Price;
	this->Class = Class;
}
Hero::Hero(int heroId)
{
	switch (heroId)
	{
		// хп макс 300
		// дамаг макс 25
		// цена макс 200

		// 1 - Обычный
		// 2 - Редкий
		// 3 - Легендарный
		// 4 - Эпический

	case 1:
		this->Damage = 70;
		this->Health = 100;
		this->Name = "Азагхал";
		this->Price = 10;
		this->Class = 4;
		break;

	case 2:
		this->Damage = 25;
		this->Health = 110;
		this->Name = "Балин";
		this->Price = 200;
		this->Class = 2;
		break;

	case 3:
		this->Damage = 20;
		this->Health = 12;
		this->Name = "Бифур";
		this->Price = 150;
		this->Class = 3;
		break;

	case 4:
		this->Damage = 16;
		this->Health = 180;
		this->Name = "Гроин";
		this->Price = 100;
		this->Class = 4;
		break;

	case 5:
		this->Damage = 19;
		this->Health = 150;
		this->Name = "Дис";
		this->Price = 10;
		this->Class = 1;
		break;

	case 6:
		this->Damage = 21;
		this->Health = 135;
		this->Name = "Телхар";
		this->Price = 50;
		this->Class = 3;
		break;

	default:
		this->Damage = 0;
		this->Health = 0;
		this->Name = "Test";
		this->Price = 0;
		this->Class = 1;
		break;
	}
}
Hero::~Hero() {}

int Hero::getHealth() { return Health; }
void Hero::setHealth(int Health) { this->Health = Health; }

int Hero::getDamage() { return Damage; }
void Hero::setDamage(int Damage) { this->Damage = Damage; }

string Hero::getName() { return Name; }
void Hero::setName(string Name) { this->Name = Name; }

int Hero::getPrice() { return Price; }
void Hero::setPrice(int Price) { this->Price = Price; }

int Hero::getClass() { return Class; }
void Hero::setClass(int Class) { this->Class = Class; }

Hero Hero::getHeroById(int heroId)
{
	return Hero(heroId);
}

