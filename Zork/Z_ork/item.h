#ifndef _item_
#define _item_
#include "entity.h"
class item :public entity{
public:
	int location;
	int state;
	enum state{
		EQUIPED,
		UNEQUIPED,
		UNKNOWN

	};

	item(const string& cpy_name, const string& cpy_description, const int& cpy_location){
		name = cpy_name;
		description = cpy_description;
		location = cpy_location;
		state = UNKNOWN;
	}
	item(){
		name.STR = description.STR = nullptr;
	}
};
#endif