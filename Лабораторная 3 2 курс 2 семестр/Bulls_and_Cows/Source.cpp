/*������� A ���-21
���� � ������*/
#include<iostream>
#include<vector>
#include <conio.h>
#include <ctime>
#include <string>

using namespace std;

string input;//��������������� ����
int number[4];//���������� �����
int use[4];//�������� �����

bool check()//���� ��� ����
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
				cout << "����� = 4, ����� = 0";
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
	cout << "����� = " << Bulls << ", ����� = " << Cows << endl << endl;
	return(false);
}

bool digit()//�������� �� ���,������� ������ �����
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

bool not_repeat()//�������� �� ���,��������� ����� �� �����������
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

void vvod()//�������� ����������� �����
{
	cin.sync();
	cin >> input;
	if (input == "lose")
	{
		cout << endl << endl << "����������� �����: ";
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
		cout << "����� ������ ���� 4! ��������� ����:";
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
				cout << "����� �� ������ �����������!:";
				vvod();
			}
		}
		else
		{
			cout << "������� ������ �����!:";
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
		cout << "������� lose ������ �����, ����� ��������� ������" << endl << endl;;
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
			cout << "��� " << x;
			cout <<endl<<"������� �����: ";
			vvod();
			for (int x = 0; x < 4; x++)
			{
				use[x] = input[x] - 48;//����������� char � int
			}
		} while (!check());//���� �� ������


	cout << endl << "�� ��������! ������� escape ��� ������ ��� ����� ������ ������� ��� ����� ����." << endl;
	} while (_getch() != 27);
}