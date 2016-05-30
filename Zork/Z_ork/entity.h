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
	TRADER,
	SOILDER,
	MERCHANT,
	THIEF,
	TALKER,
	UNDEFINED
};

class entity{
public:
	//entity data
	type type;
	string name;
	string description;
	list<entity*> data;

public:

	//entity constructor
	entity(const string& name, const string& description) :name(name), description(description){}
	//entity destructor
	~entity(){
		name.erase();
		description.erase();
		data.clean();
	}


	//Functions
	virtual void look_it(){
		printf("%s\n\n%s", name.get_string(), description.get_string());
	}
	virtual void Update(){}

};
#endif