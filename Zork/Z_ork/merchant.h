#ifndef _MERCHANT_
#define _MERCHANT_
#include "NPC.h"
#include "rooms.h"
#include "item.h"
class merchant :public npc{
public:
	merchant(const string& name, const string& description, unsigned int live_points, unsigned int attack, room* location_added, item* object, item* object_1, item* object_2) :npc(name, description, live_points, attack){
		data.push_back(object);
		data.push_back(object_1);
		data.push_back(object_2);
		location = location_added;
		type = MERCHANT;
	}
	void Update();
	void Talk(const vector<string> instruction);
};
#endif