
#ifndef _character_
#define _character_
#include "entity.h"
#include "map.h"
#include "string.h"
#include "item.h"
#include "chest.h"
#include "vector.h"
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
		pos_x = pos_y = exit_used = direction[0] = direction[1] = 0;
		inroom = 10;
		next_room = 10;
		name = "Earl the knight";
		description = "You are a brave knight from a far village called Gandar, there all the people respects you, but here in Bloody Sword nobody knows you.";
		live = 150;
		attack = 5;
		type = CHARACTER;
	}
	~character(){
		/*
		name.erase();
		description.erase();
		direction[0] = NULL;
		direction[1] = NULL;
		equipation = nullptr;
		bag.clean();*/
	}
	//move instruction
	void apply_go_instruction(const map&, const vector<string>&);
	
	//look instruction
	void apply_look_instruction(vector<item*>&, const map&,vector<string>&);
	
	//open door instruction
	bool apply_open_door_instruction(map&, const vector<string>&);
	
	//close door instruction
	bool apply_close_door_instruction(map&, const vector<string>&);
	
	//pick instruction
	bool apply_pick_instruction(vector<item*>&, map&);
	
	//drop instruction
	bool apply_drop_instruction(vector<item*>&, map&);
	
	//equip instruction
	bool apply_equip_instruction(vector<item*>&);
	
	//unequip instruction
	bool apply_unequip_instruction(vector<item*>&);

	//put instruction
	bool apply_put_instruction(vector<chest*>&, vector<item*>&);
	
	//get instruction
	bool apply_get_instruction(vector<chest*>&, vector<item*>&);
};
#endif