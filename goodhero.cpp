#include "goodhero.h"
#include <iostream>
#include <cstring>
using namespace std;

void goodhero::all_data()
{
	cout << "Имя: " << name << endl;
	cout << "Навыки: " << skills << endl;
	cout << "Тип оружия: " << typeweapon << endl;
	
}

void goodhero::all_set()
{
	while (1)
	{
		system("cls");
		cout << "Введите имя героя: ";
		cin >> name;
		if (excep(name) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите навыки героя (без пробелов!): ";
		cin >> skills;
		if (excep(skills) == -2)
			continue;
		break;
	}
	while (1)
	{
		system("cls");
		cout << "Введите тип оружия: ";
		cin >> typeweapon;
		if (excep(typeweapon) == -2)
			continue;
		break;
	}
	
}

void goodhero::all_recover(ifstream& fin)
{
	string line;
	for (int i = 0; i < 3; i++)
	{
		getline(fin, line);
		switch (i)
		{
		case 0:
		{
			name = line;
			break;
		}
		case 1:
		{
			skills = line;
			break;
		}
		case 2:
		{
			typeweapon = line;
			break;
		}
		
		default:
		{
			break;
		}
		}
	}
}



void goodhero::all_save(ofstream& out)
{
	out << 3 << endl;
	out << name << endl;
	out << skills << endl;
	out << typeweapon << endl;
	
}

goodhero::goodhero()
{
	name = "No information";
	skills = "No information";
	typeweapon = "No information";
	
}

goodhero::goodhero(string n, string s, string t )
{
	name = n;
	skills = s;
	typeweapon = t;
	
}

goodhero::goodhero(const goodhero& goo) :
	name(goo.name), skills(goo.skills), typeweapon(goo.typeweapon) {}// мы имеем прямой доступ к членам объекта goo,т.к мы находимся в классе goodhero

goodhero::~goodhero() {}

int goodhero::excep(string line)//exep исключение
{
	try//строка пуста,тогда
	{
		if (line.empty())
			throw - 2; //возращение об ошибке
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
