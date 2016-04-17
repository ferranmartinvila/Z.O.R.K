#ifndef _item_
#define _item_
#include "entity.h"
enum state{
	EQUIPED,
	UNEQUIPED,
	UNKNOWN,
	INCHEST
};
class item :public entity{
public:
	int location;
	int state;
	

	item(const string& cpy_name, const string& cpy_description, const int& cpy_location,const int& cpy_state){
		name = cpy_name;
		description = cpy_description;
		location = cpy_location;
		state = cpy_state;
	}
	item(){
		name.STR = description.STR = nullptr;
	}
};
#endif