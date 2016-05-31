#ifndef _TALKER_
#define _TALKER_
#include "NPC.h"
#include "rooms.h"
#include "item.h"
class talker :public npc{
public:
	talker(const string& name, const string& description, unsigned int live_points, room* location_added, unsigned int attack = 5) :npc(name, description, live_points, attack){
		location = location_added;
		type = TALKER;
	}
	void Update();
	void Talk(const vector<string> instruction);
};
#endif