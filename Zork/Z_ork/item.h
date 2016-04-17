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
	int live_buff;
	int attack_buff;

	item(const string& cpy_name, const string& cpy_description,int cpy_location,int cpy_state,int cpy_live,int cpy_attack){
		name = cpy_name;
		description = cpy_description;
		location = cpy_location;
		state = cpy_state;
		live_buff = cpy_live;
		attack_buff = cpy_attack;
	}
	item(){
		name.STR = description.STR = nullptr;
	}
};
#endif