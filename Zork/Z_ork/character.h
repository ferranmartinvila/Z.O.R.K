
#ifndef _character_
#define _character_
#include "entity.h"
#include "map.h"
#include "string.h"
#include "item.h"
#include "chest.h"
#include "dinamic_array.h"
#include "string.h"
#include <stdio.h>
class character :public entity{
public:
	int pos_x, pos_y, inroom;
	//the next room you focus the action
	int next_room;
	//the direction x & y where is the next room
	int direction[2];
	//the exit that is between your room and the next room
	int exit_used;
	//the object and the chest you focus
	int object_focused, chest_focused;

	//is true if your equipation cell is free
	bool equipation_state;
	vector<item*> bag;
	item* equipation;
	//stats
	unsigned int live;
	unsigned int attack;
	character(){
		pos_x = pos_y = inroom = exit_used = next_room = direction[0] = direction[1] = 0;
		name = "Earl the knight";
		description = "You are a brave knight from a far village called Gandar there all the people respects you but here in Bloody Sword nobody knows you.";
		live = 150;
		attack = 5;
	}
	//move instruction
	void apply_go_instruction(const map&, const vector<string>&);
	//look instruction
	void apply_look_instruction(vector<item*>&, const map&,vector<string>&);
	//open/close instruction
	void apply_door_instruction(map&, const vector<string>&);
	//pick/drop instruction
	void apply_pickdrop_instruction(vector<item*>&, map&, const vector<string>&);
	//equip/unequip instruction
	void apply_equipment_instruction(vector<item*>&, const vector<string>&);
	//put/get instruction
	void apply_chest_instruction(vector<chest*>&, vector<item*>&, const vector<string>&);
};
#endif