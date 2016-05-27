#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
struct room;
class creature :public entity{
public:
	unsigned int live_points;
	unsigned int attack = 0;
	room* location;

public:
	creature(const string& name, const string& description, unsigned int live_points, unsigned int attack) :entity(name, description), live_points(live_points), attack(attack){}

	//Functions
	//void Update();
};




#endif