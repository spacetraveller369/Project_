#include <iostream>
#include <cstdlib>
#include <windows.h>
#pragma comment(lib, "winmm.lib")



using namespace std;

void Menu();
void MenuSub1();
void MenuSub2();
void MenuSub3();
int Find(string key, string arr[], int size);

int main()
{
	 
	SetConsoleTitle(TEXT("Телефонная книга")); 
	

	system("color 02");
	setlocale(LC_ALL, "RU");

	{
		const wchar_t* path = L"C:\\Users\\User\\Desktop\\polskaya-korova.wav";

		PlaySound(path, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	}

	cout << "\n";
	cout << "\t\t ТЕЛЕФОННАЯ КНИГА" << "\n"; cout << "\n";

	char yesNo;

	const int SIZE = 10;
	string names[SIZE]{ "Ilona", "Eugene", "Alina","0","0","0","0","0","0","0" };
	string tel[SIZE]{ "380971234567", "3809612345667", "380501234567","0","0","0","0","0","0","0" };
	string find, name, phone;
	int count, index, choice, choiceMenu, choiceSubMenu1, choiceSubMen2, choiceSubMen3;;

	do
	{
		yesNo = 'N';

		Menu(); // вывод меню 1) cписок контактов | 2) поиск контактов | 3) добавить контакт	
		cout << "Введите номер меню: "; cin >> choiceMenu; cout << "\n";

		if (choiceMenu == 1) //меню выбора 1
		{
			MenuSub1();

			if (names[0].size() > 1 && tel[0].size() > 1)
			{
				for (int i = 0; i < SIZE; i++)
				{
					if (names[i].size() > 1 && tel[i].size() > 1)
					{
						count = i + 1;
						cout << count << ") " << "Имя: " << names[i] << " Телефон: " << tel[i]; cout << "\n";
					}
				}
			}
			else
			{
				cout << "\n";
				cout << "Cписок контактов пуст. Неоходимо добавить контакты." << "\n";
				cout << "Хотите ли вы выйти в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;
			}

		}
		else if (choiceMenu == 2) //меню выбора 2
		{
			MenuSub2();

			cout << "Вариант 1: Введите 1 если хотите поиск по имени"; cout << "\n";
			cout << "Вариант 2: Введите 2 если хотите поиск по номеру"; cout << "\n";
			cout << "Введите вариант: "; cin >> choice;

			if (choice == 1)
			{
				cout << "Введите имя: "; cin >> find;
				index = Find(find, names, SIZE);

				if (index == -1)
				{
					cout << "\n";
					cout << "Такого имени нет!"; cout << "\n"; cout << "\n";
					cout << "Хотите ли вы вернуться в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;
					continue;
				}
				else
				{
					cout << "\n";
					cout << names[index] << " : " << tel[index]; cout << "\n"; cout << "\n";
					cout << "Хотите ли вы вернуться в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;
					continue;
				}
			}
			if (choice == 2)
			{
				cout << "Введите номер: "; cin >> find;
				index = Find(find, tel, SIZE);

				if (index == -1)
				{
					cout << "\n";
					cout << "Такого номера нет!"; cout << "\n"; cout << "\n";
					cout << "Хотите ли вы вернуться в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;
					continue;
				}
				else
				{
					cout << "\n";
					cout << names[index] << " : " << tel[index]; cout << "\n"; cout << "\n";
					cout << "Хотите ли вы вернуться в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;
					continue;
				}
			}
			else
			{
				cout << "\n";
				cout << "Такого варианта нет!" << "\n"; cout << "\n";
				cout << "Хотите ли вы вернуться в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;
				continue;
			}
		}
		else if (choiceMenu == 3) //меню выбора 3
		{
			do
			{
				MenuSub3();

				cout << "Введите имя: "; cin >> name;

				for (int i = 0; i < SIZE; i++)
				{
					if (names[i].size() == 1)
					{
						names[i] = name;
						break;
					}
				}
				cout << "Введите телефон: "; cin >> phone;

				for (int i = 0; i < SIZE; i++)
				{
					if (tel[i].size() == 1)
					{
						tel[i] = phone;
						break;
					}
				}
				cout << "\n";
				cout << "Хотите ли вы еще добавить контакт?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;

			} while (yesNo == 'Y' || yesNo == 'y');
		}

		cout << "\n";
		cout << "Хотите ли вы вернуться в главное меню?" << " Введите 'Y' или 'N'" << "\n"; cin >> yesNo;

	} while (yesNo == 'Y' || yesNo == 'y');

	system("pause");
}

void Menu() //Функция вывода меню
{
	for (int i = 0; i < 18; i++)
	{
		cout << " __ ";
	}

	cout << "\n";
	cout << "\n";
	cout << "|  1) СПИСОК КОНТАКТОВ  |  2) ПОИСК КОНТАКТОВ  |  3) ДОБАВИТЬ КОНТАКТ  |" << "\n";

	for (int i = 0; i < 18; i++)
	{
		cout << " __ ";
	}
	cout << "\n"; cout << "\n";
}

void MenuSub1() // меню 1
{
	for (int i = 0; i < 6; i++)
	{
		cout << " __ ";
	}

	cout << "\n";
	cout << "\n";
	cout << "| 1) СПИСОК КОНТАКТОВ  |" << "\n";

	for (int i = 0; i < 6; i++)
	{
		cout << " __ ";
	}
	cout << "\n"; cout << "\n"; cout << "\n";
}

void MenuSub2() // меню 2
{
	for (int i = 0; i < 6; i++)
	{
		cout << " __ ";
	}

	cout << "\n";
	cout << "\n";
	cout << "| 2) ПОИСК КОНТАКТОВ  |" << "\n";

	for (int i = 0; i < 6; i++)
	{
		cout << " __ ";
	}
	cout << "\n"; cout << "\n"; cout << "\n";
}

void MenuSub3() // меню 3
{
	for (int i = 0; i < 6; i++)
	{
		cout << " __ ";
	}

	cout << "\n";
	cout << "\n";
	cout << "| 3) ДОБАВИТЬ КОНТАКТ  |" << "\n";

	for (int i = 0; i < 6; i++)
	{
		cout << " __ ";
	}
	cout << "\n"; cout << "\n"; cout << "\n";
}

int Find(string key, string arr[], int size) //Функция поиска
{
	for (int i = 0; i < size; i++)
	{
		if (key == arr[i])
		{
			return i;
		}
	}
	return -1;
}