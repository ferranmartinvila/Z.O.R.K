#include "entity.h"
#include "map.h"
#include "string.h"
#include "item.h"
#include"dinamic_array.h"
#include"string.h"
#include <stdio.h>
#ifndef _character_
#define _character_
class character :public entity{
public:
	int pos_x, pos_y, inroom, next_room, direction[2], exit_used;
	vector<item>bag;
	item equipation;

	character(){

	}

	
	//move instruction
	void apply_go_instruction(const map&, const vector<string>&);
	//look instruction
	void apply_look_instruction(const vector<item*>&, const map&, const vector<string>&);
	//open/close instruction
	void apply_door_instruction(map&, const vector<string>&);
	//pick/drop instruction in progress
	void apply_pickdrop_instruction(vector<item*>&, map&, const vector<string>&);
};
#endif