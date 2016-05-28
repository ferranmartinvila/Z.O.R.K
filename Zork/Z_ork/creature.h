#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
struct room;
enum STATE{
	RUN,
	ATTACK,
	TALK,
	TRADE,
	SELL,
	BUY,
	NOTHING
};

class creature :public entity{
public:
	//live
	unsigned int live_points;
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
	creature(const string& name, const string& description, unsigned int live_points, unsigned int attack) :entity(name, description), live_points(live_points), attack(attack){}
};




#endif