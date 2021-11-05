#pragma once

#include "monsters.h"
#include "heroes.h"
#include "goodhero.h"
#include "villains.h"
#include "keeper.h"
#include <iostream>

using std::cout;
using std::cin;

short answer;

bool check_input()
{
	if (!cin.good())
	{
		cout << "Вы вводите неправильные данные! Попробуйте еще раз!" << endl;
		system("pause");
		cin.clear();
		while (cin.get() != '\n');
		return false;
	}
	return true;
}

void menu()
{
	while (1)
	{
		system("cls");
		cout << "Выберите пункт из предложенных ниже:" << endl << endl;
		cout << "1. Добавить элемент в очередь" << endl;
		cout << "2. Удалить элемент из очереди" << endl;
		cout << "3. Сохранить данные в файл" << endl;
		cout << "4. Загрузить данные из файла" << endl;
		cout << "5. Показать данные на экране" << endl;
		cout << "6. Выход из программы" << endl;
		cout << "Введите ваш ответ: ";
		cin >> answer;
		if (!check_input())
			continue;
		break;
	}
}

void add_menu(Keeper* keeper)
{
	short answer2;
	while (1)
	{
		system("cls");
		cout << "Выберите объект для добавления в очередь:" << endl;
		cout << "1. Хорошие герои" << endl;
		cout << "2. Злодеи" << endl;
		cout << "3. Монстры" << endl;
		cout << "4. Выход" << endl;
		cout << "Ваш ответ: ";
		cin >> answer2;
		if (!check_input())
			continue;
		switch (answer2)
		{
		case 1:
		{
			heroes* obj = new goodhero;
			obj->all_set();
			keeper->push(obj);
			continue;
		}
		case 2:
		{
			heroes* obj = new villains;
			obj->all_set();
			keeper->push(obj);
			continue;
		}
		case 3:
		{
			heroes* obj = new monsters;
			obj->all_set();
			keeper->push(obj);
			continue;
		}
		case 4:
		{
			break;
		}
		default:
		{
			cout << "Нет такого пункта меню! Попробуйте еще раз!" << endl;
			system("cls");
			continue;
		}
		}
		break;
	}
}

void starting()
{
	Keeper* keeper = new Keeper;
	while (1)
	{
		menu();
		switch (answer)
		{
		case 1:
		{
			add_menu(keeper);
			continue;
		}
		case 2:
		{
			if (!(keeper->pop()))
			{
				cout << "Удаление невозможно! Очередь пуста!" << endl;
				system("pause");
			}
			continue;
		}
		case 3:
		{
			system("cls");
			int answ;
			if (keeper->get_size() == 0)
			{
				cout << "Очередь пуста, запись невозможна!" << endl;
				system("pause");
				continue;
			}
			cout << "Хотите добавить в файл(1) или перезаписать(2)?" << endl;
			cin >> answ;
			if (!check_input())
			{
				cout << "Вы вводите неверные данные! Попробуйте еще раз!" << endl;
				system("pause");
				continue;
			}
			switch (answ)
			{
			case 1:
			{
				if (keeper->save_all())
				{
					cout << "Сохранение прошло успешно!" << endl;
					system("pause");
				}
				break;
			}
			case 2:
			{
				if (remove("base.txt") != 0)
					cout << "Ошибка перезаписи";
				else
				{
					if (keeper->save_all())
						cout << "Сохранение прошло успешно!" << endl;
				}
				system("pause");
				break;
			}
			default:
			{
				cout << "Неверные данные! Проверьте работоспособность программы!" << endl;
				system("pause");
				break;
			}
			}
			continue;
		}
		case 4:
		{
			if ((keeper->recover_all()) != -1)
				cout << "Восстановление прошло успешно!" << endl;
			else
				cout << "Файл пуст!" << endl;
			system("pause");
			continue;
		}
		case 5:
		{
			system("cls");
			keeper->show();
			system("pause");
			continue;
		}
		case 6:
		{
			break;
		}
		default:
		{
			cout << "Нет такого пункта меню! Попробуйте еще раз!" << endl;
			system("pause");
			continue;
		}
		}
		break;
	}
}
