#include "keeper.h"
#include <iostream>
#include <fstream>
#include <typeinfo>

Keeper::Keeper() { tail = nullptr; size = 0; }

Keeper::Keeper(element* Tail, int Size) { tail = Tail; size = Size; }

Keeper::Keeper(const Keeper& keeper) : size(keeper.size), tail(keeper.tail) {}

Keeper::~Keeper()
{
	while (size > 0)
	{
		element* obj = tail;
		tail = obj->get_prev();
		delete[] obj;
		size--;
	}
	tail = NULL;
}

int Keeper::get_size() { return size; }

int Keeper::pop()
{
	element* tmp = this->tail;

	if (!(this->isempty()))
		return 0;

	if (this->size == 1)
	{
		tmp->set_obj(nullptr);
		tail = nullptr;
		size = 0;
		return 1;
	}

	while (tmp->get_prev()->get_prev() != 0)
		tmp = tmp->get_prev();

	element* pop = tmp->get_prev();
	tmp->set_prev(nullptr);
	delete pop;
	size--;
	return 1;
}

void Keeper::push(heroes* obj)
{
	element* newElem = new(element);
	newElem->set_prev(this->tail);
	newElem->set_obj(obj);
	this->tail = newElem;
	size++;
}

int Keeper::save_all()
{
	int Size = size;
	ofstream out("base.txt", std::ios::app);
	element* tmp;

	if (out.is_open())
	{
		for (int i = Size; i > 0; i--)
		{
			tmp = tail;
			for (int j = 0; j < (i - 1); j++)
				tmp = tmp->get_prev();
			tmp->get_obj()->all_save(out);
		}
	}
	else
	{
		cout << "Файл не открывается или повреждён!" << endl;
		system("pause");
		return -1;
	}
	out.close();

	return 1;
}

int Keeper::recover_all()
{
	string line;
	int res;

	ifstream fin("base.txt");

	if ((this->get_size()) > 0)
	{
		while ((this->get_size()) > 0)
			this->pop();
	}

	if (fin.is_open())
	{
		if (fin.peek() == EOF)
			return -1;
		
	}
	else
	{
		cout << "Файл не открыт :( " << endl;
		system("pause");
		return -1;
	}
	fin.close();
	return 1;
}

bool Keeper::isempty() { return size > 0 ? true : false; }

void Keeper::show()
{
	int Size = size;
	if (!isempty())
	{
		cout << "Очередь пустая!" << endl;
		return;
	}
	element* temp = tail;
	while (temp->get_prev() != nullptr)
	{
		cout << Size << ". ";
		temp->get_obj()->all_data();
		cout << endl;
		temp = temp->get_prev();
		Size--;
	}
	cout << Size << ". ";
	temp->get_obj()->all_data();
}
