#pragma once
#include <string>
#include "heroes.h"

using namespace std;

class goodhero : public heroes
{
private:
    string name;
    string skills;
    string typeweapon;
    
public:
    virtual void all_data() override;
    virtual void all_set() override;//ovveride для переопределения
    virtual void all_recover(ifstream& in) override;
    virtual void all_save(ofstream& out) override;
    goodhero();
    goodhero(string n, string s, string t);//крнструктор строки
    goodhero(const goodhero& goo); //конструктор копирования
    ~goodhero();
    int excep(string line);
   
};
