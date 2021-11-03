/*
	Для злодея:
	nam-имя,
	type-тип оружия,
	zlo-какое зло совершил,
	home-где обитает,
	skills-навыки.
*/
#pragma once
#include <string>
#include "heroes.h"

using namespace std;

class villains : public heroes
{
private:
	string nam;
	string type;
	string zlo;
	string home;
	string skills;
public:
	virtual void all_data() override;
	virtual void all_set() override;
	virtual void all_recover(ifstream& in) override;
	virtual void all_save(ofstream& out) override;
	villains();
	villains(string n, string t, string z, string h, string s);
	villains(const villains& villains);
	~villains();
	int excep(string line);
};
