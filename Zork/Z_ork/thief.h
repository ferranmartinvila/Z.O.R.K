#ifndef _THIEF_
#define _THIEF_
#include "NPC.h"
class thief :public npc{
public:
	room*last_room = nullptr;
	unsigned int exit_choosed = 0;
public:
	thief(const string& name, const string& description, unsigned int live_points, unsigned int attack, room* location_added) :npc(name, description, live_points, attack){
		location = location_added;
		type = THIEF;
		last_room = location;
	}
	~thief(){
		last_room = nullptr;
		creature::~creature();
	}

	void Attack();
	void Update();
};
#endif