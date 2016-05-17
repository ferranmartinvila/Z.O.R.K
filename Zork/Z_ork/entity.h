#ifndef _entity_
#define _entity_
#include "string.h"
#include "simple_list.h"
enum type{
	CHARACTER,
	MAP,
	ROOM,
	EXIT,
	CHEST,
	ITEM,
	UNDEFINED
};

class entity{
public:
	//entity data
	unsigned int type;
	string name;
	string description;
	list<entity*> data;
public:
	//entity destructor
	~entity(){
		name.erase();
		description.erase();
		data.clean();
	}
	//entity virtual look it function
	virtual void look_it(){
		printf("%s\n\n%s", name.get_string(), description.get_string());
	}
	//virtual bool update();
};
#endif