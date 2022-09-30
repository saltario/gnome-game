#include "Functions.h"

// �����������!
// 
// ��� ����������, ������� ����� �������� �� ���� ��������� �������� � ���������� ��� ������� �����
// ����� �� ����� ���� ����� ������ ���� ����� ��������
// ����� �������� � ����� �����
// ��� ������� ����� ���� �������, ����� ������ ��� �� ��������� ����� ������
// ��� ������� ����� ����� ������, ��� �����, ��� ����� ����������, ��� 9 - ��� ������� ����
//

// �������� ���� �������
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// ����� ������ ��� ��������������
int blueTextColor = 9;		// �������
int greenTextColor = 10;	// �������

							// ������ ���� ����� ��� ������ ��� ������������
int separatorTextWidth = 20;
int heroTextWidth = 10;

// �������� ��������� �� ��� ������
// 
Hero getHero(int choice)
{
	switch (choice)
	{
		/*
		���������
		*/
	case 1:
		return Hero(10, 10, "Test", 0);

	case 2:
		return Hero(20, 30, "Luse", 0); // ����

										// TODO: �������� ��� 10 ������


										/*
										��� �����
										*/

										/*case 2:
										{
										Hero hero = Hero();
										hero.setDamage(20);
										hero.setHealth(200);
										hero.setName("govno kod");
										hero.setPrice(500);
										return hero;
										}
										*/
										/*
										��������
										*/
	default:
		return Hero();
		break;
	}
}

// �������� ������ ��������� �� ������
// 
void printHero(Hero hero)
{
	// �������� ��������� 
	printSeparator();

	// ����������� ����� ������� � �������
	SetConsoleTextAttribute(hConsole, greenTextColor);

	// ��� ���������������� ������ ���������� ������������ ����� � ��������
	// ��� ������ ������ �������� ��������
	// * .setf(ios::left) - ������������ �� ������ ����
	// * .width - ������ ���� �����
	// * .fill - ����������� ������� ������������
	//
	// ��������������� ����� �������� ������ ��� ������, ������� int, double � �.� ��������� � ������ to_string(*���� ����������*)
	// ������: to_string(hero.getHealth())
	// 

	cout.fill(' ');
	cout.width(heroTextWidth);

	cout << "���: " << hero.getName() << endl;

	cout.width(heroTextWidth);
	cout << "��������: " << to_string(hero.getHealth()) << endl;

	cout.width(heroTextWidth);
	cout << "����: " << to_string(hero.getDamage()) << endl;

	cout.width(heroTextWidth);
	cout << "����: " << to_string(hero.getPrice()) << endl;

	printSeparator();
}

// �������� ����������� �� ������
// 
void printSeparator() {

	// ����������� ����� ������� � �������
	SetConsoleTextAttribute(hConsole, blueTextColor);

	// ������� 20 ��� =
	cout.setf(ios::left);
	cout.width(separatorTextWidth); // 20
	cout.fill('=');
	cout << "=" << endl;
}