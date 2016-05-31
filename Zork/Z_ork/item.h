#ifndef _item_
#define _item_
#include "entity.h"
#include "rooms.h"
//possible item states
enum state{
	EQUIPED,
	UNEQUIPED,
	UNKNOWN,
	IN_NPC,
	INCHEST
};
class item :public entity{
public:
	room*place;
	int state;
	int live_buff;
	int attack_buff;
	unsigned int price;
	//copy item constructor
	item(const string& name, const string& description,int state, int live_buff, int attack_buff, room* room_added = nullptr, unsigned int price = 0) :entity(name, description), state(state), live_buff(live_buff), attack_buff(attack_buff),price(price){
		type = ITEM;
		place = room_added;
	}
	//default item constructor
	~item(){
		entity::~entity();
		place = nullptr;

	}
	//item look it vitual function
	void look_it(){
		printf("%s\n%s\nSTATS:\nlive upgrade[+%i]\nattack upgrade[+%i]\n", name.get_string(), description.get_string(),live_buff,attack_buff);
	}
};
#endif