
#ifndef _character_
#define _character_
#include "entity.h"
#include "map.h"
#include "string.h"
#include "item.h"
#include"dinamic_array.h"
#include"string.h"
#include <stdio.h>
class character :public entity{
public:
	int pos_x, pos_y, inroom, next_room, direction[2], exit_used,object_focused;
	vector<item*>bag;
	item* equipation;

	character(){

	}

	
	//move instruction
	void apply_go_instruction(const map&, const vector<string>&);
	//look instruction
	void apply_look_instruction(const vector<item*>&, const map&, const vector<string>&);
	//open/close instruction
	void apply_door_instruction(map&, const vector<string>&);
	//pick/drop instruction
	void apply_pickdrop_instruction(vector<item*>&, map&, const vector<string>&);
	//equip/unequip instruction
	void apply_equipment_instruction(vector<item*>&, const vector<string>&);
};
#endif