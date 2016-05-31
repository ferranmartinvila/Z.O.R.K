#ifndef _SOILDER_
#define _SOILDER_
#include "NPC.h"
class soldier :public npc{
public:
	soldier(const string& name, const string& description, unsigned int live_points, unsigned int attack, room* location_added) :npc(name, description, live_points, attack){
		location = location_added;
		type = SOILDER;
	}
	void Update();
};
#endif