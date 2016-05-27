#ifndef _item_
#define _item_
#include "entity.h"
struct room;
//possible item states
enum state{
	EQUIPED,
	UNEQUIPED,
	UNKNOWN,
	INCHEST
};
class item :public entity{
public:
	room*place;
	int location;
	int state;
	int live_buff;
	int attack_buff;
	//copy item constructor
	item(const string& name, const string& description, int location, int state, int live_buff, int attack_buff,room* room_added = nullptr):entity(name,description),location(location), state(state), live_buff(live_buff), attack_buff(attack_buff){
		type = ITEM;
		place = room_added;
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