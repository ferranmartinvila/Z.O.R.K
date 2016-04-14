#include "entity.h"
#ifndef _item_
#define _item_
class item :public entity{
public:
	int location;

	item(const string& cpy_name, const string& cpy_description, const int cpy_location){
		name = cpy_name;
		description = cpy_description;
		location = cpy_location;
	}
	item(){
		name.STR = description.STR = nullptr;
	}
};
#endif