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
	item(const string& cpy_name, const string& cpy_description, int location, int state, int live_buff, int attack_buff):location(location), state(state), live_buff(live_buff), attack_buff(attack_buff){
		name = cpy_name;
		description = cpy_description;
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