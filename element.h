#pragma once
#include "heroes.h"

class element
{
private:
	heroes* obj;
	element* prev;
public:
	heroes* get_obj();
	element* get_prev();
	void set_obj(heroes* Obj);
	void set_prev(element* Prev);
};
