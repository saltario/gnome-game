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

void Hero::setupHero(int choice)
{
	switch (choice)
	{
		// хп макс 300
		// дамаг макс 25
		// цена макс 200

	case 1:
		this->Damage = 7;
		this->Health = 300;
		this->Name = "Азагхал";
		this->Price = 10;
		break;

	case 2:
		this->Damage = 25;
		this->Health = 110;
		this->Name = "Балин";
		this->Price = 200;
		break;

	case 3:
		this->Damage = 200;
		this->Health = 12;
		this->Name = "Бифур";
		this->Price = 150;
		break;

	case 4:
		this->Damage = 16;
		this->Health = 180;
		this->Name = "Гроин";
		this->Price = 100;
		break;

	case 5:
		this->Damage = 19;
		this->Health = 150;
		this->Name = "Дис";
		this->Price = 10;
		break;

	case 6:
		this->Damage = 21;
		this->Health = 135;
		this->Name = "Телхар";
		this->Price = 50;
		break;
		
	default:
		this->Damage = 0;
		this->Health = 0;
		this->Name = "Test";
		this->Price = 0;
		break;
	}
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

