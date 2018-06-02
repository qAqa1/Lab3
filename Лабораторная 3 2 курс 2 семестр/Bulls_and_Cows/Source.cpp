/*Фантров A Бис-21
Быки и коровы*/
#include<iostream>
#include<vector>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

string input;//предварительный ввод
int number[4];//загаданные цифры
int use[4];//введённые цифры

bool check()//один ход игры
{
	int Bulls = 0;
	int Cows = 0;
	for (int x = 0; x < 4; x++)
	{
		if (use[x] == number[x])
		{
			Bulls++;
			if (Bulls == 4)
			{
				cout << "Быков = 4, Коров = 0";
				return(true);
			}
		}
		else
		{
			for (int y = 0; y < 4; y++)
			{
				if (use[x] == number[y])
				{
						Cows++;
				}
			}
		}
	}
	cout << "Быков = " << Bulls << ", Коров = " << Cows << endl << endl;
	return(false);
}

bool digit()//проверка на что,введены только числа
{
	for (int x = 0; x < 4; x++)
	{
		if ((input[x] < 48) || (input[x] > 57))
		{
			return(false);
		}
	}
		return(true);
}

bool not_repeat()//проверка на что,введенные числа не повторяются
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (input[x] == input[y])
			{
				if (x != y)
				{
					return(false);
				}
			}
		}
	}
	return(true);
}

void vvod()//проверка коректности ввода
{
	cin.sync();
	cin >> input;
	if (input == "lose")
	{
		cout << endl << endl << "Загаднанное слово: ";
		for (int x = 0; x < 4; x++)
		{
			cout<<number[x];
		}
		cout << endl;
		system("pause");
		exit(0);
	}
	if (input.length() != 4)
	{
		cout << "Чисел должно быть 4! Повторите ввод:";
		vvod();
	}
	else
	{
		if (digit() == true)
		{
			if (not_repeat() == true)
			{
				return;
			}
			else
			{
				cout << "Числа не должны повторяться!:";
				vvod();
			}
		}
		else
		{
			cout << "Введите только цифры!:";
			vvod();
		}
	}
}

void main()
{
	setlocale(LC_ALL, "russian");
	srand(time(NULL));
	do {
		system("cls");
		cout << "Введите lose вместо числа, чтобы закончить партию" << endl << endl;;
		vector<int>digits;
		for (int x = 0; x < 10; x++)
		{
			digits.push_back(x);
		}
		
		for (int x = 0; x < 4; x++)
		{
			int random = rand() % digits.size();
			number[x] = digits[random];
			digits.erase(digits.begin() + random);
		}

		int x = 0;
		do {
			x++;
			cout << "Ход " << x;
			cout <<endl<<"Введите числа: ";
			vvod();
			for (int x = 0; x < 4; x++)
			{
				use[x] = input[x] - 48;//превращение char в int
			}
		} while (!check());//пока не победа


	cout << endl << "Вы выйграли! Нажмите escape для выхода или любую другую клавишу для новой игры." << endl;
	} while (_getch() != 27);
}