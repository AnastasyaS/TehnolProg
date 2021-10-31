#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class heroes //базовый класс
{
public:
	virtual void all_data() = 0; //чистая виртуальная функция 
	virtual void all_set() = 0;
	virtual void all_save(ofstream& out) = 0;
	virtual void all_recover(ifstream& in) = 0;
	virtual ~heroes();
};
