#include "monsters.h"
#include <iostream>
#include <cstring>

using namespace std;

void monsters::all_data()
{
	cout << "Кличка: " << clichka << endl;
	cout << "Описание внешнего вида: " << description << endl;
	
}

void monsters::all_set()
{
	while (1)
	{
		system("cls");
		cout << "Введите кличку монстра: ";
		cin >> clichka;
		if (excep(clichka) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите описание внешнего вида(через запятую): ";
		cin >> description;
		if (excep(description) == -2)
			continue;
		break;
	}
	
}

void monsters::all_recover(ifstream& fin)//восстановление
{
	string line;
	for (int i = 0; i < 2; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			clichka = line;
			break;
		}
		case 1:
		{
			description = line;//описание
			break;
		}
		
		default:
		{
			break;
		}
		}
	}

}

void monsters::all_save(ofstream& out)
{
	out << 1 << endl;
	out << clichka << endl;
	out << description << endl;
	
}

monsters::monsters()
{
	clichka = "Нет названия";
	description = "Нет названия";
	
}

monsters::monsters(string clichka, string description)
{
	this->clichka = clichka;
	this->description = description;
	
}

monsters::monsters(const monsters& Mons) : clichka(Mons.clichka), description(Mons.description) {}
int monsters::excep(string line)
{
	try
	{
		if (line.empty())
			throw - 2;
	}
	catch (int a)
	{
		switch (a)
		{
		case -2:
		{
			cout << "Ввод нельзя оставлять пустым!!!" << endl;
			system("pause");
			return -2;
		}
		default:
		{
			cout << "Что-то пошло не так!" << endl;
			system("pause");
			break;
		}
		}
	}
	return 0;
}
monsters::~monsters() {}


