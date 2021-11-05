/*
	Для монстра определено:
	кличка,
	описание
*/

#pragma once
#include <string>
#include "heroes.h"

using namespace std;

class monsters : public heroes
{
private:
	string clichka;
	string description;
	
public:
	virtual void all_data() override;
	virtual void all_set() override;
	virtual void all_recover(ifstream& in) override;
	virtual void all_save(ofstream& out) override;
	monsters();
	monsters(string clichka, string description);
	monsters(const monsters& Mons);
	int excep(string line);
	~monsters();
	
	
};
