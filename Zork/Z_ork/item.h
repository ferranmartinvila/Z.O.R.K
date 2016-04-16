#ifndef _item_
#define _item_
#include "entity.h"
enum state{
	EQUIPED,
	UNEQUIPED,
	UNKNOWN

};
class item :public entity{
public:
	int location;
	int state;
	

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