#ifndef _entity_
#define _entity_
#include"string.h"
class entity{
public:
	string name, description;
	~entity(){
		name.STR = description.STR = nullptr;
	}
	virtual void look_it(){
		printf("%s\n%s\n", name.STR, description.STR);
	}
};
#endif