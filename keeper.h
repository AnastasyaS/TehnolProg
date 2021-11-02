#pragma once
#include "monsters.h"
#include "heroes.h"
#include "villains.h"
#include "goodhero.h"
#include "element.h"

using namespace std;

class Keeper
{
private:
	element* tail;
	int size;
public:
	Keeper();
	Keeper(element* Tail, int Size);
	Keeper(const Keeper& keeper);//конструктор копирования
	int get_size();
	int pop();
	void push(heroes* obj);
	int save_all();
	int recover_all();
	bool isempty();
	void show();
	~Keeper();
};
