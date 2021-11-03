#include "villains.h"
#include <iostream>

using namespace std;

void villains::all_data()
{
	cout << "Имя: " << nam << endl;
	cout << "Тип оружия: " << type << endl;
	cout << "Зло совершил: " << zlo << endl;
	cout << "Где обитает: " << home << endl;
	cout << "Навыки: " << skills << endl;
}

void villains::all_set()
{
	while (1)
	{
		system("cls");
		cout << "Введите имя злодея: ";
		cin >> nam;
		if (excep(nam) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите тип оружия: ";
		cin >> type;
		if (excep(type) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите какое зло совершил(через нижнее подчёркивание): ";
		cin >> zlo;
		if (excep(zlo) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите где обитает злодей (вместо пробелов нижние подчеркивания!): ";
		cin >> home;
		if (excep(home) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите навыки злодея (через запятую): ";
		cin >> skills;
		if (excep(skills) == -2)
			continue;
		break;
	}
}

void villains::all_recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 5; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			nam = line;
			break;
		}
		case 1:
		{
			type = line;
			break;
		}
		case 2:
		{
			zlo = line;
			break;
		}
		case 3:
		{
			home = line;
			break;
		}
		case 4:
		{
			skills = line;
			break;
		}
		default:
		{
			break;
		}
		}
	}

}

void villains::all_save(ofstream& out)
{
	out << 2 << endl;
	out << nam << endl;
	out << type << endl;
	out << zlo << endl;
	out << home << endl;
	out << skills << endl << endl;
}

villains::villains()
{
	nam = "Unnamed";
	type = "No information";
	zlo = "No information";
	home = "No information";
	skills = "No information";

}

villains::villains(string n, string t, string z, string h, string s)
{
	nam = n;
	type = t;
	zlo = z;
	home = h;
	skills = s;
}

villains::villains(const villains& Vill) :
	nam(Vill.nam), type(Vill.type), zlo(Vill.zlo), home(Vill.home), skills(Vill.skills) {}

villains::~villains() {}

int villains::excep(string line)
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
			cout << "Данное поле не может быть пустым!!!" << endl;
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





