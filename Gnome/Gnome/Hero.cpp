#include "Hero.h"

Hero::Hero() {

	this->health = 0;
	this->damage = 0;
	this->name = "Name";
	this->price = 0;

}
Hero::Hero(int Health, int Damage, string Name, int Price)
{
	this->health = Health;
	this->damage = Damage;
	this->name = Name;
	this->price = Price;
}
Hero::Hero(int heroId)
{
	switch (heroId)
	{
		// хп макс 300
		// дамаг макс 25
		// цена макс 200

	case 1:
		this->damage = 7;
		this->health = 300;
		this->name = "Азагхал";
		this->price = 10;
		break;

	case 2:
		this->damage = 25;
		this->health = 110;
		this->name = "Балин";
		this->price = 200;
		break;

	case 3:
		this->damage = 200;
		this->health = 12;
		this->name = "Бифур";
		this->price = 150;
		break;

	case 4:
		this->damage = 16;
		this->health = 180;
		this->name = "Гроин";
		this->price = 100;
		break;

	case 5:
		this->damage = 19;
		this->health = 150;
		this->name = "Дис";
		this->price = 10;
		break;

	case 6:
		this->damage = 21;
		this->health = 135;
		this->name = "Телхар";
		this->price = 50;
		break;

	default:
		this->damage = 0;
		this->health = 0;
		this->name = "Test";
		this->price = 0;
		break;
	}
}

Hero::~Hero() {}

int Hero::getHealth() { return health; }
void Hero::setHealth(int Health) { this->health = Health; }

int Hero::getDamage() { return damage; }
void Hero::setDamage(int Damage) { this->damage = Damage; }

string Hero::getName() { return name; }
void Hero::setName(string Name) { this->name = Name; }

int Hero::getPrice() { return price; }
void Hero::setPrice(int Price) { this->price = Price; }

Hero Hero::getHeroById(int heroId)
{
	return Hero(heroId);
}
void Hero::printHero()
{
	printSeparator();

	string str1;
	string str2 = " |";

	cout.fill(' ');
	SetConsoleTextAttribute(hConsole, lightGreenTextColor);

	////////////////////////////////
	str1 = "| Имя: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << getName();

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Здоровье: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(getHealth());

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Урон: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(getDamage());

	cout.width(str2.length());
	cout << str2 << endl;

	////////////////////////////////

	str1 = "| Цена: ";
	cout.width(heroTextWidth);
	cout << str1;

	cout.width(heroTextWidth - str2.length());
	cout << to_string(getPrice());

	cout.width(str2.length());
	cout << str2 << endl;

	printSeparator();
}
