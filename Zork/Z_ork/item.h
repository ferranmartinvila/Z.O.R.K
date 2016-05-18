#ifndef _item_
#define _item_
#include "entity.h"
//possible item states
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
	//copy item constructor
	item(const string& cpy_name, const string& cpy_description,int cpy_location,int cpy_state,int cpy_live,int cpy_attack){
		name = cpy_name;
		description = cpy_description;
		location = cpy_location;
		state = cpy_state;
		live_buff = cpy_live;
		attack_buff = cpy_attack;
		type = ITEM;
	}
	//default item constructor
	/*~item(){
		
		name.erase();
		description.erase();
	}*/
	//item look it vitual function
	void look_it(){
		printf("%s\n%s\nSTATS:\nlive upgrade[+%i]\nattack upgrade[+%i]\n", name.get_string(), description.get_string(),live_buff,attack_buff);
	}
};
#endif