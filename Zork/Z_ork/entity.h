#include"string.h"
#ifndef _entity_
#define _entity_
class entity{
public:
	string name, description;
	~entity(){
		name.STR = description.STR = nullptr;
	}
};
#endif