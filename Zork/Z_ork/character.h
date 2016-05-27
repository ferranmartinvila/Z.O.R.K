
#ifndef _character_
#define _character_
#include "entity.h"
#include "map.h"
#include "string.h"
#include "item.h"
#include "chest.h"
#include "vector.h"
#include "string.h"
#include "creature.h"
#include "rooms.h"
#include <stdio.h>
class character :public creature{
public:

	//Bad data
	item* equipation;
	unsigned int in_bag = 0;

	//Functional pointers
	room* next_room_ad = nullptr;
	exit* exit_focused = nullptr;
	item* object_focused_ad = nullptr;
	chest* chest_focused_ad = nullptr;


public:

	character() :creature("Earl the knight", "You are a brave knight from a far village called Gandar, there all the people respects you, but here in Bloody Sword nobody knows you.", 150, 5){
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

	//Functions
	//move instruction
	void apply_go_instruction(const vector<string>&);
	
	//look instruction
	void apply_look_instruction(vector<string>&);
	
	//open door instruction
	bool apply_open_door_instruction();
	
	//close door instruction
	bool apply_close_door_instruction();
	
	//pick instruction
	bool apply_pick_instruction();
	
	//drop instruction
	bool apply_drop_instruction();
	
	//equip instruction
	bool apply_equip_instruction();
	
	//unequip instruction
	bool apply_unequip_instruction();

	//put instruction
	bool apply_put_instruction();
	
	//get instruction
	bool apply_get_instruction();
};
#endif