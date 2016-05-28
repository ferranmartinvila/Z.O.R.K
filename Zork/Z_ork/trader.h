#ifndef _TRADER_
#define _TRADER_
#include "NPC.h"
#include "rooms.h"
#include "item.h"
class trader :public npc{
public:
	trader(const string& name, const string& description, unsigned int live_points, unsigned int attack, room* location_added, item* object) :npc(name, description, live_points, attack){
		data.push_back(object);
		location = location_added;
		type = TRADER;
	}
	void Update();
	void Talk(const vector<string> instruction);
	void Trade();
};
#endif