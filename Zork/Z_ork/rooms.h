#ifndef _rooms_
#define _rooms_
#include"entity.h"
#include"string.h"
class room :public entity{
public:
	//Constructor
	room(const string& name, const string& description) :entity(name, description){ type = ROOM; }
};

#endif