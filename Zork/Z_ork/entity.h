#ifndef _entity_
#define _entity_
#include "string.h"
class entity{
public:
	string name, description;


	//entity destructor
	~entity(){
		name.STR = description.STR = nullptr;
	}
	//entity virtual look it function
	virtual void look_it(){
		printf("%s\n\n%s", name.STR, description.STR);
	}
};
#endif