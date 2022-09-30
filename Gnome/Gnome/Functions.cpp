#include "Functions.h"

// ОБЯЗАТЕЛЬНО!
// 
// Все переменные, которые могут меняться во всей прогремме выносить в глобальные для данного файла
// Чтобы не нужно было везде менять если вдруг придется
// Проще поменять в одном месте
// Для примера вынес окно консоли, чтобы каждый раз не создавать новый объект
// Для примера вынес цвета текста, так проще, чем потом вспоминать, что 9 - это голубой цвет
//

// Получаем окно консоли
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// Цвета текста для стандартизации
int blueTextColor = 9;		// Голубой
int greenTextColor = 10;	// Зеленый

							// Ширина поля ввода для текста для выравнивания
int separatorTextWidth = 20;
int heroTextWidth = 10;

// Получаем персонажа по его номеру
// 
Hero getHero(int choice)
{
	switch (choice)
	{
		/*
		ПРАВИЛЬНО
		*/
	case 1:
		return Hero(10, 10, "Test", 0);

	case 2:
		return Hero(20, 30, "Luse", 0); // Тест

										// TODO: Дописать еще 10 героев


										/*
										КАК ГОВНО
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
										СТАНДАРТ
										*/
	default:
		return Hero();
		break;
	}
}

// Печатаем нашего персонажа на экране
// 
void printHero(Hero hero)
{
	// Печатаем разделить 
	printSeparator();

	// Уставливаем текст консоли в зеленый
	SetConsoleTextAttribute(hConsole, greenTextColor);

	// Для форматированного вывода необходимо использовать флаги и свойства
	// Для каждой строки задается отдельно
	// * .setf(ios::left) - выравнивание по левому краю
	// * .width - ширина поля ввода
	// * .fill - заполнитель пустого пространства
	//
	// Форматированный вывод доступен только для строки, поэтому int, double и т.д обрамляем в строку to_string(*твоя переменная*)
	// Пример: to_string(hero.getHealth())
	// 

	cout.fill(' ');
	cout.width(heroTextWidth);

	cout << "Имя: " << hero.getName() << endl;

	cout.width(heroTextWidth);
	cout << "Здоровье: " << to_string(hero.getHealth()) << endl;

	cout.width(heroTextWidth);
	cout << "Урон: " << to_string(hero.getDamage()) << endl;

	cout.width(heroTextWidth);
	cout << "Цена: " << to_string(hero.getPrice()) << endl;

	printSeparator();
}

// Печатаем разделитель на экране
// 
void printSeparator() {

	// Уставливаем текст консоли в голубой
	SetConsoleTextAttribute(hConsole, blueTextColor);

	// Выводим 20 раз =
	cout.setf(ios::left);
	cout.width(separatorTextWidth); // 20
	cout.fill('=');
	cout << "=" << endl;
}