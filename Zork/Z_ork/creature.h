#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
#include "rooms.h"
enum STATE{
	RUN,
	ATTACK,
	TALK,
	TRADE,
	SELL,
	BUY,
	DEAD,
	NOTHING
};

class creature :public entity{
public:
	//live
	int live_points;
	int total_live;
	//attack
	unsigned int attack = 0;
	//creature localtion
	room* location;
	//true alive false dead
	bool alive = true;
	//Creature current action
	STATE action = NOTHING;
public:
	//Constructor
	creature(const string& name, const string& description, unsigned int live_points, unsigned int attack) :entity(name, description), live_points(live_points), attack(attack),total_live(live_points){}
	//Destructor
	~creature(){
		location = nullptr;
		entity::~entity();
	}


	bool heal(){
		//not regen totally
		if (live_points < total_live-5){
			printf("\n%s regen %i live points!\n", name.get_string(), total_live-live_points);
			live_points = total_live;
		}
		return true;
	}
};




#endif